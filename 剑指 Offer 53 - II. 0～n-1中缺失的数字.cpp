/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
限制：1 <= 数组长度 <= 10000.
思路：二分查找，即寻找下标和当前数值不相等的数。如果当前mid值等于下标时，表示要寻找的数在右区间，修改low指针；
如果当前mid值不等于下标时，如果下标mid-1等于mid-1则表明mid就是要寻找的数；如果下标mid-1不等于mid-1则表明要寻找的数在左区间。
时间复杂度O(logn)，空间复杂度O(1)，其中n为数组长度。最后的返回值要注意一下，寻找不到不要直接返回-1。
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() <= 0)
            return -1;
        int low = 0, high = nums.size() - 1;
        int mid = -1;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == mid)
                low = mid + 1;
            else if(mid == 0 || nums[mid - 1] == mid - 1)
                return mid;
            else
                high = mid - 1;
        }
        return nums.size();
    }
};
