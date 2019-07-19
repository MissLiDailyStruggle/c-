typedef struct {
    int *_cycle_array;
	int _front;
	int _rear;
    int _len;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *m = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    m -> _cycle_array = (int *)malloc(sizeof(int)*(k+1));
    m -> _rear = m -> _front = 0;
    m -> _len = k+1;
    return m;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    if(myCircularQueueIsFull(obj))
      return false;
    obj -> _cycle_array[obj -> _rear] = value;
    obj -> _rear ++;
    if(obj -> _rear == obj ->_len)
        obj ->_rear = 0;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
   if(myCircularQueueIsEmpty(obj))
      return false;
    obj -> _front ++;
    if(obj -> _front == obj ->_len)
        obj -> _front = 0;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
  assert(obj);
  if(myCircularQueueIsEmpty(obj))
      return -1;
  else 
      return obj -> _cycle_array[obj -> _front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
  assert(obj);
  if(myCircularQueueIsEmpty(obj))
      return -1;
  else 
  {
      int rear = obj -> _rear;
      if(rear == 0)
          rear = obj -> _len - 1;
      else
          --rear;
   return obj -> _cycle_array[rear];       
  }
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  if(obj -> _front == obj -> _rear)
      return true;
    else 
        return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  
    if((obj -> _rear+1) % (obj -> _len) == obj ->_front)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj -> _cycle_array);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
