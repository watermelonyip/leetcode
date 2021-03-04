/*
统计一个数字在排序数组中出现的次数。限制：0 <= 数组长度 <= 50000。
思路：二分查找，但是有一点改动。因为是排序数组，因此需要找到target值连续出现的区间。
当前mid值等于target值并且左边依然等于target值时，继续往左区间查找得到target值第一次出现的下标。
当前mid值等于target值并且右边依然等于target值时，继续往右区间查找得到target值最后一次出现的下标。
时间复杂度O(logn)，空间复杂度O(1)，其中n为数组长度。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() <= 0)
            return 0;
        int low = 0, high = nums.size() - 1;
        int mid = (low + high) / 2;
        
        int firstindex = -1, lastindex = -1;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target){
                if(mid == 0 || nums[mid - 1] != target){
                    firstindex = mid;
                    break;
                }
                else
                    high = mid - 1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        low = 0, high = nums.size() - 1;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target){
                if(mid == nums.size() - 1 || nums[mid + 1] != target){
                    lastindex = mid;
                    break;
                }
                else
                    low = mid + 1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        //cout << firstindex << " " << lastindex << endl;
        if(firstindex != -1 && lastindex != -1)
            return lastindex - firstindex + 1;
        return 0;
    }
};
