/*
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1]

思路：先处理特殊情况，base为0，exponent为0或1。若exponent为负数，需要求绝对值。循环求余的方法，若exponent为偶数，则计算base^exponent = base^(expoent/2) * base^(exponet/2)；
若exponent为奇数，则计算base^exponent = base^(expoent/2) * base^(exponet/2) * base。也可以用递归的方法，两种方法都不是很熟悉，需要多练。

易错点：特殊情况处理，当exponent为负数求绝对值时，需要考虑边界值，exponent求余后需要用unsigned int之类的类型来表示。&操作和>>操作，位运算比乘除法和求余运算效率要高。
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        unsigned int exponent = (unsigned int)(abs(n));
        //cout << "exponent: " << exponent << endl;
        double result = 1;
        while(exponent){
            if(exponent & 0x1 == 1)
                result *= x;
            x *= x;
            exponent = exponent >> 1;
            //cout << exponent << "  " << result << endl;
        }
        if(n < 0)
            result = 1.0 / result;
        return result;
    }
};
