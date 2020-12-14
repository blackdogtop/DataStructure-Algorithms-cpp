#include <iostream>
#include <stack>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /* 
        Complexity:
            time: O(n)
            space: O(n)
         */
        if(root == nullptr) {
            return root;
        }
        if(root == q || root == p) {
            return root;
        }

        TreeNode* left;
        TreeNode* right;
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);
        
        if(left == nullptr){
            return right;
        }
        if(right == nullptr) {
            return left;
        }

        if(left && right) { // p q异侧
            return root;
        }
    return nullptr;
    }
};


int main() {
    TreeNode node3 = 3;
    TreeNode node5 = 5;
    TreeNode node1 = 1;
    TreeNode node6 = 6;
    TreeNode node2 = 2;
    TreeNode node0 = 0;
    TreeNode node8 = 8;
    TreeNode node7 = 7;
    TreeNode node4 = 4;

    node3.left = &node5;
    node3.right = &node1;
    node5.left = &node6;
    node5.right = &node2;
    node1.left = &node0;
    node1.right = &node8;
    node2.left = &node7;
    node2.right = &node4;

    Solution s;
    bool res;
    res = s.lowestCommonAncestor(&node3, &node5, &node1);
    cout << res << endl;

}