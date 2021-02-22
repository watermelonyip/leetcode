/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
提示：0 < grid.length <= 200, 0 < grid[0].length <= 200.
思路：动态规划，用数组来存储当前格子计算的最大值。原始方法，用二维数组记录，时间复杂度O(mn),空间复杂度O(mn)。
改进：用一维数组来存储，假设当前格子味i,j，那么数组中前j个数为第i行的第0列到第j-1列格子的最大值，数组中后n-j个数为第i-1行第j列到第n列的格子最大值。
即，前j个数为当前第i行在[i,j]之前的数（左边）的最大值，后n-j个数为第i-1行[i-1,j]之后的数（上一行对应列计算出来的最大值）。时间复杂度O(mn)，空间复杂度O(n)。
*/
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.size() <= 0)
            return 0;
        if(grid[0].size() <= 0)
            return 0;
        int* maxvalue = new int[grid[0].size()];
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                int up = 0, left = 0;
                if(i > 0)
                    up = maxvalue[j];
                if(j > 0)
                    left = maxvalue[j - 1];
                maxvalue[j] = max(up, left) + grid[i][j];
            }
        }
        int result = maxvalue[grid[0].size() - 1];
        delete[] maxvalue;
        return result;
    }
};
