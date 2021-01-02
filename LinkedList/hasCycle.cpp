#include <iostream>
#include <unordered_set>
using namespace std;
/* https://leetcode-cn.com/problems/linked-list-cycle/
 *
 * 141. 环形链表
 * 给定一个链表，判断链表中是否有环。
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
 * 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
 *
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第二个节点。*/


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        /* Complexity:
         *      time: O(N) ?
         *      space: O(N)
         *      */
        unordered_set <ListNode*> seen;
        while(head){
            if (seen.count(head)){return true;}
            seen.insert(head);
            head = head->next;
        }
        return false;
    }

    bool hasCycleReverse(ListNode *head) {
        /* 逆序法 - 从头节点开始逆序链表中所有节点 当p2节点==头节点时 则回到了头节点 说明链表有环
         * Complexity:
         *      time: O(N)
         *      space: O(1)*/
        if(!head || !head->next){return false;}
        ListNode *p1, *p2;
        p1 = nullptr;
        p2 = head;
        while(p2){
            ListNode* p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;

            if(p2 == head){return true;}
        }
        return false;
    }

    bool hasCycleTwoPtrs(ListNode *head){
        /* 快慢双指针
         * Complexity:
         *      time: O(N)
         *      space: O(1)*/
        if(!head){return false;}
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            if(fast == slow){return true;}
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);

    node1->next = node2;
    node2->next = node1;

    Solution s;
    bool res;
//    res = s.hasCycle(node1);  // 哈希方法
//    res = s.hasCycleReverse(node1);  // reverse方法
    res = s.hasCycleTwoPtrs(node1);  // 快慢指针法
    cout << res << endl;
}