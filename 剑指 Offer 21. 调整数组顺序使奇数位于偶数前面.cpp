/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
1 <= nums.length <= 50000
1 <= nums[i] <= 10000

思路：方法一：双指针，p1指针从前往后，p2指针从后往前。p1在偶数位停留，p2在奇数位停留，交换。直到p1>=p2。
方法二：看了题解才知道，可以用快慢指针，low指针走一步，fast指针走两步，若low指向偶数，fast指向奇数，则交换。直到遍历完整个数组。
*/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size() <= 0)
            return nums;
        int p1 = 0, p2 = nums.size() - 1;
        while(p1 < p2){
            while(p1 < p2 && (nums[p1] & 0x1) == 1)
                p1++;
            while(p1 < p2 && (nums[p2] & 0x1) == 0)
                p2--;
            if(p1 < p2){
                int temp = nums[p1];
                nums[p1] = nums[p2];
                nums[p2] = temp;
            }
        }
        return nums;
    }
};
