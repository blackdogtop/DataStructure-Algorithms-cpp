#include <iostream>
using namespace std;
/* https://leetcode-cn.com/problems/partition-list/
 *
 * 86. 分隔链表
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 你应当保留两个分区中每个节点的初始相对位置。
 *
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5*/


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        /* Complexity:
         *      time: O(n)
         *      space: O(1)
         *      */
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* a = dummy1;
        ListNode* b = dummy2;
        ListNode* c = head;

        while (c){
            if(c->val < x){
                a->next = c;
                a = a->next;
            }
            else{
                b->next = c;
                b = b->next;
            }
            c = c->next;
        }
        b->next = nullptr;
        a->next = dummy2->next;
        return dummy1->next;
    }
};

