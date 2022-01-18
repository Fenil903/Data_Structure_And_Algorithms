#include <iostream>
#include <string>
using namespace std;

// Create Queue with limited size
class Queue {
    public:
    int size;   // Size of Queue
    int front;  // Point first element of Queue
    int rear;   // Pint last element of Queue
    int* arr = new int(size);   // Create a Queue using array dynamically

    Queue(int s) {
        size = s;
        front = rear = -1;
    }
};

void display(Queue* q_ptr) {
    for (int i = 0; i <= q_ptr ->rear; i++)
    {
        cout <<q_ptr ->arr[i] <<" ";
    }
    cout <<endl;
}

// Main Function
int main() {
    Queue* qp = new Queue(5);   // Queue pointer to accsss Queue from the memory

    qp ->arr[0] = 4;
    qp ->rear ++;
    qp ->arr[1] = 9;
    qp ->rear ++;
    qp ->arr[2] = 15;
    qp ->rear ++;

    display(qp);

    return 0;
}