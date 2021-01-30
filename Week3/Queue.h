#pragma once
#include "Employee.h"
#include <iostream>

// queue class
class Queue
{

private:

    struct node{

        // each node will include an employee object for data
        Employee employee;
        // pointer to point to the next node
        node* next;

        node(Employee e) {
            employee = e;
            next = NULL;
        }
    };

    // head and tail pointers
    node *front, *back;

public:

    // Default Constructor
    Queue();

    // class methods that can be accessed outside the scope of the class
    void enQueue(Employee e);
    void deQueue();
    bool isEmpty();
    void count();
    void display();
    void showFront();
};

