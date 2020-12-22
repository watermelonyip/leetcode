/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]
但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

思路：回溯法。可以理解为树，从任意点出发，不符合则回溯到上一个节点。比较复杂。
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
