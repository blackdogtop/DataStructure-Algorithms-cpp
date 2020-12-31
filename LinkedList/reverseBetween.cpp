#include <iostream>
using namespace std;
/* https://leetcode-cn.com/problems/reverse-linked-list-ii/
 * 92. 反转链表 II
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 *
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL*/


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        /* 递归 + 递归反转前N
         * Complexity:
         *      time: O(n) - n is param
         *      space: O(n) - n is param
         *      */
        if(m == 1){
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, --m, --n);
        return head;
    }

    ListNode* reverseN(ListNode* head, int n){
        /* 反转链表前n个节点
         * Complexity:
         *      time: O(n)
         *      space: O(n)
         *      */
        if (n == 1){
            successor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, --n);
        head->next->next = head;
        head->next = successor;
        return last;
    }

    ListNode* reverseIter(ListNode* head, int n){
        /* 反转链表前n个节点
         * Complexity:
         *      time: O(n)
         *      space: O(1)
         *      */
        if (!head || !head->next){return head;}

        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        pre->next = head;
        ListNode* cur = head;

        for (int i=1; i<n; i++){
            ListNode* nex = cur->next;

            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return dummy->next;
    }

    ListNode* reverseBetweenIter(ListNode* head, int m, int n) {
        /* 递归 + 迭代链表前N
         * Complexity:
         *      time: O(n) - n为参数
         *      space: O(m) - m为参数
         *      */
        if (m == 1){
            return reverseIter(head, n);
        }
        head->next = reverseBetweenIter(head->next, m-1, n-1);
        return head;
    }

private:
    ListNode* successor = nullptr;
};


int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution s;
//    ListNode* res = s.reverseBetween(node1, 3,4);  // 递归 + 递归反转前N
    ListNode* res = s.reverseBetweenIter(node1, 2, 4);  // 递归 + 迭代反转前N
    while(res){
        cout << res->val << ' ';
        res = res->next;
    }
}