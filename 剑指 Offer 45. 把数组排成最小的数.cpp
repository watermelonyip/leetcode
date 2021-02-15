/*
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
提示:0 < nums.length <= 100.
说明:输出结果可能非常大，所以你需要返回一个字符串而不是整数,拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
思路：用sort来将vector排序，其中的compare自定义。比较规则是，数字s1和s2拼接起来，如果s1s2<s2s1，那么s1<s2，反之则反。时间复杂度O(nlogn)，空间复杂度O(1)，其中n为数组大小。
需要注意的是compare算法里不要直接返回strcmp的结果，不然排序毫无规则。
*/
class Solution {
public:
    string minNumber(vector<int>& nums) {
        if(nums.size() <= 0)
            return "";
        sort(nums.begin(), nums.end(), compare);
        string result = "";
        for(int i = 0; i < nums.size(); i++)
            //cout << nums[i] << "  ";
            result += to_string(nums[i]);
        return result;
    }

    static bool compare(int d1, int d2){
        string s1 = to_string(d1) + to_string(d2);
        string s2 = to_string(d2) + to_string(d1);
        //cout << s1 << "  " << s2 << "  " << strcmp(s1.c_str(), s2.c_str()) << endl;
        if(strcmp(s1.c_str(), s2.c_str()) < 0)
            return true;
        return false;
    }
};
