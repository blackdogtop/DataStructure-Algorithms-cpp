#include <iostream>
#include <queue>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int leftDepth;
        int rightDepth;

        leftDepth = maxDepth(root->left);
        rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }

    int bfs(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        queue <TreeNode*> stack;
        stack.push(root);
        int layer = 0;

        while(!stack.empty()) {
            int size = stack.size();  // 记录本层的节点数量
            while(size > 0) {
                TreeNode* currentNode = stack.front(); 
                stack.pop();  // queue只能从尾部添加 从头部移除
                if(currentNode->left){
                    stack.push(currentNode->left);
                }
                if(currentNode->right) {
                    stack.push(currentNode->right);
                }
                size --;
            }
            layer ++;
        }
        return layer;
    }
};

int main(){
    TreeNode node3 = TreeNode(3);
    TreeNode node9 = TreeNode(9);
    TreeNode node20 = TreeNode(20);
    TreeNode node15 = TreeNode(15);
    TreeNode node7 = TreeNode(7);

    node3.left = &node9;
    node3.right = &node20;
    node20.left = &node15;
    node20.right = &node7;

    Solution s;
    int res;
    res = s.maxDepth(&node3);
    cout << res << endl;

    int res2 = s.bfs(&node3);
    cout << res2 << endl;
}