/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。提示：你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
思路：用双端队列来辅助，新窗口即将输入的值从队列末尾开始比较，如果大于队列的值，那么队列的值pop_back；否则push_back到队列末尾（因为可能是以后窗口的最大值）。
然后需要判断位于队列前端的数字是否还在当前窗口内，如果不在则pop_front；否则位于队列最前面的数字就是当前窗口的最大值。注意的是为了方便比较，队列里面存放的是数字在数组里的下标。
时间复杂度O(n)，空间复杂度O(k)，其中n为数组大小，k为滑动窗口大小。
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size() <= 0 || k <= 0)
            return result;
        deque<int> index;
        for(int i = 0; i < k && i < nums.size(); i++){
            while(!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        
        for(int i = k; i < nums.size(); i++){
            result.push_back(nums[index.front()]);
            while(!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();
            index.push_back(i);
            if(!index.empty() && index.front() <= (i - k))
                index.pop_front();
        }
        result.push_back(nums[index.front()]);
        return result;
    }
};
