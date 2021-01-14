/*
请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

思路：判断下一个符号是否为*。如果下一个符号是*，分为是否匹配两种情况，如果匹配，可以选择继续看或不看*两种情况，如果不匹配，匹配串往下走两步；如果下一个符号不是*，则直接判断是否匹配。
可以用递归或者动归，然而两种方法都不是很熟悉。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.length() == 0 && p.length() == 0)
            return true;

        if(s[0] != '\0' && p[0] == '\0')
            return false;
        
        if(p[1] == '*'){
            if(s[0] == p[0] || p[0] == '.' && s[0] != '\0'){
                return isMatch(s.substr(1, s.length() - 1), p)
                        || isMatch(s, p.substr(2, p.length() - 2));
            }
            else{
                return isMatch(s, p.substr(2, p.length() - 2));
            }
        }
        if(s[0] == p[0] || s[0] != '\0' && p[0] == '.')
            return isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));

        return false;
    }
};
