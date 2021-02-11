/*
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
思路：找规律，讲数字拆分处理。时间复杂度O(logn)。太难了目前都没有很明白。
其他方法：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/
*/
class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0)
            return 0;
        return countNum(to_string(n));
    }

    int countNum(string n){
        if(n == "" || n[0] < '0' || n[0] > '9' || n[0] == '\0')
            return 0;
        
        int first = n[0] - '0';
        if(first == 0 && n.length() == 1)
            return 0;
        if(n.length() == 1 && first > 0)
            return 1;
        
        int firstNum = 0;
        if(first > 1)
            firstNum = countPower(n.length() - 1);
        else if(first == 1)
            firstNum = atoi(n.substr(1).c_str()) + 1;
        
        int otherNum = first * (n.length() - 1) * countPower(n.length() - 2);
        int recursiveNum = countNum(n.substr(1));
        return firstNum + otherNum + recursiveNum;
    }

    int countPower(int n){
        int result = 1;
        for(int i = 0; i < n; i++){
            result *= 10;
        }
        return result;
    }
};
