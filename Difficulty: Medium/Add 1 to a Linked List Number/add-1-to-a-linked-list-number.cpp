/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node *head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        head = reverse(head);
        Node *temp = head;
        Node *prev = NULL;
        int carry = 1;
        while(temp != NULL){
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;
            prev = temp;
            temp = temp->next;
        }
        if(carry > 0){
            prev->next = new Node(carry);
        }
        
        head = reverse(head);
        return head;
    }
};