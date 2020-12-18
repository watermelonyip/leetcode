/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
思路：用双指针方法来修改，时间复杂度O(n)，空间复杂度O(1)(还是O(n)?)；而不是移动元素
如果s原本长度足够大，直接在s上进行修改

*/
class Solution {
public:
    string replaceSpace(string s) {
        if(s.length() <= 0)
            return "";
        int blank = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ')
                blank++;
        }
        char result[s.length() + blank * 2 + 1];
        result[s.length() + blank * 2] = '\0';
        int p1 = s.length() - 1, p2 = s.length() + blank * 2 - 1;
        while(p1 >= 0){
            if(s[p1] == ' '){
                result[p2--] = '0';
                result[p2--] = '2';
                result[p2--] = '%';
            }
            else
                result[p2--] = s[p1];
            p1--;
        }
        return result;
    }
};
