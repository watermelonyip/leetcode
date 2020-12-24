/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
2 <= n <= 58
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

思路：用动态规划的方法。注意的是绳子长度为0，1，2，3这几个特殊情况，然后其他情况：比如求解长度为n的，从i的位置剪一刀，即求出f(i)*f(n-i)，即问题可以分解为求解长度为i和长度为n-i的两个子问题。
所以可以通过循环求解出长度为i(i=4,5,...,n)的值，并且用数组存储将当前长度i的最大乘积存储起来。求解子问题过程中很多重复值，所以用数组存储起来。时间复杂度O(n^2)，空间复杂度O(n)。
*/
class Solution {
public:
    int cuttingRope(int n) {
        int* product = new int[n + 1];
        if(n <= 1)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        product[0] = 0;
        product[1] = 1;
        product[2] = 2;
        product[3] = 3;
        int max = 0;
        for(int i = 4; i <= n; i++){
            max = 0;
            for(int j = 1; j <= i / 2; j++){
                int temp = product[j] * product[i - j];
                if(temp > max)
                    max = temp;
            }
            product[i] = max;
            //cout << max << endl;
        }
        max = product[n];
        delete[] product;
        return max;
    }
};
