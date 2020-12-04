#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int a): data(a), left(NULL), right(NULL){}
};

class Traverse{
    public:
        void preOrder(TreeNode* root){ // 指向结构变量的指针
            if(root == NULL){
                return;
            }

            cout << root->data << " ";

            if(root->left != NULL){
                preOrder(root->left);
            }
            if(root->right != NULL){
                preOrder(root->right);
            }
        }


        void preOrderNonRecursion(TreeNode* root){
            stack<TreeNode *> stack;
            while(!stack.empty() || root != NULL){
                while(root != NULL){
                    cout << root->data << " ";
                    stack.push(root);
                    root = root->left;
                }
                if(!stack.empty()){
                    root = stack.top();
                    stack.pop();
                    root = root -> right;
                }
            }
        }


        void inOrder(TreeNode* root){
            if(root == NULL){
                return;
            }
            if(root->left){
                inOrder(root->left);
            }

            cout << root->data << " ";

            if(root->right){
                inOrder(root->right);
            }
        }


        void inOrderNonRecustion(TreeNode* root){
            stack<TreeNode*> stack;
            while(root != NULL || !stack.empty()){
                while(root != NULL){
                    stack.push(root);
                    root = root->left;
                }

                if(!stack.empty()){
                    root = stack.top();
                    stack.pop();

                    cout << root->data << " ";

                    root = root->right;
                }
            }
        }


        void postOrder(TreeNode* root){
            if(root==NULL){
                return;
            }
            if(root->left){
                postOrder(root->left);
            }
            if(root->right){
                postOrder(root->right);
            }
            cout << root->data << " ";
        }


        void postOrderNonRecursion(TreeNode* root){
            stack<TreeNode*> stack;
            while(root || !stack.empty()){
                while(root){
                    stack.push(root);
                    if(root->left){
                        root = root->left;
                    }
                    else{
                        root = root->right;
                    }
                }
                root = stack.top();
                stack.pop();
                cout << root->data << " ";

                if(!stack.empty() && stack.top()->left == root){
                    root = stack.top()->right;
                }
                else{
                    root = NULL;
                }
            }
        }

};

int main(){
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);
    TreeNode node3 = TreeNode(3);
    TreeNode node4 = TreeNode(4);
    TreeNode node5 = TreeNode(5);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;

    Traverse t;
    t.preOrder(&node1);

    cout << endl;

    t.preOrderNonRecursion(&node1);

    cout << endl;

    t.inOrder(&node1);

    cout << endl;

    t.inOrderNonRecustion(&node1);

    cout << endl;

    t.postOrder(&node1);

    cout << endl;

    t.postOrderNonRecursion(&node1);
}