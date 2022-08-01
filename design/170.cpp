/**
 * 170. 两数之和 III - 数据结构设计
 * 设计一个接收整数流的数据结构，该数据结构支持检查是否存在两数之和等于特定值。
 * 实现 TwoSum 类：
 * TwoSum() 使用空数组初始化 TwoSum 对象
 * void add(int number) 向数据结构添加一个数 number
 * boolean find(int value) 寻找数据结构中是否存在一对整数，使得两数之和与给定的值相等。
 * 如果存在，返回 true ；否则，返回 false 。
 * https://leetcode.cn/problems/two-sum-iii-data-structure-design/
 */

class TwoSum {
public:
    TwoSum() {
    }
    
    void add(int number) {
        if (hash.count(number) == 0)
            hash[number] = 1;
        else 
            hash[number]++;
    }
    
    bool find(int value) {
        for (auto it : hash) {
            long x = it.first;
            long y = value - x;
            if (y != x) {   // 如果y不等于x，则直接看hash里有没有y
                if (hash.count(y)) return true;
            } else {        // 否则看y（即x）出现次数，大于1次，表明存在
                if (hash[y] > 1) return true;
            }
        }

        return false;       // 其他情况均不存在这样的数对
    }

private:
    unordered_map<long, int> hash;   // 数据->出现次数 mapping
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */