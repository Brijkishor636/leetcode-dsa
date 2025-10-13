/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        if(!head || !head->next){
            return head;
        }
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        
        Node *zero = zeroHead;
        Node *one = oneHead;
        Node *two = twoHead;
        Node *curr = head;
        
        while(curr != NULL){
            if(curr->data == 0){
                zero->next = new Node(0);
                zero = zero->next;
            }
            else if(curr->data == 1){
                one->next = new Node(1);
                one = one->next;
            }
            else if(curr->data == 2){
                two->next = new Node(2);
                two = two->next;
            }
            curr = curr->next;
        }
        zero->next = (oneHead->next) ? (oneHead->next) : twoHead->next;
        one->next = twoHead->next;
        
        Node *sortedHead = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return sortedHead;
    }
};