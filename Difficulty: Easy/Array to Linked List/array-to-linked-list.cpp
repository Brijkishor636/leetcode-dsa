/*
// Representation of a node
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* arrayToList(vector<int>& arr) {
        Node *head = new Node(arr[0]);
        Node *t = head;
        for(int i = 1; i < arr.size(); i++){
            Node *temp = new Node(arr[i]);
            t->next = temp;
            t = t->next;
        }
        return head;
    }
};