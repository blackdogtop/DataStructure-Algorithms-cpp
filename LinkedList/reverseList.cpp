#include <iostream>
#include <vector>
using namespace std;
/* https://leetcode-cn.com/problems/reverse-linked-list/
 *
 * 206. 反转链表
 * 反转一个单链表。
 *
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL*/


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /* 进栈方法
         * Complexity:
         *      time: O(n)
         *      space: O(n)
         *      */
        vector<ListNode*> stack;
        ListNode* currentNode = head;
        while (currentNode){
            stack.push_back(currentNode);
            currentNode = currentNode->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while (!stack.empty()){
            p->next = stack.back();
            stack.pop_back();
            p = p->next;
        }
        p->next = nullptr;
        return dummy->next;
    }

    ListNode* reverseList2(ListNode* head){
        /* 双指针方法反转next指针
         * Complexity:
         *      time: O(n)
         *      space: O(1)
         *      */
        if(head == nullptr || head->next == nullptr){return head;}
        ListNode* pos1 = nullptr;
        ListNode* pos2 = head;
        while(pos2){
            ListNode* pos3 = pos2->next;
            pos2->next = pos1;
            pos1 = pos2;
            pos2 = pos3;
        }
        return pos1;
    }

    ListNode* reverseList3(ListNode* head){
        /* 递归
        Complexity:
            time: O(n)
            space: O(n) */
        if(!head || !head->next) {return head;}
        if(!head->next) {return head;}
        ListNode* last = reverseList3(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};


int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);

    node1 -> next = node2;
    node2 -> next = node3;

    Solution s;
    ListNode* res;
    res = s.reverseList(node1);  // 进栈
    // res = s.reverseList2(node1);  // 双指针
    // res = s.reverseList3(node1);  // 递归
    while(res){
        cout << res->val << ' ';
        res = res->next;
    }
}

