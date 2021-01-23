/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

思路：使用辅助栈，用于存储根据弹出序列的压栈元素。即，当前栈为空或者栈顶元素不等于弹出序列里的某个下标数时，将该元素压栈；相等时弹出。结束条件是弹出序列是否遍历完，栈是否为空。
时间复杂度O(n)，空间复杂度O(n)，其中n为压栈序列元素个数。
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty()){
            if(popped.empty())
                return true;
            else
                return false;
        }
        else if(popped.empty())
            return true;
        int index1 = 0, index2 = 0;
        stack<int> s;
        while(index2 < popped.size()){
            while(s.empty() || s.top() != popped[index2]){
                if(index1 < pushed.size())
                    s.push(pushed[index1++]);
                else
                    break;
            }
            if(s.top() != popped[index2])
                break;
            s.pop();
            index2++;
        }
        if(index2 == popped.size() && s.empty())
            return true;
        return false;
    }
};

