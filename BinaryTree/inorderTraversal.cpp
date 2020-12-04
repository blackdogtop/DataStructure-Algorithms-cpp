#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> res;

        while(root || !stack.empty()){
            while (root)
            {
                stack.push_back(root);
                root = root->left;
            }
            
            if(!stack.empty()){
                root = stack.back();
                stack.pop_back();

                res.push_back(root->val);

                root = root->right;
            }
        }

        return res;
    }

    vector<int> inorderTraversalRecursion(TreeNode* root){
        if(root){
            if(root->left){
                inorderTraversalRecursion(root->left);
            }

            res.push_back(root->val);

            if(root->right){
                inorderTraversalRecursion(root->right);
            }
        }
        return res;
    }   

protected:
    vector<int> res;
};


int main(){
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);
    TreeNode node3 = TreeNode(3);

    node1.right = &node2;
    node2.left = &node3;

    Solution s;

    vector<int> res;
    res = s.inorderTraversal(&node1);

    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }

    vector<int> res2;
    res2 = s.inorderTraversalRecursion(&node1);

    cout << endl;

    for(int i=0; i<res2.size(); i++){
        cout << res[i] << " ";
    }
}