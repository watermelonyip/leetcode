/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
限制：1 <= k < s.length <= 10000.
思路：简单的做法是直接字符串截取再拼接，但是string的操作消耗比较大。另一种方法：用上一道题字符串翻转的方法，先将整个字符串翻转，然后将字符串分为两部分。
第一部分是不需要左旋的，第二部分是需要左旋的。分别将这两部分再做字符串翻转，得到最后的结果。
时间复杂度O(n)，空间复杂度O(1)，其中n为字符串长度。
*/
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(s == "" || n <= 0 || n >= s.length() || s.length() == 1)
            return s;
        reverse(s, 0, s.length() - 1);
        reverse(s, 0, s.length() - n - 1);
        reverse(s, s.length() - n, s.length() - 1);
        return s;
    }

    void reverse(string &s, int begin, int end){
        if(s == "" || begin >= end)
            return;
        while(begin < end){
            char temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;
            begin++;
            end--;
        }
    }
};
