/*
Name: Kashvi Goyal  
Class: SE Comp 2 
Roll no: 15 
*/

//PROBLEM STATEMENT: E31

/*
A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end.
Obtain a data representation mapping a deque into a one- dimensional array. Write C++ program to simulate deque with functions to 
add and delete elements from either end of the deque.
*/

#include <iostream> 
using namespace std; 
class Deque { 
    private: 
        int* arr; // Dynamic array to hold deque elements 
        int front;  // Index of the front element 
        int rear; // Index of the rear element 
        int capacity;  // Maximum size of the deque 
        int size; // Current size of the deque 
    public: // Constructor to initialize the deque 
        Deque(int cap) { 
        capacity = cap; 
        arr = new int[capacity]; 
        front = -1; 
        rear = -1; 
        size = 0; 
        } 
        // Destructor to clean up the dynamic array 
        ~Deque() { 
        delete[] arr; 
        } 
        // Function to check if the deque is empty 
        bool isEmpty() { 
            return size == 0; 
        } 
        // Function to check if the deque is full 
        bool isFull() { 
        return size == capacity; 
        } 
        // Function to add an element at the front 
        void addFront(int value) { 
            if (isFull()) { 
                cout << "Deque is full. Cannot add " << value << " at the front." << endl; 
                return; 
            } 
            if (isEmpty()) { 
                front = rear = 0; // First element 
            } 
            else { 
                front = (front - 1 + capacity) % capacity; // Circular decrement 
            } 
            arr[front] = value; 
            size++; 
        } 
        // Function to add an element at the rear 
        void addRear(int value) { 
            if (isFull()) { 
                cout << "Deque is full. Cannot add " << value << " at the rear." << endl; 
                return; 
            } 
            if (isEmpty()) { 
                front = rear = 0; // First element 
            }
            else { 
                rear = (rear + 1) % capacity; // Circular increment 
            } 
            arr[rear] = value; 
            size++; 
        } 
        // Function to delete an element from the front 
        void deleteFront() { 
            if (isEmpty()) { 
                cout << "Deque is empty. Cannot delete from the front." << endl; 
                return; 
            } 
            cout << "Deleted from front: " << arr[front] << endl; 
            if (front == rear) { // Only one element was in deque 
                front = rear = -1; 
            } 
            else { 
                front = (front + 1) % capacity; // Circular increment 
            } 
            size--; 
        } 
        // Function to delete an element from the rear 
        void deleteRear() { 
            if (isEmpty()) { 
                cout << "Deque is empty. Cannot delete from the rear." << endl; 
                return; 
            } 
            cout << "Deleted from rear: " << arr[rear] << endl; 
            if (front == rear) { // Only one element was in deque 
                front = rear = -1; 
            } 
            else { 
                rear = (rear - 1 + capacity) % capacity; // Circular decrement 
            } 
            size--;
        } 
        
 
        // Function to display the elements in the deque 
        void display() { 
            if (isEmpty()) { 
                cout << "Deque is empty." << endl; 
                return; 
            } 
            cout << "Deque elements: "; 
            int i = front; 
            while (i != rear) { 
                cout << arr[i] << " "; 
                i = (i + 1) % capacity; 
            } 
            cout << arr[rear] << endl; // Print the last element 
        } 
}; 

int main() { 
    Deque dq(5); // Create a deque of capacity 5 
    dq.addRear(10); 
    dq.addRear(20); 
    dq.addFront(30); 
    dq.display(); 
    dq.deleteFront(); 
    dq.display(); 
    dq.addFront(40); 
    dq.deleteRear(); 
    dq.display(); 
    return 0;
}