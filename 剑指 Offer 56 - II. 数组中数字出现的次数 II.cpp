/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
限制：1 <= nums.length <= 10000, 1 <= nums[i] < 2^31.
思路：数组里每个数组的对应位相加起来，最后得到的结果如果该位能整除3，表示只出现一次的数字该位位0；如果不能整除3，表示只出现一次的数字该位为1。
时间复杂度O(n)，空间复杂度O(1)，其中n为数组大小。
还可以用位运算的方法，参考：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/mian-shi-ti-56-ii-shu-zu-zhong-shu-zi-chu-xian-d-4/

要注意一些自己容易错的细节，bit的类型是unsigned int，不然会溢出；(nums[i] & bit) != 0 这里的判断条件不要写成==1。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        int* arr = new int[32];
        for(int i = 0; i < 32; i++)
            arr[i] = 0;
        
        for(int i = 0; i < nums.size(); i++){
            unsigned int bit = 1;
            for(int j = 31; j >= 0; j--){
                if((nums[i] & bit) != 0)
                    arr[j]++;
                bit = bit << 1;
                //cout << arr[j] << "  ";
            }
        }
        int result = 0;
        for(int i = 0; i < 32; i++){
            result = result << 1;
            result += arr[i] % 3;
        }
        return result;
    }
};
