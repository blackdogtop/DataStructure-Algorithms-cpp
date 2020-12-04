#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> res;

        while(root || !stack.empty()){
            while(root){
                stack.push_back(root);
                if(root->left){
                    root = root->left;
                }
                else{
                    root = root->right;
                }
            }

            root = stack.back();
            stack.pop_back();
            res.push_back(root->val);
            if(!stack.empty() && stack.back()->left == root){
                root = stack.back()->right;
            }
            else
            {
                root = nullptr;
            }    
        }
        return res;
    }

    void dfs(TreeNode* root, vector<int>& result){  // 传入引用
        if(root == nullptr){return;}
        if(root->left){
            dfs(root->left, result);
        }
        if(root->right){
            dfs(root->right, result);
        }
        result.push_back(root->val);
    }

    vector<int> dfsNonRef(TreeNode* root, vector<int> res){
        if(root != nullptr){
            if(root->left){
                dfs(root->left, res);
            }
            if(root->right){
                dfs(root->right, res);
            }
            res.push_back(root->val);
        }
        return res;
    }

    vector<int> postorderTraversalRecursion(TreeNode* root){
        vector<int> res;

        // dfs(root, res);  // 函数形参引用
        // return res;

        return  dfsNonRef(root, res);  // 函数形参非引用
    }
};


int main(){
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);
    TreeNode node3 = TreeNode(3);

    node1.right = &node2;
    node2.left = &node3;

    Solution s;
    vector<int> res = s.postorderTraversal(&node1);

    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }

    cout << endl;

    vector<int> res2 = s.postorderTraversalRecursion(&node1);

    for(int i=0; i<res2.size(); i++){
        cout << res2[i] << " ";
    }

}