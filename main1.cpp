#include <iostream>
#include <string>



//define stack size(provided in instructions)
#define STACK_SIZE 9

/*
For following questions make stack size as per instructions (9) 
*/


using namespace std;

// Node class to represent each element in the stack
class Node {
public:
    string data;  // Data stored in the node
    Node* next;   // Pointer to the next node

    // Constructor to initialize node with given data
    Node(string value) : data(value), next(nullptr) {}
};

// Stack class using linked list implementation
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack() : top(nullptr) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(string value) {
        // Create a new node with the given value
        Node* newNode = new Node(value);
        // Set the next pointer of the new node to the current top of the stack
        newNode->next = top;
        // Update the top pointer to point to the new node
        top = newNode;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            // If stack is empty, print an error message and return
            cout << "Stack Underflow" << endl;
            return;
        }
        // Store the current top of the stack in a temporary variable
        Node* temp = top;
        // Move the top pointer to the next node in the stack
        top = top->next;
        // Print the popped item
        cout << "Popped item: " << temp->data << endl;
        // Deallocate memory for the popped node
        delete temp;
    }

    // Function to peek at the top element of the stack without removing it
    string peek() {
        if (isEmpty()) {
            // If stack is empty, print an error message and return an empty string
            cout << "Stack is empty" << endl;
            return "";
        }
        // Return the data of the top node
        return top->data;
    }

    // Function to display all elements of the stack
    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            // Traverse the stack and print each element
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to deallocate memory for all nodes in the stack
    ~Stack() {
        while (!isEmpty()) {
            // Pop elements until the stack is empty
            pop();
        }
    }
};

// Main function to demonstrate the stack operations
int main() {
    // Create a stack object
    Stack stack;

    // Insert items individually into the stack
    stack.push("Volleyball");
    stack.push("Football");
    stack.push("Baseball");
    stack.push("Kitten");
    stack.push("Puppy");
    stack.push("Wolverine");
    stack.push("Book");
    stack.push("Keyboard");
    stack.push("CPU");

    // Display the stack after initial insertions
    cout << "Stack after initial insertions: " << endl;
    stack.display();
    cout << endl;

    // Remove three items from the stack
    cout << "Removing three items from the stack: " << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    cout << endl;

    // Display the stack after removal
    cout << "Stack after removal: " << endl;
    stack.display();
    cout << endl;

    // Insert additional items into the stack
    stack.push("UMich");
    stack.push("Dearborn");
    stack.push("Rocks!");

    // Display the stack after additional insertions
    cout << "Stack after additional insertions: " << endl;
    stack.display();
    cout << endl;

    // Remove and print items from the stack until it is empty
    cout << "Stack will be emptied automatically by the destructor" << endl;

    return 0;
}

