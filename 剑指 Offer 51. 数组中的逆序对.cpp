/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。限制：0 <= 数组长度 <= 50000.
思路：归并排序的思路，不断将数组对半分，当子数组长度为1时，比较两个子数组，如果前面的子数组数值上大于后面的子数组，那么符合逆序对规则，然后将这两个数进行排序，然后合并数组得到长度为2的子数组。
在合并长度为2的两个子数组时（子数组在上面步骤已经排好序），分别从两个长度为2的子数组的末尾开始，如果左子数组当前数字大于右子数组当前数字，那么表明当前左子数组的数字大于右子数组当前数字，
以及右子数组当前数字的左边数字，因此逆序对个数要加上右子数组当前数字及其左边数字的总个数。合并后子数组长度为4。合并其他规模的子数组也类似。时间复杂度O(nlogn)，空间复杂度O(n)，其中n为数组长度。
需要注意的是，在归并排序当中，需要一个辅助的数组来记录原数组，然后在原数组上直接修改得到排好序的数组。如果一开始直接将原数组复制到辅助数组再进行后续操作的话，会存在超时的情况。
所以可以将原数组看作辅助数组，然后建立一个新的数组保存排好序的结果，最后在递归调用的时候将两个数组调换过来，这样能解决超时的问题。
*/
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        vector<int> nums2(nums);
        return merge(nums, nums2, 0, nums.size() - 1);
        //delete[] nums2;
    }

    int merge(vector<int>& nums1, vector<int>& nums2, int start, int end){
        if(start == end){
            nums2[end] = nums1[start];
            return 0;
        }
        int length = (end - start) / 2;

        int left = merge(nums2, nums1, start, start + length);
        int right = merge(nums2, nums1, start + length + 1, end);

        int i = start + length, j = end;
        int index = end;
        int count = 0;
        //for(int k = 0; k < nums1.size(); k++)
            //nums2[k] = nums1[k];
        for(; i >= start && j >= start + length + 1;){
            if(nums1[i] > nums1[j]){
                count += j - (start + length);
                //cout << count << "  " << nums1[i] << "  " << nums1[j]<<endl;
                nums2[index--] = nums1[i--];
            }
            else
                nums2[index--] = nums1[j--];
        }
        for(; i >= start; i--)
            nums2[index--] = nums1[i];
        for(; j >= start + length + 1; j--)
            nums2[index--] = nums1[j];

        return count + left + right;
    }
};
