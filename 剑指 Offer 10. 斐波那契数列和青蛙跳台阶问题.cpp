/*
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

思路：如果直接用递归的方法，会产生很多重复的调用，可以使用数组来记录调用过后产生的结果值，但在计算中发现只需要记录最新的两个f(n - 1)和f(n - 2)即可。所以使用【滚动数组】循环的方法，时间复杂度O(n)，空间复杂度O(1)。
*/
class Solution {
public:
    int fib(int n) {
        if(n <= 1)
            return n;
        int num1 = 1, num2 = 0; //记录f(n - 1)和f(n - 2)
        int result = 0;
        for(int i = 2; i <= n; i++){
            result = (num1 + num2) % 1000000007;
            num2 = num1;
            num1 = result;
        }
        return result;
    }
};

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
思路：本质上斐波那契数列，只是在f(0)的值为1，方法不变。通俗来解释就是，比如要跳n级，如果第一步跳1级，那么剩下的级数方法为f(n - 1)；如果第一步跳2级，那么剩下的级数方法为f(n - 2)；所以总的方法为f(n - 1) + f(n - 2)
*/
class Solution {
public:
    int numWays(int n) {
        if(n <= 1)
            return 1;
        int num1 = 1, num2 = 1;
        int result = 0;
        for(int i = 2; i <= n; i++){
            result = (num1 + num2) % 1000000007;
            num2 = num1;
            num1 = result;
        }
        return result;
    }
};
