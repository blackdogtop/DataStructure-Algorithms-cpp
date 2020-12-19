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
         *      time: O(2n)
         *      space: O(n)
         *      */
        vector<int> stack;
        ListNode* currentNode = head;
        while (currentNode){
            stack.push_back(currentNode->val);
            currentNode = currentNode->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while (!stack.empty()){
            p->next = new ListNode(stack.back());
            stack.pop_back();
            p = p->next;
        }
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
};


int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);

    node1 -> next = node2;
    node2 -> next = node3;

    Solution s;
    ListNode* res;
    res = s.reverseList(node1);
    while(res){
        cout << res->val << ' ';
        res = res->next;
    }

    cout << endl;

    ListNode* res2;
    res2 = s.reverseList2(node1);
    while(res2){
        cout << res2->val << ' ';
        res2 = res2->next;
    }
}

