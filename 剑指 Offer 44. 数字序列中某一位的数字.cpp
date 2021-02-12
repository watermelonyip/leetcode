/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。请写一个函数，求任意第n位对应的数字。
限制：0 <= n < 2^31.
思路：找规律，第0～9位直接返回n；其余按照规律：两位数的10～99共90个数字，90*2=180位，判断n是否小于180，如果是的话继续往里找，否则找三位数、四位数，直到在某个区间内。
找到区间后，首先找到该区间的第一个数字，如果两位数起始数字是10，三位数起始数字是100；然后找到具体数字；接着进行处理求余得到某一位。
需要注意的是，判断是否在区间内的时候乘法可能溢出，用long long比较有保障。
时间复杂度O(logn)，空间复杂度O(logn)。
*/
class Solution {
public:
    int findNthDigit(int n) {
        if(n < 0)
            return -1;
        if(n < 10)
            return n;
        int digit = 1;  //  数字位数
        while(true){
            int number = countNum(digit);   //当前位数的数量
            if(n < (long long)digit * number)
                return findNthDigit(n, digit);
            n -= digit * number;
            digit++;
        }
        return -1;
    }

    int findNthDigit(int n, int digit){
        int beginNum = pow(10, digit - 1);  //当前位数的初始数字
        int result = beginNum + n / digit;
        int remain = digit - n % digit - 1;
        for(int i = 0; i < remain; i++){
            result /= 10;
        }
        return result % 10;
    }

    int countNum(int digit){
        if(digit == 1)
            return 10;
        return 9 * pow(10, digit - 1);
    }

};
