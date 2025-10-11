// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        set<int>s;
        Node *temp = head;
        vector<pair<int, int>>v;
        while(temp != NULL){
            int x = target-temp->data;
            if(s.find(x) != s.end()){
                v.push_back({x, temp->data});
            }
            else{
                s.insert(temp->data);
            }
            temp = temp->next;
        }
        sort(v.begin(), v.end());
        return v;
    }
};