#include <iostream>
#include <map>
using namespace std;
/*
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 *
 * 82. 删除排序链表中的重复元素 II
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 *
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * */


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        /* Hash
         * Complexity:
         *      time: O(n)
         *      space: O(n)
         *      */
        if(!(head && head->next)) {return head;}
        map <int, int> hash;
        ListNode* currentNode = head;
        while (currentNode){
            if (hash.count(currentNode->val) == 0){
                hash[currentNode->val] = 1;
            }
            else{
                hash[currentNode->val] ++;
            }
            currentNode = currentNode->next;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        map<int, int>::iterator it;
        for(it = hash.begin(); it!=hash.end(); it++){
//            cout << (*it).first << ':' << (*it).second << ' ';
            if((*it).second == 1){
                p->next = new ListNode((*it).first);
                p = p->next;
            }
        }

        return dummy->next;
    }


    ListNode* deleteDuplicates2(ListNode* head) {
        /* 双指针
         * Complexity:
         *      time: O(n)
         *      space: O(1)*/
        if (!(head && head->next)) {return head;}
        ListNode* dummy = new ListNode(-1);
        ListNode* a = dummy;
        a->next = head;
        ListNode* b = head;

        while(b and b->next){
            if(a->next->val != b->next->val){
                a = a->next;
                b = b->next;
            }
            else {
                while(b && b->next && a->next->val == b->next->val){
                    b = b->next;
                }
                a->next = b->next;
                b = b->next;
            }
        }
        return dummy->next;
    }

    ListNode* deleteDuplicatesRecursion(ListNode* head) {
        /* 递归
         * Complexity:
         *      time: O(n)
         *      space: O(n)
         *      */
        if (!head || !head->next){return head;}

        if(head->val == head->next->val){
            while (head->next && head->val == head->next->val){
                head->next = head->next->next;
            }
            ListNode* sub = deleteDuplicatesRecursion(head->next);
            return sub;
        }
        else{
            ListNode* sub = deleteDuplicatesRecursion(head->next);
            head->next = sub;
            return head;
        }
    }
};


int main(){
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(2);

    node1->next = node2;
    node2->next = node3;

    Solution s;
    ListNode* res;
//    res = s.deleteDuplicates(node1);  // hash
//    res = s.deleteDuplicates2(node1);  // 双指针
    res = s.deleteDuplicatesRecursion(node1);  // 递归
    while(res){
        cout << res->val << ' ';
        res = res->next;
    }

}