#include <iostream>
#include <float.h>
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
    float maxNum = -DBL_MAX;  // 负无穷

    int maxPathSum(TreeNode* root) {
        recursion(root);
        return maxNum;
    }

    int recursion(TreeNode* root) {
        // 递归 - 当根结点为root时与左/右子树的最大路径和
        // Complexity:
        //      time: O(n)
        //      space: 最差O(n)
        if(root == nullptr) {
            return 0;
        }
        int leftPathSum;
        int rightPathSum;
        leftPathSum = recursion(root->left);
        rightPathSum = recursion(root->right);

        // 更新最大值
        if(root->val + max(0, leftPathSum) + max(0, rightPathSum) > maxNum) {
            maxNum = root->val + max(0, leftPathSum) + max(0, rightPathSum);
        }

        return max(0, max(leftPathSum, rightPathSum)) + root->val;
    }

};

int main() {
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(-2);
    TreeNode node3 = TreeNode(3);

    node1.left = &node2;
    node1.right = &node3;

    Solution s;
    int res;
    res = s.maxPathSum(&node1);
    cout << res << endl;
}