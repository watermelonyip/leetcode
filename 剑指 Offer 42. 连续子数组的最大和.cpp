/*
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。
提示：1 <= arr.length <= 10^5, -100 <= arr[i] <= 100.
思路：用cursum记录当前累加值，maxsum记录最大累加值。当cursum + nums[i] > nums[i]时，即cursum > 0，cursum加上nums[i]；否则cursum = nums[i]。
由于每次cursum不一定是最大累加值，所以要用maxsum来记录最大累加值。时间复杂度O(n)，空间复杂度O(1)，其中n为数组大小。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        if(nums.size() == 1)
            nums[0];
        int cursum = nums[0];
        int maxsum = cursum;

        for(int i = 1; i < nums.size(); i++){
            if(cursum <= 0)
                cursum = nums[i];
            else
                cursum += nums[i];
            if(cursum > maxsum)
                maxsum = cursum;
        }
        return maxsum;
    }
};
