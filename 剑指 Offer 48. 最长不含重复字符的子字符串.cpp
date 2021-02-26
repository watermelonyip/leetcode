/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。提示：s.length <= 40000.字符串里可能有大小写字母数字等，这里的要求和书本不一样。
思路：用哈希表记录每个字符最新一次出现的下标。当前遍历到下标i时，如果之前没有出现过该字符，则length++；
如果下标i距离上一次出现的距离d大于当前length，则表示length长度字符串内没有出现过该字符，则可以length++；
如果下标i距离上一次出现的距离d小于或等于当前length，则表示length长度字符串内出现过该字符，则length=d。
时间复杂度O(n)，空间复杂度O(1)，其中n为字符串长度，而且因为字符的ASCII码范围为0 ~ 127，所以最多使用O(128)额外空间，空间复杂度为O(128)=O(1)。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1)
            return s.length();
        int length = 0, maxlength = 0;
        /*
        int* position = new int[26];
        for(int i = 0; i < 26; i++)
            position[i] = -1;
        */
        unordered_map<char,int> set;
        for(int i = 0; i < s.length(); i++){
            if(set.find(s[i]) == set.end() || (i - set[s[i]] > length))
                length++;
            else
                length = i - set[s[i]];
            if(length > maxlength)
                maxlength = length;
            set[s[i]] = i;
            //cout << set[s[i]] << endl;
        }
        return maxlength;
    }
};
