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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next){
            return NULL;
        }
        ListNode *temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        temp = head;
        int k = count - n;
        if(k == 0){
            head = head->next;
            delete temp;
            return head;
        }
        while(k > 1){
            temp = temp->next;
            k--;
        }
        ListNode *del = temp->next;
        temp->next = del->next;
        delete del;
        return head;
    }
};