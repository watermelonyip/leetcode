/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int result = 0;
        int **arr = new int*[n];
        for(int i = 0; i < n; i++)
            arr[i] = new int[m];
        for(int j = 0; j < m; j++)
            arr[n - 1][j] = 1;
        for(int i = 0; i < n; i++)
            arr[i][m - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            for(int j = m - 2; j >= 0; j--){
                arr[i][j] = arr[i + 1][j] + arr[i][j + 1];
            }
        }
        return arr[0][0];
    }
};

/*
可以用组合数学的方法：https://leetcode-cn.com/problems/unique-paths/solution/bu-tong-lu-jing-by-leetcode-solution-hzjf/
*/
