/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。限制：0 <= matrix.length <= 100，0 <= matrix[i].length <= 100。
思路：四个方向，顺序是往左，往下，往右，往上。需要注意的是边界处理，因此用四个常量来记录边界值。需要特别注意循环里面的判断。时间复杂度O(mn)，空间复杂度O(1)，其中m，n分别为矩阵的行数和列数。
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() <= 0)
            return result;
        int row = matrix.size();
        int col = matrix[0].size();
        if(col <= 0)
            return result;
        int startX = 0, endX = row - 1;
        int startY = 0, endY = col - 1;
        while(startX <= endX && startY <= endY){
            for(int i = startY; i <= endY; i++){
                //cout << matrix[startX][i] << "  ";
                result.push_back(matrix[startX][i]);
            }
            startX++;
            for(int i = startX; i <= endX; i++){
                //cout << matrix[i][endY] << "  ";
                result.push_back(matrix[i][endY]);
            }
            endY--;
            for(int i = endY; i >= startY && startX <= endX; i--){
                //cout << matrix[endX][i] << "  ";
                result.push_back(matrix[endX][i]);
            }
            endX--;
            for(int i = endX; i >= startX && startY <= endY; i--){
                //cout << matrix[i][startY] << "  ";
                result.push_back(matrix[i][startY]);
            }
            startY++;
        }
        return result;
    }
};
