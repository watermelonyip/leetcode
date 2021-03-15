/*
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
提示：所有元素乘积之和不会溢出 32 位整数, a.length <= 100000.
思路：分为上三角和下三角来计算。即每一行以第i列的数为分界线，左边为A[0] * ... * A[i - 1]，右边为A[i + 1] * ... * A[n - 1]。
第i行的左边等于上一行的结果再乘上A[i - 1]，右边等于下一行的结果乘上A[i + 1]，因此左边从上往下计算，右边从下往上计算。
两次遍历得到最终结果，也可以增加变量来记录使用一次遍历得到最终结果。时间复杂度O(n)，空间复杂度O(1)，其中n为数组长度。
*/
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size() <= 0)
            return a;
        vector<int> result(a.size(), 1);
        for(int i = 1; i < a.size(); i++)
            result[i] = result[i - 1] * a[i - 1];
        int temp = 1;
        for(int i = a.size() - 2; i >= 0; i--){
            temp *= a[i + 1];
            result[i] *= temp;
        }
        return result; 
    }
};
