/**
 * 346. 数据流中的移动平均值
 * 给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。
 * 实现 MovingAverage 类：
 * MovingAverage(int size) 用窗口大小 size 初始化对象。
 * double next(int val) 计算并返回数据流中最后 size 个值的移动平均值。
 * https://leetcode.cn/problems/moving-average-from-data-stream/
 */

class MovingAverage {
    int size;
    int sum;
    queue<int> q;

public:
    MovingAverage(int sz) {
        size = sz;
        sum = 0;
    }
    
    double next(int val) {
        if (q.size() == size) {     // 如果队列已满，删除队头数据     
            sum -= q.front();
            q.pop();
        }

        q.emplace(val);
        sum += val;
        return 1.0 * sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */