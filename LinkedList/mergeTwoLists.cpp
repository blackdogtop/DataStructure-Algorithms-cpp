#include <iostream>
using namespace std;
/* https://leetcode-cn.com/problems/merge-two-sorted-lists/
 *
 * 21. 合并两个有序链表
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 *
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4*/


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /* 迭代
         * Complexity:
         *      time: O(l1 + l2)
         *      space: O(1)
         *      */
        ListNode* dummy = new ListNode(-1);
        ListNode* a = dummy;
        ListNode* b = l1;
        ListNode* c = l2;

        while(b && c){
            if(b->val < c->val){
                a->next = b;
                b = b->next;
            } else{
                a->next = c;
                c = c->next;
            }
            a = a->next;
        }
        if(b) {a->next = b;}
        if(c) {a->next = c;}
        return dummy->next;
    }

    ListNode* mergeTwoListsRecursion(ListNode* l1, ListNode* l2){
        /* 递归
         * Complexity:
         *      time: O(l1 + l2)
         *      space: O(l1 + l2)
         *      */
        if (!l1 || !l2) {
            if (!l1) { return l2; }
            else { return l1; }
        }
        if(l1->val < l2->val){
            l1->next = mergeTwoListsRecursion(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoListsRecursion(l1, l2->next);
            return l2;
        }
    }

};

int main(){
    ListNode* node11 = new ListNode(1);
    ListNode* node12 = new ListNode(2);
    ListNode* node13 = new ListNode(4);

    ListNode* node21 = new ListNode(1);
    ListNode* node22 = new ListNode(3);
    ListNode* node23 = new ListNode(4);

    node11 -> next = node12;
    node12 -> next = node13;

    node21 -> next = node22;
    node22 -> next = node23;

    Solution s;
    ListNode* res;
//    res = s.mergeTwoLists(node11, node21);  // 迭代
    res = s.mergeTwoListsRecursion(node11, node21);  // 递归
    while (res){
        cout << res->val << ' ';
        res = res->next;
    }

}