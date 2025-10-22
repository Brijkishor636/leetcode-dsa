/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *temp = head;
        ListNode *twoHead = head->next;
        ListNode *q = twoHead;

        while(q && q->next){
            temp->next = q->next;
            temp = q->next;
            q->next = temp->next;
            q = q->next;
        }
        temp->next = twoHead;
        return head;
    }
};