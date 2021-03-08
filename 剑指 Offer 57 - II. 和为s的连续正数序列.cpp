/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
限制：1 <= target <= 10^5.
思路：双指针，p1和p2之间的区间之和等于target时，将区间内结果保留下来，然后p2指针继续往后走。当p1和p2区间之和小于target时，p2指针需要往后走，使得区间之和变大；
大于target时，p1指针往后走，使得区间之和结果变小。时间复杂度O(n)，空间复杂度O(1)，其中n为target值。
很奇怪的是，各种题解都是用普通的if else，但是我这样写的话就超时，只能按书本的这种来写才能通过。
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        int p1 = 1, p2 = 2;
        int middle = (target + 1) / 2;
        int sum = p1 + p2;
        while(p1 < middle){
            if(sum == target){
                result.push_back(pushElement(p1, p2));
            }
            while(sum > target && p1 < middle){
                sum -= p1;
                p1++;
                if(sum == target)
                    result.push_back(pushElement(p1, p2));
            } 
            p2++;
            sum += p2;
        }
        return result;
    }

    vector<int> pushElement(int p1, int p2){
        vector<int> temp;
        for(int i = p1; i <= p2; i++)
            temp.push_back(i);
        return temp;
    }
};
