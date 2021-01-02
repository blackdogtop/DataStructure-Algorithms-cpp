#include <iostream>
#include <vector>
using namespace std;
/* https://leetcode-cn.com/problems/palindrome-linked-list/
 *
 * 234. 回文链表
 * 请判断一个链表是否为回文链表。
 *
 * 输入: 1->2
 * 输出: false
 * 输入: 1->2->2->1
 * 输出: true*/


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        /* 递归
         * Complexity:
         *      time: O(N)
         *      space: O(N)
         *      */
        if (!head || !head->next){return true;}

        ListNode* lastSec = head;
        while(lastSec->next->next){lastSec = lastSec->next;}  // 倒数第二节点
        ListNode* last = lastSec->next;
        lastSec->next = nullptr;

        if (head->val != last->val){return false;}
        if (! isPalindrome(head->next)){return false;}
        return true;
    }

    bool isPalindromeStack(ListNode* head) {
        /* 栈
         * Complexity:
         *      time: O(N)
         *      space: O(N)
         *      */
        if(!head || !head->next){return true;}
        vector<int> stack;
        while (head){
            stack.push_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = stack.size() - 1; i < j; ++i, --j) {
            if (stack[i] != stack[j]){return false;}
        }
        return true;
    }

    bool isPalindromeTwoptr(ListNode* head) {
        /* 双指针反转前半链表
         * Complexity:
         *      time: O(N)
         *      space: O(1)
         *      */
        if(!head || !head->next){return true;}
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* ptr1 = nullptr;

        while(fast && fast->next){
            fast = fast->next->next;
            ListNode* ptr2 = slow->next;
            slow->next = ptr1;
            ptr1 = slow;
            slow = ptr2;
        }
        ListNode* ptr2 = slow->next;
        slow->next = ptr1;
        ptr1 = slow;

        if(fast == nullptr){ptr1 = ptr1->next;}

        while (ptr1 && ptr2){
            if (ptr1->val != ptr2->val){return false;}
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }

    bool isPalindromeReverse(ListNode* head) {
        /* 中断+反转+判断
         * Complexity:
         *      time: O(N)
         *      space: O(1) */
        if (!head || !head->next){return true;}

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = slow->next;
        slow->next = nullptr;

        ListNode* pre = nullptr;
        while (right){
            ListNode* nex = right->next;
            right->next = pre;
            pre = right;
            right = nex;
        }
        right = pre;

        while (right && head){
            if (right->val != head->val){return false;}
            right = right->next;
            head = head->next;
        }
        return true;
    }
};


int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution s;
    bool res;
//    res = s.isPalindrome(node1);  // 递归
//    res = s.isPalindromeStack(node1); // 栈
//    res = s.isPalindromeTwoptr(node1);  // 双指针
    res = s.isPalindromeReverse(node1);  // 中断+反转+判断
    cout << res << endl;
}