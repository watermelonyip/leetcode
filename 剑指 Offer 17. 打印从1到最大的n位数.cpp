/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
用返回一个整数列表来代替打印，n 为正整数。

思路：因为n范围没给出，所以要考虑大数的情况。方法一：大数一直累加，判断加1之后是否到达最大的n位数，比较复杂；方法二：数字排列的方法，使用递归，时间复杂度O(10^n)，空间复杂度O(10^n)。

下面的做法是针对返回值是vector<int>的，如果返回字符串则修改void print(vector<int> &result, char* number)即可。
*/
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        if(n <= 0)
            return result;
        char* number = new char[n + 1];
        number[n] = '\0';
        for(int i = 0; i < 10; i++){
            number[0] = i + '0';
            printNumber(result, number, n, 0); 
        }
        delete[] number;
        return result;
    }

    void printNumber(vector<int> &result, char* number, int length, int index){
        if(index == length - 1){
            print(result, number);
            return;
        }
        for(int i = 0; i < 10; i++){
            number[index + 1] = i + '0';
            printNumber(result, number, length, index + 1);
        }  
    }

    void print(vector<int> &result, char* number){
        bool iszero = true;
        int temp = 0;
        for(int i = 0; i < strlen(number); i++){
            if(iszero && number[i] != '0'){
                iszero = false;
            }
            if(!iszero){
                temp = temp * 10 + (number[i] - '0');
            }
        }
        if(!iszero)
            result.push_back(temp);
    }
};
