/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]
但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

思路：回溯法。可以理解为树，从任意点出发，不符合则回溯到上一个节点。比较复杂。
时间复杂度 O(3^K MN) ： 最差情况下，需要遍历矩阵中长度为 K 字符串的所有方案，时间复杂度为 O(3^K)；矩阵中共有 MN 个起点，时间复杂度为 O(MN) 。
方案数计算： 设字符串长度为 K ，搜索中每个字符有上、下、左、右四个方向可以选择，舍弃回头（上个字符）的方向，剩下 3 种选择，因此方案数的复杂度为 O(3^K) 。
空间复杂度 O(K) ： 搜索过程中的递归深度不超过 K ，因此系统因函数调用累计使用的栈空间占用 O(K) （因为函数返回后，系统调用的栈空间会释放）。最坏情况下 K = MN ，递归深度为 O(MN) 的额外空间。

*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() == 0)
            return false;
        bool *visited = new bool[board.size() * board[0].size()];
        memset(visited, 0, board.size() * board[0].size());
        int index = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(findPath(board, word, index, i, j, visited))
                    return true;
            }
        }
        delete[] visited;
        return false;
    }

    bool findPath(vector<vector<char>>& board, const string word, int& index, int row, int col, bool *visited){
        if(word[index] == '\0')
            return true;
        bool hasPath = false;
        if(row >= 0 && row < board.size() && col >= 0 && col < board[row].size() && !visited[row * board[row].size() + col] && board[row][col] == word[index]){
            index++;
            visited[row * board[row].size() + col] = true;
            hasPath = findPath(board, word, index, row, col - 1, visited)
                      || findPath(board, word, index, row - 1, col, visited)
                      || findPath(board, word, index, row, col + 1, visited)
                      || findPath(board, word, index, row + 1, col, visited);
            if(!hasPath){
                index--;
                visited[row * board[row].size() + col] = false;
            }
        }
        return hasPath;
    }
};
