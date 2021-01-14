/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
思路：正则表达式，遍历判断。一个数值分为三部分，整数部分，小数点，小数部分，e或者E，指数部分。整数部分、小数部分、指数部分都是0～9的数，其中整数部分和指数部分可以有+或者-符号。
特殊情况：当小数部分有内容时，整数部分可以没有内容；当有小数点时，小数部分也可以没内容。另外注意字符串前后的空格。

*/
class Solution {
    int index = 0;
public:
    bool isNumber(string s) {
        if(s.length() <= 0)
            return false;
        while(index < s.length() && s[index] == ' ') index++;
        bool isnumber = isSigned(s);
        if(s[index] == '.'){
            index++;
            isnumber = isInterger(s) || isnumber;
        }
        if(s[index] == 'e' || s[index] == 'E'){
            index++;
            isnumber = isnumber && isSigned(s);
        }
        if(!isnumber)
            return false;
        while(index < s.length() && s[index] == ' ') index++;
        return isnumber && s[index] == '\0';
        
    }

    bool isInterger(string s){
        int position = index;
        while(s[index] >= '0' && s[index] <= '9')
            index++;
        return index > position;
    }

    bool isSigned(string s){
        if(s[index] == '+' || s[index] == '-'){
            index++;
        }
        return isInterger(s);
    }
};
