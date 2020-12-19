/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

自己的想法：s1是辅助，s2以队列顺序存储。每次插入元素时，将s2元素弹出并插入到s1，然后将新元素插入到s2，再将s1元素弹出插入到s2。删除元素时，直接弹出s2第一个元素。
题解：插入元素时，直接将元素插入到s1。删除元素时，如果s2为空，将s1元素弹出插入到s2，并弹出s2第一个元素；如果s2不为空，直接弹出s2第一个元素。时间复杂度：对于插入和删除操作，时间复杂度均为 
O(1)。插入不多说，对于删除操作，虽然看起来是 O(n)的时间复杂度，但是仔细考虑下每个元素只会「至多被插入和弹出 stack2 一次」，因此均摊下来每个元素被删除的时间复杂度仍为 O(1)，空间复杂度O(n)。

自己的想法比题解稍微慢些。
*/
//自己的方法
class CQueue {
        stack<int> s1;
        stack<int> s2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        if(s2.empty())
            s2.push(value);
        else{
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(value);
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    
    int deleteHead() {
        if(s2.empty())
            return -1;
        int value = s2.top();
        s2.pop();
        return value;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */


//题解方法
class CQueue {
        stack<int> s1;
        stack<int> s2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty() && s1.empty())
            return -1;
        int value;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            
        }
        value = s2.top();
        s2.pop();
        return value;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
