#include <iostream>
#include <string>
using namespace std;

// Create Queue with limited size
class Queue {
    public:
    int size;
    int front;
    int rear;
    int* arr = new int[size];

    Queue(int s) {
        size = s;
        front = rear = -1;
    }
};

// Ckeck whether the Queue is full or not
bool isFull(Queue* q_ptr) {

    // When the value of rear become size then the Queue will be full 
    if(q_ptr ->rear == q_ptr ->size-1)
        return true;
    else
        return false;
}

// Ckeck whether the Queue is empty or not
bool isEmpty(Queue* q_ptr) {

    // When the value of both front and rear become same then the Queue will be empty  
    if(q_ptr ->front == q_ptr ->rear) 
        return true;
    else
        return false;
}

// To add element in the Queue
void enqueue(Queue* q_ptr, int value) {

    // Increase rear and add element
    if(isFull(q_ptr))
        cout <<"Queue is Full!! Cannot add " <<value <<" in the Queue!" <<endl;
    else {
        q_ptr ->rear ++;
        q_ptr ->arr[q_ptr ->rear] = value;
    }
}

// To remove the element from the Queue
int dequeue(Queue* q_ptr) {

    // Increase front and remove element
    if(isEmpty(q_ptr)) {
        cout <<"Queue is Empty!! Cannot remove anything from the Queue!" <<endl;
        return -1;
    }
    else {
        q_ptr ->front ++;
        return q_ptr ->arr[q_ptr ->front]; 
    }
}

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

    (isFull(qp)) ? cout <<"Full!" <<endl : cout <<"Not Full!" <<endl;
    (isEmpty(qp)) ? cout <<"Empty!" <<endl : cout <<"Not Empty!" <<endl;

    enqueue(qp, 4);
    enqueue(qp, 7);
    enqueue(qp, 9);
    enqueue(qp, 5);
    enqueue(qp, 10);
    // enqueue(qp, 15);

    display(qp);

    (isFull(qp)) ? cout <<"Full!" <<endl : cout <<"Not Full!" <<endl;
    (isEmpty(qp)) ? cout <<"Empty!" <<endl : cout <<"Not Empty!" <<endl;

    cout <<"Dequeue Element: " <<dequeue(qp) <<endl;
    cout <<"Dequeue Element: " <<dequeue(qp) <<endl;
    cout <<"Dequeue Element: " <<dequeue(qp) <<endl;
    cout <<"Dequeue Element: " <<dequeue(qp) <<endl;
    cout <<"Dequeue Element: " <<dequeue(qp) <<endl;

    (isFull(qp)) ? cout <<"Full!" <<endl : cout <<"Not Full!" <<endl;
    (isEmpty(qp)) ? cout <<"Empty!" <<endl : cout <<"Not Empty!" <<endl;

    return 0;
}