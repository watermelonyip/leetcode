/*
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
限制：1 <= n <= 11.
思路：最简单的方法，暴力法，会超时。其他方法：比如有n个骰子，点数的总和范围是[n,6n]。
假设在某一轮骰子的点数总和为s，那么在多加入一个骰子的下一轮里点数总和有6种情况：新加入的骰子点数为1，上一轮骰子点数总和为s - 1; ... ;新加入的骰子点数为6，上一轮骰子点数总和为s-6.
所以设立两个数组分别来记录上一轮骰子点数总和情况和当前骰子点数总和情况，用循环来完成。
时间复杂度O(n^2)，空间复杂度O(n)，其中n为骰子个数。
具体看题解：https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/jian-zhi-offer-60-n-ge-tou-zi-de-dian-sh-z36d/
*/
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> result(6, 1.0 / 6);
        if(n <= 0)
            return result;
        for(int i = 2; i <= n; i++){
            vector<double> temp(5 * i + 1, 0.0);
            for(int j = 0; j < result.size(); j++){
                for(int k = 0; k < 6; k++){
                    temp[j + k] += result[j] * (1.0 / 6);
                }
            }
            result = temp;
        }
        return result;
    }
};
