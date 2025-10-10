/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        Node *temp = head;
        if(!head){
            return NULL;
        }
        if(x == 1){
            head = head->next;
            head->prev = NULL;
            delete temp;
            return head;
        }
        while(x > 2){
            temp = temp->next;
            x--;
        }
        Node *t = temp->next;
        if(t->next == NULL){
            temp->next = NULL;
            delete t;
        }
        else{
            temp->next = t->next;
            t->next->prev = temp;
            delete t;
        }
        return head;
    }
};