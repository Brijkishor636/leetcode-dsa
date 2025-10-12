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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>num1;
        vector<int>num2;
        vector<int>result;
        while(l1 != NULL){
            num1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            num2.push_back(l2->val);
            l2 = l2->next;
        }
        int max_size = max(num1.size(), num2.size());
        int carry = 0;
        for(int i = 0; i < max_size; i++){
            int digit1 = (i < num1.size())?num1[i] : 0;
            int digit2 = (i < num2.size())?num2[i]: 0;
            int sum = digit1+digit2+carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        if(carry > 0){
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        ListNode *head = new ListNode(result[0]);
        for(int i = 1; i < result.size(); i++){
            ListNode *temp = new ListNode(result[i]);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};
