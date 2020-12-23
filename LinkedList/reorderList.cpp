#include <iostream>
#include <vector>
using namespace std;
/* https://leetcode-cn.com/problems/reorder-list/
 *
 * 143. 重排链表
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.*/


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        /* 中点+逆序+双指针重排
         * Complexity:
         *      time: O(3/2*N) - N为节点个数
         *      space: O(1)
         *      */
        if (!head){return;}
        ListNode* h2 = getMid(head);  // 获取第二段头节点
        h2 = reverse(h2);  // 逆序
        reorder(head, h2);  // 重排
    }

    ListNode* getMid(ListNode* &head){
        /* 获取链表中点并切断
         * Complexity:
         *      time: O(N/2) - N为以head为头节点的链表节点个数
         *      space: O(1)
         *      */
        ListNode *low, *fast;
        low = head;
        fast = head->next;
        while (fast && fast->next){
            low = low->next;
            fast = fast->next->next;
        }
        ListNode* right = low->next;
        low->next = nullptr;
        return right;
    }

    ListNode* reverse(ListNode* &head){
        /* 逆序链表
         * Complexity:
         *      time: O(N) - N为以head为头节点的链表节点个数
         *      space: O(1)
         *      */
        ListNode *ptr1, *ptr2;
        ptr1 = nullptr;
        ptr2 = head;
        while(ptr2){
            ListNode* ptr3 = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr3;
        }
        return ptr1;  // 逆序后的头节点
    }

    void reorder(ListNode* &h1, ListNode* &h2){
        /* 重排序
         * Complexity:
         *      time: O(N) - N为h1/h2为头节点的链表节点个数
         *      space: O(1)
         *      */
        while (h1 && h2){
            ListNode *n1, *n2;
            n1 = h1->next;
            n2 = h2->next;

            h1->next = h2;
            h2->next = n1;

            h1 = n1;
            h2 = n2;
        }
    }

    void reorderListStack(ListNode* head) {
        /* 栈存储
         * Complexity:
         *      time: O(3/2*N) - N为节点数
         *      space: O(N)
         *      */
        if(!head){return;}
        vector<ListNode*> stack;
        ListNode* h = head->next;
        while(h){
            stack.push_back(h);
            h = h->next;
        }

        int begin, end;
        begin = 0;
        end = stack.size() - 1;

        while (begin <= end){
            head->next = stack[end];
            head = head->next;
            end --;

            if(begin <= end){
                head->next = stack[begin];
                head = head->next;
            }
            begin ++;
        }
        head->next = nullptr;
    }

    void reorderListRecursion(ListNode* head) {
    /* 递归
     * Complexity:
     *      time: O(N^2/2) - N为节点数
     *      space: O(N/2)
     *      */
        if (!head || !head->next || !head->next->next){return;}
        ListNode* cur = head;
        while (cur->next->next){
            cur = cur->next;
        }
        cur->next->next = head->next;
        head->next = cur->next;
        cur->next = nullptr;
        reorderListRecursion(head->next->next);
    }
};


int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution s;
//    s.reorderList(node1);  // 中点+逆序+重排
//    s.reorderListStack(node1);  // 栈存储
    s.reorderListRecursion(node1);  // 递归

    while(node1){
        cout << node1->val << ' ';
        node1 = node1->next;
    }

}