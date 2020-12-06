class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            //cout << nums[i] << "  " << abs(nums[i]) - 1 << "  "<< nums[abs(nums[i]) - 1] << endl;
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                result.push_back(i + 1);
        }
        return result;
    }
};
/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
在不使用额外空间且时间复杂度为O(n)的情况下找到所有在 [1, n] 范围之间没有出现在数组中的数字。可以假定返回的数组不算在额外空间内。

题解：在原数组上进行修改，比如数组的第i个元素，就修改nums[nums[i] - 1]为负数，最后遍历数组找到不为负数下标值。

*/
