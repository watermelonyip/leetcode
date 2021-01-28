/*
请实现两个函数，分别用来序列化和反序列化二叉树。
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

思路：采用层次遍历的方法，但是需要注意写入写出的方法，序列化时输出非空叶子节点的左右节点(nullptr, nullptr)对于后面反序列化比较方便。
时间复杂度O(n)，空间复杂度O(n)，其中n为二叉树节点数量。太难了真的，多练练吧。

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        string result = "";
        ostringstream stream;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp != nullptr){
                stream << temp->val << ' ';
                //result += to_string(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            }  
            else
                //result += "$";
                stream << "$ ";
            //result += ",";
        }
        return stream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() <= 0)
            return nullptr;
        vector<TreeNode*> vec;
        string val;
        istringstream input(data);
        while(input >> val){
            if(val == "$")
                vec.push_back(nullptr);
            else
                vec.push_back(new TreeNode(stoi(val)));
        }
        /*
        cout << vec.size() << endl;
        for(int i = 0; i < vec.size(); i++)
            if(vec[i] == nullptr)
                cout << "null, ";
            else
                cout << vec[i]->val << " , ";
        */
        int num = 0;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i] == nullptr)
                continue;
            vec[i]->left = vec[num * 2 + 1];
            vec[i]->right = vec[num * 2 + 2];
            num++;
        }
        return vec[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
