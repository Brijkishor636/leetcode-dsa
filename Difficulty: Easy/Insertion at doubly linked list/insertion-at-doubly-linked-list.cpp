/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        Node *newnode = new Node(x);
        if (!head) {
            if (p == 0) return newnode;
            return head;
        }
        
        Node *temp = head;
        if (p == 0) {
            newnode->next = temp->next;
            newnode->next->prev = newnode;
            newnode->prev = temp;
            temp->next = newnode;
            return head;
        }
        while(p > 0){
            if(temp->next)
                temp = temp->next;
            p--;
        }
        if(temp->next == NULL){
            temp->next = newnode;
            newnode->prev = temp;
        }
        else{
            newnode->next = temp->next;
            newnode->next->prev = newnode;
            newnode->prev = temp;
            temp->next = newnode;
        }
        return head;
    }
};