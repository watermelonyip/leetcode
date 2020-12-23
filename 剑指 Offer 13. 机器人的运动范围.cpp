/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

思路：使用回溯法，时间复杂度O(mn)，空间复杂度O(mn)。也可以使用广度优先搜索，时间复杂度和空间复杂度一样。需要注意的点是，每次只需要搜索右边和下边的点即可。
*/
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(m <= 0 || n <= 0 || k < 0)
            return 0;
        bool* visited = new bool[m * n];
        memset(visited, 0, m * n);
        int count = countNums(m, n, k, visited, 0, 0);
        delete[] visited;
        return count;
    }

    int countNums(int row ,int col, int k, bool* visited, int i, int j){
        //cout << " i: " << i << " j: " << j << endl;
        int count = 0;
        if(i >= 0 && i < row && j >= 0 && j < col && !visited[i * col + j] && getDigitSum(i, j) <= k){
            visited[i * col + j] = true;
            count = 1 + countNums(row, col, k, visited, i, j + 1)
                    + countNums(row, col, k, visited, i + 1, j);
        }
        return count;
    }

    int getDigitSum(int num1, int num2){
        //cout << num1 << "  " << num2;
        int sum = 0;
        while(num1){
            sum += num1 % 10;
            num1 /= 10;
        }
        while(num2){
            sum += num2 % 10;
            num2 /= 10;
        }
        //cout << "   " << sum << endl;
        return sum;
    }
};
