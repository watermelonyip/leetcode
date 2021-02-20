/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
提示：0 <= num < 2^31.
思路：可以用递归，但是递归可能有重复的子程序，所以从字符串后往前处理比较好。用一个数组arr来存储次数。比如12258，对于8，arr[4] = 1;对于5，因为58不能翻译过来，所以arr[3] = 1;
对于2，有两种情况，如果只看2，那么arr[2] = arr[3] = 1,如果看2和5组合成25，那么arr[2] = arr[4] = 1，将这两种情况加起来，所以arr[2] = 1 + 1 = 2;对于剩下的两个数字也是这样处理。
最后返回arr[0]。需要注意最后要delete[] arr。时间复杂度O(n)，空间复杂度O(n)，其中n为字符串长度。
优化：可以用求余和整除的方法来代替转换成字符串，可以用两个值记录arr[i + 1]和arr[i + 2]来代替数组。时间复杂度O(n)，空间复杂度O(1)，其中n为字符串长度。
*/
class Solution {
public:
    int translateNum(int num) {
        if(num < 0)
            return 0;
        string number = to_string(num);
        int length = number.length();
        int* arr = new int[length];
        int count = 0;
        for(int i = length - 1; i >= 0; i--){
            int count = 0;
            if(i == length - 1)
                count = 1;
            else
                count = arr[i + 1];
            if(i < length - 1){
                int digit = (number[i] - '0') * 10 + (number[i + 1] - '0');
                //cout << digit << endl;
                if(digit >= 10 && digit <= 25){
                    if(i < length - 2)
                        count += arr[i + 2];
                    else
                        count += 1;
                }
            }
            arr[i] = count;
        }
        count = arr[0];
        delete[] arr;
        return count;
        
        
        /*
        //用变量a和b记录arr[i]和arr[i + 2]来代替数组。
        int a = 1, b = 0;   //  记录arr[i + 1]和arr[i + 2]
        int number = num;
        int count = 0;
        while(number){
            count = a;
            int digit = number % 100;
            if(digit >= 10 && digit <= 25){
                if(number < num)
                    count += b;
                else
                    count += 1;
            }
            b = a;
            a = count;
            number /= 10;
        }
        return a;
        */
    }
};
