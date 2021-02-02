/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
限制：0 <= k <= arr.length <= 10000, 0 <= arr[i] <= 10000.
思路：用了堆的思想，当前堆里个数小于k个时直接插入，否则比较当前元素和堆顶元素再判断是否插入。时间复杂度O(nlogk)，空间复杂度O(k)，其中n为数组长度。这里的multiset可以用优先队列来替换。
还有其他方法，比如快速选择法，时间复杂度O(n)，空间复杂度O(n)，但还不是很熟练。

*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result;
        if(k <= 0)
            return result;
        multiset<int, greater<int>> set;
        for(int i = 0; i < arr.size(); i++){
            if(set.size() < k)
                set.insert(arr[i]);
            else{
                auto maxnum = set.begin();
                if(arr[i] < *maxnum){
                    set.erase(maxnum);
                    set.insert(arr[i]);
                }
            }
        }
        for(auto it = set.begin(); it != set.end(); it++)
            result.push_back(*it);
        return result;
    }
};
