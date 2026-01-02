class myQueue {

  public:
    int *nums;
    int rear;
    int front;
    int size;
    myQueue(int n) {
        // Define Data Structures
        nums = new int[n];
        size = n;
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(front == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        // check if the queue is full
        if((rear+1)%size == front)
            return true;
        else 
            return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(rear == size-1)
            return;
        else if(rear == -1){
            rear++;
            front++;
            nums[rear] = x;
        }
        else{
            rear++;
            nums[rear] = x;
        }
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(front == rear){
            rear = -1;
            front = -1;
        }
        else 
        front = (front+1)%size;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(front == -1)
            return -1;
        return nums[front];
    }

    int getRear() {
        // Return the last element of queue
        if(rear == -1)
            return -1;
        return nums[rear];
    }
};