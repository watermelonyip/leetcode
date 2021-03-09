/*
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
说明：无空格字符构成一个单词。输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
思路：书本方法：将整个字符串翻转，然后对每个单词进行翻转，但是书本的方法是对应char*类型的，这里string类型可以省去reverse函数直接用substr。
时间复杂度O(n)，空间复杂度O(n)，其中n为字符串长度。
*/
class Solution {
public:
    string reverseWords(string s) {
        if(s == "")
            return s;
        reverse(s);
        string result = "";
        int begin = 0, end = 0;
        while(begin < s.length()){
            if(s[begin] == ' '){
                begin++;
                continue;
            }
            end = begin;
            while(s[end] != ' ' && end < s.length())
                end++;
            string temp = s.substr(begin, end - begin);
            reverse(temp);
            result += temp + ' ';
            begin = end + 1;
        }
        if(result == "")
            return "";
        result[result.length() - 1] = '\0';
        return result;
    }

    void reverse(string &s){
        if(s != ""){
            int begin = 0, end = s.length() - 1;
            while(begin < end){
                char temp = s[begin];
                s[begin] = s[end];
                s[end] = temp;
                begin++;
                end--;
            }
        }
    }
};

//以下是用string的
class Solution {
public:
    string reverseWords(string s) {
        if(s == "")
            return s;
        string result = "";
        int begin = 0, end = s.length() - 1;
        while(begin >= 0){
            while(end >= 0 && s[end] == ' ')
                end--;
            begin = end;
            while(begin >= 0 && s[begin] != ' ')
                begin--;
            if(s[begin + 1] == ' ')
                break;
            //cout << s[begin + 1] << "  " << s[end] << endl;
            if(end > begin + 1){
                string temp = s.substr(begin + 1, end - begin);
                result += temp + " ";
            }
            else{
                result += s[end] + ' ';
                //result += " ";
            }
            end = begin - 1;
        }

        if(result != "")
            result[result.length() - 1] = '\0';
        return result;
    }
};
