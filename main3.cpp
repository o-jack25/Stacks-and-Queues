#include <iostream>
#include <string>
#define STACK_SIZE 9


using namespace std;


// Node structure for the linked list
struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to insert an element into the queue (enqueue)
    void enQueue(string item) {
        Node* newNode = new Node; // Allocate memory for the new node
        newNode->data = item;
        newNode->next = nullptr;

        // If queue is empty, set both front and rear to the new node
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode; // Link the new node to the rear
            rear = newNode;       // Update rear to the new node
        }
    }

    // Function to remove an element from the queue (dequeue)
    string deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return "";
        }

        Node* temp = front; // Temporary pointer to the front node
        string dequeuedItem = temp->data;

        if (front == rear) {
            // If only one element in the queue, set both front and rear to nullptr
            front = rear = nullptr;
        }
        else {
            front = front->next; // Move front to the next node
        }

        delete temp; // Free memory of the dequeued node
        return dequeuedItem;
    }

    // Destructor to free memory of all nodes in the queue
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue queue;

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