/*
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。限制：1 <= n <= 10000。
思路：方法一：递归，由于不能用if来判断，所以利用关系判断来当递归的终止条件，时间复杂度O(n)，空间复杂度O(n)。
方法二：定义一个n行n+1列的bool类型数组，然后sizeof来计算数组所占大小，再除2。相当于计算n(n+1)/2求和公式。时间复杂度O(1)，空间复杂度O(n)。
还有其他的方法在书本里。
*/
class Solution {
public:
    int sumNums(int n) {
        /*
        bool x = (n > 1) && ((n += sumNums(n - 1)) > 1);
        return n;
        */
        bool arr[n][n + 1];
        return sizeof(arr) >> 1;
    }
};
