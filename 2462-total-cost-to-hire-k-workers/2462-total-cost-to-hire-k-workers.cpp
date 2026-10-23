
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0;
        int right = n - 1;

        priority_queue<int, vector<int>, greater<int>> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;

        long long total = 0;

        for (int i = 0; i < k; i++) {
            while (leftHeap.size() < candidates && left <= right) {
                leftHeap.push(costs[left++]);
            }

            while (rightHeap.size() < candidates && left <= right) {
                rightHeap.push(costs[right--]);
            }

            if (leftHeap.empty()) {
                total += rightHeap.top();
                rightHeap.pop();
            }
            else if (rightHeap.empty()) {
                total += leftHeap.top();
                leftHeap.pop();
            }
            else if (leftHeap.top() <= rightHeap.top()) {
                total += leftHeap.top();
                leftHeap.pop();
            }
            else {
                total += rightHeap.top();
                rightHeap.pop();
            }
        }

        return total;
    }
};
