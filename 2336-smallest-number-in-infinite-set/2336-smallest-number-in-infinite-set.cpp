
class SmallestInfiniteSet {
private:
    int curr = 1;
    set<int> added;

public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        if (added.empty()) {
            return curr++;
        }

        int smallest = *added.begin();
        added.erase(added.begin());

        return smallest;
    }

    void addBack(int num) {
        if (num < curr) {
            added.insert(num);
        }
    }
};
