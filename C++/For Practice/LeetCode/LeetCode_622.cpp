// Design Circular Queue

#include <iostream>

using namespace std;

class MyCircularQueue {
private:
    int* cqueue;
    int f, r;
    int size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k + 1;
        cqueue = new int[k+1];  // 多开一个空间，处理队列空和满两种情况
        f = 0;
        r = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(this->isFull())
            return false;
        else{
            cqueue[r] = value;    // 原来r所指为空，所以先赋值
            r = (r+1) % size;
            return true;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(this->isEmpty())
            return false;
        else{
            f = (f+1) % size;
            return true;
        }
    }

    /** Get the front item from the queue. */
    int Front() {
        if(this->isEmpty())
            return -1;
        else
            return cqueue[f];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(this->isEmpty())
            return -1;
        if(r == 0)
            return cqueue[size-1];
        else
            return cqueue[r-1];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return f == r;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (r+1-f) % size == 0;  //空一个位置
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

int main(){
    MyCircularQueue* obj = new MyCircularQueue(5);
    bool param_1 = obj->enQueue(6);
    bool param_2 = obj->isEmpty();
    bool param_3 = obj->enQueue(1);
    bool param_4 = obj->enQueue(2);
    int param_5 = obj->Rear();
    bool param_6 = obj->enQueue(7);
    bool param_7 = obj->enQueue(7);
    bool param_8 = obj->Rear();
    bool param_9 = obj->Rear();
    bool param_10 = obj->deQueue();
    bool param_11 = obj->enQueue(5);

    return 0;
}
