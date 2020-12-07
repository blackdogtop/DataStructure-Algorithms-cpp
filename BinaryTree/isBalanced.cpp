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
    bool isBalanced(TreeNode* root) {
        // Complexity:
        //     time: O(NlogN)
        //     space: O(N) ?
        if(root == nullptr) {
            return true;
        }
        queue <TreeNode*> stack;
        stack.push(root);

        while(!stack.empty()) {
            TreeNode* currentNode;
            currentNode = stack.front();
            stack.pop();
            if(currentNode->left) {
                stack.push(currentNode->left);
            }
            if(currentNode->right) {
                stack.push(currentNode->right);
            }

            int leftDepth;
            int rightDepth;
            leftDepth = maxDepth(currentNode->left);
            rightDepth = maxDepth(currentNode->right);
            if(abs(leftDepth - rightDepth) > 1){
                return false;
            }
        }
        return true;
    }

    bool isBalancedOptimised(TreeNode* root) {
        // Complexity:
        //      time: O(n)
        //      space: 最坏O(n) ?
        if(root == nullptr) {return true;}
        if(depth(root) == -1) {return false;}
        return true;
    }

protected:
    int maxDepth(TreeNode* root) {
        // 当根节点为root时的二叉树最大深度
        // Complexity:
        //     time: O(n)
        //     space: O(height) - height为二叉树的最大深度 函数递归需要栈空间 栈空间取决于递归次数 
        if(root == nullptr) {
            return 0;
        }
        int leftDepth;
        int rightDepth;

        leftDepth = maxDepth(root->left);
        rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }

    int depth(TreeNode* root) {
        // 平衡树条件下的二叉树最大深度
        // Complexity:
        //      time: O(n)
        //      space: O(height)
        if(root == nullptr) {
            return 0;
        }

        int leftDepth;
        int rightDepth;
        leftDepth = depth(root->left);
        if(leftDepth == -1){return -1;} // 当子节点构成的二叉树不是平衡树 则包含此子节点的父节点也不可能是平衡树
        rightDepth = depth(root->right);
        if(rightDepth == -1){return -1;}
        if(abs(leftDepth - rightDepth) <= 1) {
            return max(leftDepth, rightDepth) + 1;
        }
        else {
            return -1;
        }

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
    bool res;
    res = s.isBalanced(&node3);
    cout << res << endl;

    bool res2;
    res2 = s.isBalancedOptimised(&node3);
    cout << res << endl;
}