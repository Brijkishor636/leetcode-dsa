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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = headA;
        set<ListNode*> s;
        while(temp != NULL){
            s.insert(temp);
            temp = temp->next;
        }
        ListNode *temp2 = headB;
        while(temp2 != NULL){
            if(s.find(temp2)!=s.end()){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};