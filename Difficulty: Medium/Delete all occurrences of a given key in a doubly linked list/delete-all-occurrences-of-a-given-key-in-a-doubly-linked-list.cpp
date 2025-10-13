// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        struct Node *temp = *head_ref;
        while(temp != NULL){
            if(temp->data == x && temp == *head_ref){
                struct Node *t = temp;
                temp = temp->next;
                if (temp != NULL)
                    temp->prev = NULL;
                *head_ref = temp;
                delete t;
            }
            else if(temp->data == x){
                struct Node *t = temp;
                temp = temp->next;
                 if (t->prev != NULL)
                    t->prev->next = temp;
                if (temp != NULL)
                    temp->prev = t->prev;
                delete t;
            }
            else{
                temp = temp->next;
            }
        }
    }
};