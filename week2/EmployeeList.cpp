// EmployeeList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Nile Weadick

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream inFile;

// Employee class containing employee object constructor
class Employee {

public:
    int Number, yearsOfService;
    string firstName, lastName;
};

// node data type for linked list
struct node {

    // each node will include an employee object for data
    Employee employee;
    // pointer to point to the next node
    node* next;
};

// Linked list class 
class LinkedList {

private:
    node *head, *tail;

public:

    // default constrcutor
    LinkedList() {

        head = NULL;
        tail = NULL;
    }

    // add a new node to linked list
    void addNode(Employee e) {

        // create a temp node of node type
        node* temp = new node;

        //deref the emplyee to e
        temp->employee = e;

        //deref the next ptr to null
        temp->next = NULL;

        // if head is emplty it becomes head and tail node
        if (head == NULL) {
            head = temp;
            tail = temp;
        }

        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }

    void removeNodes() {

        // node ptr
        node* current = head;
        node* temp;
        int x;
        bool found = false;

        // ask user to enter emp number
        cout << "Enter number to delete: ";
        cin >> x;

        // if head node is empty then no data in list
        if (current == NULL) {
            cout << "List is empty" << endl;
        }

        else {

            // while current node is not empty
            while (current != NULL) {

                if (current->employee.Number == x){
                    temp = current->next;
                    delete current;
                    current = temp;

                    cout << "Employee: " << x << " has been deleted from list" << endl;
                    found = true;
                }
                // current becomes the next node
                current = current->next;
            }

            // inform user the emp number was not found
            if (found == false) {
                cout << "Employee not found" << endl;
            }
        }
    }

    // get number of employees
    void count() {

        node* current = head;
        int count = 0;

        // if head node is empty then no data in list
        if (current == NULL) {
            cout << "List is empty" << endl;
        }

        else {
            // while current node is not empty
            while (current != NULL) {
                count++;
                current = current->next;
            }
            cout << "Number of employees in the list: " << count << endl;
        }
    }

    // display all employee info to console
    void display() {

        node* current = head;

        // if head node is empty then no data in list
        if (current == NULL){
            cout << "List is empty" << endl;
        }

        else{

            //display each employee info in list to the console
            while (current != NULL){
                cout << current->employee.Number << " ";
                cout << current->employee.firstName << " ";
                cout << current->employee.lastName << " ";
                
                cout << current->employee.yearsOfService << endl;

                current = current->next;
            }
        }
    }
};

// read each line of .txt employtee infile
LinkedList readDataFile() {
    
    // local variables
    string delimeter = "><";
    string num, fName, lName, years;
    string line;

    // employee object
    Employee e;
    LinkedList list;

    // while each line of inFile has data get the whole line
    while (getline(inFile, line)){

        //get text until delimeter is found
        num = line.substr(0, line.find(delimeter));

        // earse what was just substr + delimeter
        line.erase(0, line.find(delimeter) + delimeter.length());

        fName = line.substr(0, line.find(delimeter));
        line.erase(0, line.find(delimeter) + delimeter.length());

        lName = line.substr(0, line.find(delimeter));
        line.erase(0, line.find(delimeter) + delimeter.length());

        years = line.substr(0, line.find(delimeter));
        line.erase(0, line.find(delimeter) + delimeter.length());

        // assign vsriables to employee object
        e.Number
            = stoi(num);
        e.firstName = fName;
        e.lastName = lName;
        e.yearsOfService = stoi(years);

        // add employee object to List
        list.addNode(e);
    }

    return list;
}

// user to add all fields for a employee object 
void userEmployeeAdd(LinkedList l) {

    // local variables
    string choice = "Y";

    int n, y;
    string f, lN;

    Employee e;

    while(choice == "Y") {

        // all input data
        cout << "Enter employee number: ";
        cin >> n;
        cout << endl;
        cout << "Enter employee first name: ";
        cin >> f;
        cout << endl;
        cout << "Enter employee last name: ";
        cin >> lN;
        cout << endl;
        cout << "Enter employee years of service: ";
        cin >> y;
        cout << endl;
        
        // assign all fielsds to new employee object
        e.Number = n;
        e.firstName = f;
        e.lastName = lN;
        e.yearsOfService = y;

        // push object to linked list
        l.addNode(e);

        cout << "Would you like add another employee? (Y/N)\n";
        cin >> choice;
    }
}

int main() {

    // open employee file
    inFile.open("D:\\CC Spring 2021\\Algorithms and Data Structures\\Week2\\EmployeeList\\Employees.txt");

    if (inFile.is_open()) {

        // create new linked list object
        LinkedList list = readDataFile();

        // call linked list functionality
        list.display();
        list.count();
        userEmployeeAdd(list);
        list.display();
        list.count();
        list.removeNodes();
    }

    else
    {
        cout << "File did not open";
        return 1;
    }

    system("PAUSE");

    return 0;
}