class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (auto &el: nums) {
            min_heap.push(el);
        }
        while (min_heap.size() > k) min_heap.pop();
    }

    int add(int val) {
        min_heap.push(val);

        while (min_heap.size() > k) min_heap.pop();

        return min_heap.top();
    }
};