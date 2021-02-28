/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。限制：0 <= s 的长度 <= 50000。
思路：因为s中只包含小写字母，所以用一个表来记录这26个字母出现的次数即可。遍历一遍字符串记录每个出现的字母出现的次数，然后再遍历一遍找出第一个只出现一次的字符。
时间复杂度O(n)，空间复杂度O(26)=O(1)，其中n为字符串的长度。
*/
class Solution {
public:
    char firstUniqChar(string s) {
        if(s == "")
            return ' ';
        int* arr = new int[26];
        for(int i = 0; i < 26; i++)
            arr[i] = 0;
        for(int i = 0; i < s.length(); i++){
            arr[s[i] - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(arr[s[i] - 'a'] == 1)
                return s[i];
        }
        delete[] arr;
        return ' ';
    }
};
