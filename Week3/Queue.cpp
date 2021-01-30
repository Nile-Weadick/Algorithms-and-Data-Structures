#include "Queue.h"

Queue::Queue() {

    // constructor
    front = NULL;
    back = NULL;
}

// enQueue to add employee to stack
void Queue::enQueue(Employee e) {

    // create a temp node of node type
    node* temp = new node(e);

    //deref the emplyee to e
    temp->employee = e;

    //deref the next ptr to null
    temp->next = NULL;

    if (front == NULL) {
        front = temp;
        back = temp;
    }

    else
    {
        back->next = temp;
        back = temp;
    }
}

// method to remove front of queue
void Queue::deQueue() {

    // if head node is empty then no data in queue
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    }

    // if only one node in queue
    else if (front == back) {

        // free memory of node
        free(front);
        front = back = NULL;
    }

    else
    {
        // free the data in front node
        node* temp = front;
        front = front->next;
        free(temp);
    }

}

// method to see if queue is empty
bool Queue::isEmpty() {

    // if front and back nodes are empty 
    if (front == NULL && back == NULL) {
        return true;
    }

    else
    {
        return false;
    }
}

// get number of employees
void Queue::count() {

    node* current = front;
    int count = 0;

    // if head node is empty then no data in queue
    if (isEmpty() == true) {
        cout << "Queue is empty" << endl;
    }

    else {
        // while current node is not empty
        while (current != NULL) {
            count++;
            current = current->next;
        }
        cout << "Number of employees in the Queue: " << count << endl;
    }
}

// display all employee info to console
void Queue::display() {

    node* current = front;

    //display each employee info in queue to the console
    while (current != NULL) {
        cout << current->employee.Number << " ";
        cout << current->employee.firstName << " ";
        cout << current->employee.lastName << " ";

        cout << current->employee.yearsOfService << endl;

        current = current->next;
    }
}

// method to front in queue
void Queue::showFront() {

    // if head node is empty then no data in queue
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    }

    // out put emplyee object data to console
    else
    {
        cout << front->employee.Number << " ";
        cout << front->employee.firstName << " ";
        cout << front->employee.lastName << " ";
        cout << front->employee.yearsOfService << endl;
    }
}
