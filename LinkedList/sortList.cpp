#include <iostream>
using namespace std;
/* https://leetcode-cn.com/problems/sort-list/
 *
 * 148. 排序链表
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序
 *
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 * 输入：head = []
 * 输出：[]
 * */


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        /* 递归
         * Complexity:
         *      time: O(NlogN)
         *      space: O(logN)
         *      */
        if(!head || !head->next) {return head;}

        ListNode* low = head;
        ListNode* high = head->next;
        while(high && high->next){
            low = low->next;
            high = high->next->next;
        }
        ListNode* mid = low->next;
        low->next = nullptr;  // 分隔

        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        while(left && right){
            if(left->val < right->val){
                res->next = left;
                left = left->next;
            }
            else{
                res->next = right;
                right = right->next;
            }
            res = res->next;
        }
        if (left){
            res->next = left;
        }
        else{
            res->next = right;
        }
        return dummy->next;
    }

    ListNode* sortListIteration(ListNode* head) {
        /* 迭代
         * Complexity:
         *      time: O(NlogN)
         *      space: O(1)
         *      */
        if(!head){return head;}
        int length = 0;
        ListNode* h = head;
        while(h){
            length ++;
            h = h->next;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        res->next = head;

        int step = 1;
        while (step < length){
            ListNode* cur = res->next;
            while(cur){
                ListNode* h1 = cur;
                ListNode* h2 = getHead(h1, step);
                cur = getHead(h2, step);
                mergeSort(h1, h2, res);
            }
            res = dummy;
            step = step * 2;
        }
        return dummy->next;
    }

    ListNode* getHead(ListNode* node, int step){
        if(!node){return nullptr;}
        for(int i = 1; i < step; i++){
            if(node && node->next){
                node = node->next;
            }
        }
        ListNode* right = node->next;
        node->next = nullptr;
        return right;
    }

    void mergeSort(ListNode* h1, ListNode* h2, ListNode* &res){
        while(h1 && h2){
            if(h1->val < h2->val){
                res->next = h1;
                h1 = h1->next;
            }
            else{
                res->next = h2;
                h2 = h2->next;
            }
            res = res->next;
        }
        if(h1){
            res->next = h1;
        }
        else{
            res->next = h2;
        }
        while (res->next){res = res->next;}
    }
};


int main(){
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);

    node1->next = node2;
    node2->next = node3;

    Solution s;
    ListNode* res;
//    res = s.sortList(node1);  // 迭代
    res = s.sortListIteration(node1);  // 递归
    while(res){
        cout << res->val << ' ';
        res = res->next;
    }
}