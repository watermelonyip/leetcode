/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。 2 <= n <= 1000
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

思路：这里用到的数学的方法，当n>=5时，可以证明2(n-2)>n并且3(n-3)>n，所以绳子长度大于等于5时，应该将绳子剪成长度为3或者2的绳子段。
并且，当n>=5时，3(n-3) >= 2(n-2)，所以先尽可能的将绳子长度剪为长度为3的。当剩下的长度为1时，可以将1和其中一段3结合为长度4，长度4有两种剪法：2*2和1*3，前者比较好。

和上一题不同的是n范围变大了，且需要取余。方法：循环求余(循环方法求解)或快速幂求余(分成奇偶情况求解)，前者时间复杂度O(N)，后者时间复杂度 O(log2N)比较快。
https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/mian-shi-ti-14-ii-jian-sheng-zi-iitan-xin-er-fen-f/

时间复杂度O(log2n)，空间复杂度O(1)
*/
class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 1)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int numOfThree = n / 3;
        if(n % 3 == 1)
            numOfThree -= 1;
        int numOfTwo = (n - 3 * numOfThree) / 2;

        int result = 1;
        int x = 3;
        while(numOfThree){
            if(numOfThree % 2 == 1)
                result = (int)((long long)(result) * (long long)(x) % 1000000007);
            x = (int)(((long long)(x) * (long long)(x)) % 1000000007);
            numOfThree /= 2;
        }
        x = 2;
        while(numOfTwo){
            if(numOfTwo % 2 == 1)
                result = (int)((long long)(result) * (long long)(x) % 1000000007);
            x = (int)(((long long)(x) * (long long)(x)) % 1000000007);
            numOfTwo /= 2;
        }
        
        return result;
    }
};
