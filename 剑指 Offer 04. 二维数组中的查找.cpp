/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

思路：从右上角或者左下角开始，因为只有从这两个点出发，每次才能排除一列或一行，缩小范围；若从左上角或右下角开始则没有这个效果。
时间复杂度：O(n + m)，空间复杂度O(1)
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row <= 0)
            return false;
        int col = matrix[0].size();
        if(col <= 0)
            return false;
        
        int i = 0, j = col - 1;
        while(i < row && j >= 0){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};
