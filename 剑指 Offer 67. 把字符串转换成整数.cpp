/*
写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
在任何情况下，若函数不能进行有效的转换时，请返回 0。
说明：假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^31 − 1]。如果数值超过这个范围，请返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。
思路：先判断是否为空字符串，然后遍历到第一个非空格字符位置。从这个位置开始，判断是否为+或-符号，符号过后判断是否为数字，若不是数字可以直接返回，若是则继续往下计算连续的数字组合的结果，
直到遇到非数字字符。在计算的过程中需要判断是否越界，因此用long long来存储计算的结果，遇到越界的结果可以根据+或-符号来判断返回INT_MAX或INT_MIN，这样就不用在计算过程中也计算正负了。
时间复杂度O(n)，空间复杂度O(1)，其中n为字符串长度。
*/
class Solution {
    bool isValid = false;
public:
    int strToInt(string str) {
        if(str == "")
            return 0;
        int position = 0;
        for(; position < str.length() && str[position] == ' '; position++);
        if(position == str.length())
            return 0;
        
        bool minus = false;
        if(str[position] == '+')
            position++;
        else if(str[position] == '-'){
            minus = true;
            position++;
        }

        long long number = 0;
        for(; position < str.length(); position++){
            if(str[position] >= '0' && str[position] <= '9'){
                if(!isValid)
                    isValid = true;
                if(minus)
                    number = number * 10 + -1 * (str[position] - '0');
                else
                    number = number * 10 + (str[position] - '0');
                if(!minus && number >= INT_MAX)
                    return INT_MAX;
                if(minus && number <= INT_MIN)
                    return INT_MIN;
            }
            else{
                return (int)number;
            }
        }
        return (int)number;
    }
};
