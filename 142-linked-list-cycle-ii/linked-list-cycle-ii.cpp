/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp = head;
        set<ListNode*>s;
        while(temp != NULL){
            if(s.find(temp) != s.end()){
                return temp;
            }
            s.insert(temp);
            temp = temp->next;
        }
        return NULL;
    }
};