/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1.
思路：用上一题的方法，用一个队列表示当前的数据，另一个队列保存最大值的情况。如果当前push_back的值大于最大值队列里的值，那么最大值队列里比其小的数字就要pop_back，然后这个数字再push_back；
否则将当前值直接push_back。pop_front时要注意如果如果队列前端的元素等于当前最大值，最大值队列也需要pop_front。
平均时间复杂度O(1)，空间复杂度O(n)，其中n为元素个数。
关于时间复杂度的官方解释：删除操作于求最大值操作显然只需要 O(1) 的时间。而插入操作虽然看起来有循环，做一个插入操作时最多可能会有 n 次出队操作。但要注意，由于每个数字只会出队一次，
因此对于所有的 n 个数字的插入过程，对应的所有出队操作也不会大于 n 次。因此将出队的时间均摊到每个插入操作上，时间复杂度为 O(1)。
*/
class MaxQueue {
    deque<int> maxValue;
    deque<int> data;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(data.empty() || maxValue.empty())
            return -1;
        return maxValue.front();
    }
    
    void push_back(int value) {
        while(!maxValue.empty() && value > maxValue.back())
            maxValue.pop_back();
        maxValue.push_back(value);
        data.push_back(value);
    }
    
    int pop_front() {
        if(data.empty() || maxValue.empty())
            return -1;
        int result = data.front();
        if(data.front() == maxValue.front())
            maxValue.pop_front();
        data.pop_front();
        return result;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
