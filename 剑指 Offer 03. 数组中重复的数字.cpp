/*
找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
限制：2 <= n <= 100000

方法一：用数组构建哈希表，时间复杂度和空间复杂度都是O(n)
方法二：直接修改数组，交换值；或者将访问过的下标标识为负数（对于0的情况可整体加1）
方法三：（书上的方法）类似于二分查找，先分别统计0～n/2和n/2+1~n-1的个数，超过区间个数表示里面有重复数字，继续往下查找。但是这种方法可能不能找到全部重复数字

*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            while(i != nums[i]){
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                else{
                    int temp = nums[i];
                    nums[i] = nums[nums[i]];
                    nums[temp] = temp;
                } 
            }
        }
        return -1;
    }
};
