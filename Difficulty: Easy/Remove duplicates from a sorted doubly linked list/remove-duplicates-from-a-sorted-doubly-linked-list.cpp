/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        Node *temp = head;
        while(temp != NULL && temp->next != NULL){
            if(temp->data == temp->next->data){
                Node *t = temp->next;
                while(t != NULL && t->data == temp->data){
                    Node *del = t;
                    t = t->next;
                    delete del;
                }
                temp->next = t;
                if(t != NULL)
                    t->prev = temp;
            }
            else
                temp = temp->next;
        }
        return head;
    }
};