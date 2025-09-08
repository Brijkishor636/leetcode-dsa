/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node*temp = new Node(x);
        if(head == NULL){
            head = temp;
            return head;
        }
        Node*t = head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = temp;
        return head;
    }
};