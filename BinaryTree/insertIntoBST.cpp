#include <iostream>
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        /*Complexity:
         *      time: O(logN)
         *      space: O(1)
         *      */
        if (root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode *pos = root;
        while(pos) {
            if(pos->val < val) {
                if(pos->right == nullptr){
                    pos->right = new TreeNode(val);
                    break;
                }
                else{
                    pos = pos->right;
                }
            }
            else{
                if(pos->left == nullptr){
                    pos->left = new TreeNode(val);
                    break;
                }
                else{
                    pos = pos->left;
                }
            }
        }
        return root;
    }
};