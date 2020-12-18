#include <iostream>
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
    /*Complexity:
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
};

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(2);
    node1 -> next = node2;
    node2 -> next = node3;

    Solution s;
    ListNode* res = s.deleteDuplicates(node1);
    while(res){
        cout << res->val;
        res = res->next;
    }
}