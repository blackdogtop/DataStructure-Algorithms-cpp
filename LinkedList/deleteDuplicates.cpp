#include <iostream>
#include <map>
using namespace std;

/*
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 *
 * 83. 删除排序链表中的重复元素
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 *
 * 输入: 1->1->2
 * 输出: 1->2
 * */


//Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        /* 指针 in-place
         * Complexity:
         *      time: O(n)
         *      space: O(1)
         *      */
        ListNode* currentNode = head;
        while(currentNode != NULL && currentNode->next != NULL){
            if(currentNode->val == currentNode->next->val){
                currentNode->next = currentNode->next->next;
            }
            else{
                currentNode = currentNode->next;
            }
        }
        return head;
    }

    ListNode* deleteDuplicatesTwoPtrs(ListNode* head){
        /* 双指针
         * Complexity:
         *      time: O(n)
         *      space: O(1)
         *      */
        if (!head || !head->next){return head;}

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur){
            if (pre->val != cur->val){
                pre = pre->next;
                cur = cur->next;
            }
            else{
                while (cur && pre->val == cur->val){
                    cur = cur->next;
                }
                pre->next = cur;
            }
        }
        return dummy->next;
    }

    ListNode* deleteDuplicatesHash(ListNode* head){
        /* Hash
         * Complexity:
         *      time: O(n)
         *      space: O(n)
         *      */
        if(!head){return head;}

        ListNode* p = head;
        map<int, int> hash;
        while (p){
            if (hash.count(p->val) >= 1){
                hash[p->val] ++;
            } else{
                hash[p->val] = 1;
            }
            p = p->next;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        ListNode* cur = head;
        while (cur){
            while (cur && hash[cur->val] > 1){
                cur = cur->next;
                hash[cur->val] --;
            }
            res->next = cur;
            res = res->next;
            if (cur->next){
                cur = cur->next;
            }
            else{
                cur = nullptr;
            }
        }
        return dummy->next;
    }

    ListNode* deleteDuplicatesRecursion(ListNode* head){
        /* 递归
         * Complexity:
         *      time: O(n)
         *      space: O(n)
         *      */
        if (!head || !head->next){return head;}

        ListNode* sub = deleteDuplicatesRecursion(head->next);
        if (head->val == sub->val){
            return sub;
        }
        else{
            head->next = sub;
            return head;
        }
    }
};

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    node1 -> next = node2;
    node2 -> next = node3;

    Solution s;
    ListNode* res;
//    res = s.deleteDuplicates(node1);  // 指针 in-place
//    res = s.deleteDuplicatesTwoPtrs(node1);  // 双指针
//    res = s.deleteDuplicatesHash(node1);  // hash
    res = s.deleteDuplicatesRecursion(node1);  // 递归
    while(res){
        cout << res->val << ' ';
        res = res->next;
    }
}