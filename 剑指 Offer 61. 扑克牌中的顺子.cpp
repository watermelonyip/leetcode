/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
限制：数组长度为 5 , 数组的数取值为 [0, 13] .
思路：先将数组排序，然后统计0的个数，以及统计数之间的距离总和。最后如果距离总和大于0的个数，即距离不能用0来填充，则返回false；否则返回true。
时间复杂度O(nlogn)，空间复杂度O(1)，其中n为数组大小。也可以使用长度为14的数组（哈希表）来存储每个数字是否被存储，此时时间复杂度为O(n)。
由于n大小固定为5，所以O(nlogn)和O(n)的差距不大，可以使用排序的方法。
*/
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if(nums.size() != 5)
            return false;
        sort(nums.begin(), nums.end());
        int zero = 0;
        int number = 0;
        for(; zero < nums.size() && nums[zero] == 0; zero++);
        for(int i = zero + 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1])
                return false;
            number += nums[i] - nums[i - 1] - 1;
            if(zero < number)
                return false;
        }
        return true;
    }
};
