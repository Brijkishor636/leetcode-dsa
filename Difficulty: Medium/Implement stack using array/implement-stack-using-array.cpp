class myStack {
  public:
    int *arr;
    int top;
    int size;
    myStack(int n) {
        arr = new int[n];
        top = -1;
        size = n;
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull() {
        // check if the stack is full
        if(top == size-1){
            return true;
        }
        else
            return false;
    }

    void push(int x) {
        if(top == size-1){
            return ;
        }
        else{
            top++;
            arr[top] = x;
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(top == -1)
            return;
        top--;
    }

    int peek() {
        // Returns the top element of the stack
        if(top == -1){
            return -1;
        }
        return arr[top];
    }
};