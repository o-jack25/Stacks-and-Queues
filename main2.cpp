#include <iostream>
#include <string>


#define STACK_SIZE 9

using namespace std;



class CircularQueue {
private:
    string items[STACK_SIZE]; // Array to store queue elements
    int front, rear; // Pointers to track front and rear of the queue

public:
    CircularQueue() : front(-1), rear(-1) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % STACK_SIZE == front;
    }

    // Function to insert an element into the queue (enqueue)
    void enQueue(string item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // If queue is empty, set both front and rear to 0
        }
        else {
            rear = (rear + 1) % STACK_SIZE; // Move rear circularly
        }
        items[rear] = item;
    }


    // Function to remove an element from the queue (dequeue)
    string deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return "";
        }
        string dequeuedItem = items[front];
        if (front == rear) {
            // If only one element in the queue, reset front and rear
            front = rear = -1;
        }
        else {
            front = (front + 1) % STACK_SIZE; // Move front circularly
        }
        return dequeuedItem;
    }
};

int main() {
    CircularQueue queue;

    // Insert items to the queue
    queue.enQueue("Volleyball");
    queue.enQueue("Football");
    queue.enQueue("Baseball");
    queue.enQueue("Kitten");
    queue.enQueue("Puppy");

    // Remove and print two items from the queue
    cout << "Removed: " << queue.deQueue() << endl;
    cout << "Removed: " << queue.deQueue() << endl;

    // Insert individual words to the queue
    queue.enQueue("UMich");
    queue.enQueue("Dearborn");
    queue.enQueue("Rocks!");

    // Remove and print items until the queue is empty
    while (!queue.isEmpty()) {
        cout << "Removed: " << queue.deQueue() << endl;
    }
    cout << "Queue is empty." << endl;

    // Insert items to the queue again
    queue.enQueue("Apple");
    queue.enQueue("Peaches");
    queue.enQueue("Pumpkin Pie");

    // Remove and print items until the queue is empty
    while (!queue.isEmpty()) {
        cout << "Removed: " << queue.deQueue() << endl;
    }
    cout << "Queue is empty." << endl;

    return 0;
}
