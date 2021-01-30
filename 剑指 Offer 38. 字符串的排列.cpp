/*
输入一个字符串，打印出该字符串中字符的所有排列。你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
限制：1 <= s 的长度 <= 8。
思路：递归，记录每个起始位置index，然后用index后的每个位置和该位置交换。过程比较难理解，画图有助于理解。还有就是，为了处理重复元素，用哈希集来记录和判断。
时间复杂度O(n!)，空间复杂度O(n^2)，其中n为字符串长度。

*/
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> result;
        if(s == ""){
            result.push_back(s);
            return result;
        }
        unordered_set<string> set;
        permutation(s, 0, result, set);
        return result;
    }

    void permutation(string s, int index, vector<string> &result, unordered_set<string> &set){
        if(index == s.length() && set.find(s) == set.end()){
            result.push_back(s);
            set.insert(s);
        }
        
        for(int p = index; p < s.length(); p++){
            if(s[index] == s[p] && index != p)
                continue;
            char temp = s[index];
            s[index] = s[p];
            s[p] = temp;

            permutation(s, index + 1, result, set);

            temp = s[index];
            s[index] = s[p];
            s[p] = temp;
        }
    }
};
