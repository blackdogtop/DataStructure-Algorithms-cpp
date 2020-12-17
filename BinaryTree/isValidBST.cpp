#include <iostream>
#include <limits.h>
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
    bool isValidBST(TreeNode* root) {
        bool res;
        res = bst(root, LONG_MIN, LONG_MAX);
        return res;
    }

    bool bst(TreeNode* root, long long leftMax, long long rightMin) {
        /*Complexity:
         *      time: O(n)
         *      space: O(n)
         *      */
        if (root == nullptr) {return true;}
        bool left, right;
        left = bst(root->left, leftMax, root->val);
        if(!left) {return false;}
        right = bst(root->right, root->val, rightMin);
        if(!right) {return false;}
        if(left && right && leftMax < root->val && root->val < rightMin) {return true;}
        return false;
    }
};


int main() {
    TreeNode node5 = 5;
    TreeNode node4 = 4;
    TreeNode node6 = 6;
    TreeNode node3 = 3;
    TreeNode node7 = 7;

    node5.left = &node4;
    node5.right = &node6;
    node6.left = &node3;
    node6.right = &node7;

    Solution s;
    bool res;
    res = s.isValidBST(&node7);
    cout << res << endl;

    cout << INT_MAX <<endl;  // 2^31-1
    cout << LONG_MAX << endl; // 2^63-1
}