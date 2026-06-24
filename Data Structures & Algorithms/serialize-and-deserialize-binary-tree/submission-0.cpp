/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }
        string s = "";

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {

            TreeNode* curNode = q.front();
            q.pop();

            if (curNode == nullptr) {
                s += "#,";
            } 
            else {
                s += to_string(curNode->val) + ",";

                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {

        if(data.size() == 0) {
            return NULL;
        }

        stringstream ss(data);

        string str;

        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            getline(ss, str, ',');

            if(str != "#") {

                TreeNode* leftNode = new TreeNode(stoi(str));

                node->left = leftNode;

                q.push(leftNode);
            }

            getline(ss, str, ',');

            if(str != "#") {

                TreeNode* rightNode = new TreeNode(stoi(str));

                node->right = rightNode;

                q.push(rightNode);
            }
        }

        return root;
    }
};
