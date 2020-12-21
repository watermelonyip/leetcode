/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

思路：使用二分查找的思想，如果中间元素比low处的值大，则中间元素在左边的递增子数组中；如果中间元素比high处的值小，则中间元素在右边的递增子数组中。两个指针一直往中间逼近，直到相邻。
但是注意的是，这种方法对于有重复元素要特殊处理，比如low处的值=中间元素=high处的值，这时候需要进行顺序查找。
时间复杂度：平均时间复杂度为 O(logn)，其中 n 是数组 numbers 的长度。如果数组是随机生成的，那么数组中包含相同元素的概率很低，在二分查找的过程中，大部分情况都会忽略一半的区间。而在最坏情况下，如果数组中的元素完全相同，那么 while 循环就需要执行 
n 次，每次忽略区间的右端点，时间复杂度为 O(n)。
空间复杂度：O(1)。


*/
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size() <= 0)
            return -1;
        if(numbers.size() == 1)
            return numbers[0];
        int low = 0, high = numbers.size() - 1, mid = high - (high - low) / 2;
        if(numbers[low] < numbers[high])
            return numbers[low];
        while(low <= high){
            mid = high - (high - low) / 2;
            if(numbers[mid] == numbers[low] && numbers[low] == numbers[high]){
                int min = numbers[0];
                for(int i = 1; i < numbers.size(); i++){
                    if(numbers[i] < min)
                        min = numbers[i];
                }
                return min;
            }
            if(numbers[mid] >= numbers[low])
                low = mid;
            else if(numbers[mid] <= numbers[high])
                high = mid;
            if(high - low == 1)
                return numbers[high];
        }
        return numbers[high];
    }
};
