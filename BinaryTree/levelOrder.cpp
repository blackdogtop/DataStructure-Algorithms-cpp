#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        /* 
        Complexity:
            time: O(N)
            space: O(N)
         */
        vector<vector<int> > res;
        if(root == nullptr) {return res;}
        queue<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            int size = stack.size();
            vector<int> layer;
            while(size > 0) {
                TreeNode *currentNode = stack.front();
                stack.pop();
                if(currentNode->left){stack.push(currentNode->left);}
                if(currentNode->right){stack.push(currentNode->right);}
                layer.push_back(currentNode->val);
                size --;
            }
            res.push_back(layer);
        }
        return res;
    }
};


int main(){
    TreeNode node1 = 1;
    TreeNode node2 = 2;
    TreeNode node3 = 3;
    node1.left = &node2;
    node2.right = &node3;

    Solution s;
    vector<vector<int> > res;
    res = s.levelOrder(&node1);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
    }
    cout << endl;
}