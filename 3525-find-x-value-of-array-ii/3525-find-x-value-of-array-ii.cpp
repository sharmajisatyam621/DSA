class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {0, 0, 0, 0, 0};
    };

    int k;

    Node mergeNode(const Node& A, const Node& B) {
        Node C;

        C.prod = (A.prod * B.prod) % k;

        // Prefixes completely inside A
        for (int r = 0; r < k; r++) {
            C.cnt[r] = A.cnt[r];
        }

        // Prefixes that start in A and continue into B
        for (int r = 0; r < k; r++) {
            int newRem = (A.prod * r) % k;
            C.cnt[newRem] += B.cnt[r];
        }

        return C;
    }

    vector<Node> tree;
    int size;

    void update(int pos, int val) {
        pos += size;

        tree[pos] = Node();

        val %= k;
        tree[pos].prod = val;
        tree[pos].cnt[val] = 1;

        pos /= 2;

        while (pos >= 1) {
            tree[pos] = mergeNode(tree[pos * 2],
                                   tree[pos * 2 + 1]);
            pos /= 2;
        }
    }

    Node query(int l, int r) {
        // [l, r)
        Node leftResult;
        Node rightResult;

        l += size;
        r += size;

        while (l < r) {
            if (l & 1) {
                leftResult = mergeNode(leftResult, tree[l]);
                l++;
            }

            if (r & 1) {
                --r;
                rightResult = mergeNode(tree[r], rightResult);
            }

            l /= 2;
            r /= 2;
        }

        return mergeNode(leftResult, rightResult);
    }

    vector<int> resultArray(vector<int>& nums,
                            int K,
                            vector<vector<int>>& queries) {
        k = K;

        int n = nums.size();

        size = 1;
        while (size < n)
            size *= 2;

        tree.resize(2 * size);

        // Build leaves
        for (int i = 0; i < n; i++) {
            int rem = nums[i] % k;

            tree[size + i].prod = rem;
            tree[size + i].cnt[rem] = 1;
        }

        // Build tree
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = mergeNode(tree[i * 2],
                                 tree[i * 2 + 1]);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(index, value);

            // Query [start, n)
            Node res = query(start, n);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};