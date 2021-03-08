/*
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
限制：1 <= nums.length <= 10^5, 1 <= nums[i] <= 10^6.
思路：双指针方法，设立头指针和尾指针，如果二者之和等于target值则找到并返回，若大于则向前移动尾指针，若小于则向后移动头指针。时间复杂度O(n)，空间复杂度O(1)，其中n为数组长度。
从题解里看来的注意事项，为了避免溢出判断条件可以用target - nums[p1] 跟 nums[p2]代替。平时二分查找的题判断条件(left + right) / 2可以用left + ((rigth - left) >> 1))来代替。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size() <= 0)
            return result;
        int p1 = 0, p2 = nums.size() - 1;
        while(p1 < p2){
            int sum = nums[p1] + nums[p2];
            if(sum == target){
                result.push_back(nums[p1]);
                result.push_back(nums[p2]);
                break;
            }
            else if(sum > target)
                p2--;
            else
                p1++;
        }
        return result;
    }
};
