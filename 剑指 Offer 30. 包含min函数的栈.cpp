/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
提示：各函数的调用总次数不超过 20000 次
思路：定义一个辅助栈，用于存储最小值的序列。当前push的值小于栈内最小值时，讲当前值push进去，否则将栈内最小值（即栈顶元素）重新push进去。
其实可以进一步优化，只不断push进最小值，然后pop的时候判断和辅助栈最小值是否相等，相等的话也pop出最小值。（从跑出来的结果看感觉差不多）
时间复杂度O(1)，空间复杂度O(n)，n为待入栈元素个数。
*/
class MinStack {
    stack<int> data;
    stack<int> min_data;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);
        /* //方法一
        if(min_data.empty() || x < min_data.top())
            min_data.push(x);
        else
            min_data.push(min_data.top());
        */
        if(min_data.empty() || x <= min_data.top()) //方法二
            min_data.push(x);
    }
    
    void pop() {
        int x = data.top(); //方法二
        data.pop();
        if(x == min_data.top()) //方法二
            min_data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return min_data.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
