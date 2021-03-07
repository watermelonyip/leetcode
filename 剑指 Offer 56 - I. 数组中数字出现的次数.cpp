/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
限制：2 <= nums.length <= 10000.
思路：因为除了两个数字之外，其他数字都出现了两次，所以可以用异或的思想，两个相同的数字异或等于0。因此将数组里所有数字异或，最后得到两个只出现一次的数字的异或的结果。
根据这个结果将数组分为两部分，使得每部分仅出现一个只出现一次的数字，这样在每部分使用异或的方法就能找出该数字。
将数组分为两部分的方法是：根据数组所有数字异或后的结果，最右第一次出现1的位来划分，数组里的每个数字和该位为1的数异或等于1的在第一部分，等于0的在第二部分。
时间复杂度O(n)，空间复杂度O(1)。
需要注意一些细节：比如这句(xor_result & 1) == 0，==的优先级比&高，记得加括号。
*/
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> result;
        if(nums.size() <= 0)
            return result;
        
        int xor_result = 0;
        for(int i = 0; i < nums.size(); i++)
            xor_result = xor_result ^ nums[i];

        int first_index = 0;
        while((xor_result & 1) == 0){
            first_index++;
            xor_result = xor_result >> 1;
        }
        
        int first_arr = 0, second_arr = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i] >> first_index;
            if((temp & 1) == 1)
                first_arr  = first_arr ^ nums[i];
            else
                second_arr = second_arr ^ nums[i];
        }
        result.push_back(first_arr);
        result.push_back(second_arr);
        return result;
    }
};
