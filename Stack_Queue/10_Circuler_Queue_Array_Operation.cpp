#include <iostream>
#include <string>
using namespace std;

// Create Circuler Queue with limited size
class CirculerQueue {
    public:
    int size;
    int front;
    int rear;
    int* arr = new int[size];

    CirculerQueue(int s) {
        size = s;
        front = rear = -1;
    }
};

// Ckeck whether the Queue is empty or not
bool isEmpty(CirculerQueue* q_ptr) {

    // When the value of both rear and front are -1 then Queue will be empty
    if(q_ptr ->front == -1 && q_ptr ->rear == -1)
        return true;
    else
        return false;
}

// Ckeck whether the Queue is full or not
bool isFull(CirculerQueue* q_ptr) {

    // When the value of rear + 1 become the value of front then Queue will be full
    if((q_ptr ->rear + 1)%q_ptr ->size == q_ptr ->front)
        return true;
    else
        return false;
}

// To add element in the Queue
void enqueue(CirculerQueue* q_ptr, int value) {

    /*
    If Queue is full then element cannot be added
    If Queue is empty then start inserting elements from position 0
    and point front and rear at initial element
    And then increase the rear and add elements
    */
    if(isFull(q_ptr))
        cout <<"Queue if full!! Cannot add " <<value <<" in the Queue!" <<endl;
    else if(isEmpty(q_ptr)) {
        q_ptr ->front = 0;
        q_ptr ->rear = 0;
        q_ptr ->arr[q_ptr ->rear] = value;
    } 
    else {
        q_ptr ->rear = (q_ptr ->rear + 1) % q_ptr ->size;
        q_ptr ->arr[q_ptr ->rear] = value;
    }
}

// To remove the element from the Queue
int dequeue(CirculerQueue* q_ptr) {

    /*
    If Queue is empty then element cannot be removed
    If the value of front and rear become same(not -1)
    i.e. Queue is also empty then restart Queue from the beginging.
    And then increase the front and remove elements
    */
    int dequeueValue = -1;

    if(isEmpty(q_ptr)) {
        cout <<"Queue is Empty!! Cannot remove from the Queue!" <<endl;
    }
    else if(q_ptr ->rear == q_ptr ->front) {
        dequeueValue = q_ptr ->arr[q_ptr ->front];
        q_ptr ->front = -1;
        q_ptr ->rear = -1;
    }
    else {
        dequeueValue = q_ptr ->arr[q_ptr ->front];
        q_ptr ->front = (q_ptr ->front + 1) % q_ptr ->size;        
    }
    return dequeueValue;
}

void display(CirculerQueue* q_ptr) {
    for (int i = 0; i <= q_ptr ->rear; i++)
    {
        cout <<q_ptr ->arr[i] <<" ";
    }
    cout <<endl;    
}

// Main Function
int main() {
    CirculerQueue* qp = new CirculerQueue(5);   // Queue pointer to access Queue from the memory

    enqueue(qp, 5);
    enqueue(qp, 7);
    enqueue(qp, 8);
    enqueue(qp, 4);
    enqueue(qp, 1);    // Queue became full

    display(qp);

    (isFull(qp)) ? cout <<"Full!" <<endl : cout <<"Not Full!" <<endl;
    (isEmpty(qp)) ? cout <<"Empty!" <<endl : cout <<"Not Empty!" <<endl;

    cout <<"Remeved Element: " <<dequeue(qp) <<endl;
    cout <<"Remeved Element: " <<dequeue(qp) <<endl;
    cout <<"Remeved Element: " <<dequeue(qp) <<endl;
    cout <<"Remeved Element: " <<dequeue(qp) <<endl;
    cout <<"Remeved Element: " <<dequeue(qp) <<endl;    // Queue became empty

    (isFull(qp)) ? cout <<"Full!" <<endl : cout <<"Not Full!" <<endl;
    (isEmpty(qp)) ? cout <<"Empty!" <<endl : cout <<"Not Empty!" <<endl;
    display(qp);

    enqueue(qp, 100);
    display(qp);

    (isFull(qp)) ? cout <<"Full!" <<endl : cout <<"Not Full!" <<endl;
    (isEmpty(qp)) ? cout <<"Empty!" <<endl : cout <<"Not Empty!" <<endl;

    return 0;
}