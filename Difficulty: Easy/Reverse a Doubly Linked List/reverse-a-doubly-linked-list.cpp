/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if(head->next == NULL){
            return head;
        }
        Node *prev = NULL;
        Node *temp = head;
        while(temp != NULL){
            prev = temp->prev;
            temp->prev = temp->next;
            temp->next = prev;
            temp = temp->prev;
        }
        return prev->prev;
    }
};