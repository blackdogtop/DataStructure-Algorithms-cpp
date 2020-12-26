#include <iostream>
#include <map>
using namespace std;
/* https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 *
 * 138. 复制带随机指针的链表
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 * 要求返回这个链表的 深拷贝。
 * 我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
 * val：一个表示Node.val的整数。
 * random_index：随机指针指向的节点索引（范围从0到n-1）；如果不指向任何节点，则为null。
 *
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 * */


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



class Solution {
public:
    Node* copyRandomList(Node* head) {
        /* Complexity:
         *      time: O(n)
         *      space: O(1)
         *      */
        if(!head){return head;}

        Node* p = head;
        while (p){
            Node* newNode = new Node(p->val);
            newNode->next = p->next;
            p->next = newNode;
            p = p->next->next;
        }

        p = head;
        while (p){
            if (p->random){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        Node* dummy = new Node(-1);
        Node* cur = dummy;
        p = head;
        while(p){
            cur->next = p->next;
            p->next = p->next->next;
            cur = cur->next;
            p = p->next;
        }
        return dummy->next;
    }

    Node* copyRandomListHash(Node* head) {
        /* Complexity:
         *      time: O(n)
         *      sapce: O(n)
         *      */
        if (!head){return head;}

        Node* p = head;
        map<Node*, Node*> hash;
        while (p){
            hash[p] = new Node(p->val);
            p = p->next;
        }

        p = head;
        while (p){
            if (p->next){hash[p]->next = hash[p->next];}
            if (p->random){hash[p]->random = hash[p->random];}
            p = p->next;
        }
        return hash[head];
    }
};