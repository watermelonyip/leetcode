/*
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
提示：a, b 均可能是负数或 0, 结果不会溢出 32 位整数.
思路：两个数异或的结果是相加后该位的结果，与的结果是相加后该位进位的结果。因此先将两个数异或后再做与运算，然后将与运算结果左移后和异或后的结果继续这两个步骤，直到两个数异或结果为0，即没有进位。
时间复杂度O(1)，空间复杂度O(1)。解释：最差情况下（例如 a= 0x7fffffff , b=1 时），需循环 32 次，使用 O(1) 时间；每轮中的常数次位操作使用 O(1) 时间。
leetcode上c++编译可能不支持负数左移，所以有些情况要用unsigned int类型。
*/
class Solution {
public:
    int add(int a, int b) {
        while(b != 0){
            //unsigned int xor_result = (a ^ b);
            //unsigned int and_result = (unsigned int)(a & b) << 1;
            int and_result = (unsigned int)(a & b) << 1;
            //a = xor_result;
            a = (a ^ b);
            b = and_result;
        }
        return a;
    }
};
