/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。你可以假设数组是非空的，并且给定的数组总是存在多数元素。
限制：1 <= 数组长度 <= 50000

思路：
1. 投票法：用变量分别记录当前结果和次数。当前数字和保存的结果相同时，次数加一；不相同时次数减一；次数为0时记录当前数字。时间复杂度O(n)，空间复杂度O(1)，其中n为数组长度。
2. 哈希表：哈希表记录每个数字和对应的次数，时间复杂度O(n)，空间复杂度O(n)。之前能想到的都是用这种方法。
还有其他排序法分治法随机法之类的，但是感觉没有这两个那么好理解。
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        int result = nums[0];
        int times = 0;
        for(int i = 0; i < nums.size(); i++){
            if(times == 0){
                result = nums[i];
                times++;
            }
            else if(nums[i] == result)
                times++;
            else
                times--;
        }
        return result;
    }
};
