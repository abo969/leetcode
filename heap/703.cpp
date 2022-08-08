/**
 * 703. 数据流中的第 K 大元素
 * 设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
 * 请实现 KthLargest 类：
 * KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
 * int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
 * https://leetcode.cn/problems/kth-largest-element-in-a-stream/
 * 
 */
class KthLargest {
    int size;   // 小顶堆元素个数

    // 小顶堆
    priority_queue<int, vector<int>, greater<int>> q;

public:
    KthLargest(int k, vector<int>& nums) {
        size = k;

        int n = nums.size();
        // 建堆，始终维持堆元素个数为k
        for (int i = 0; i < k && i < n; i++)
            q.push(nums[i]);

        if (k < n) {    // 处理剩余的元素，仍然维持堆元素个数为k
            for (int i = k; i < n; i++) {
                if (nums[i] > q.top()) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if (q.size() < size)        // 堆元素个数不到size个
            q.push(val);            // 直接入堆
        else if (val > q.top()) {   // 堆元素个数超过size
            q.pop();                // 若堆顶元素更小，新数据入堆
            q.push(val);
        }

        return q.top();             // 返回堆顶，即第k大元素
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */