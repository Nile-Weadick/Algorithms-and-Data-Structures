// Week6.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Nile Weadick

#include <iostream>
#include <fstream>
#include "Employee.h"
#include "BinarySearchTree.h"

using namespace std;

ifstream inFile;

// method that reads data inside .txt file and returns a tree
BinarySearchTree readDataFile() {

    // local variables
    string delimeter = "><";
    string num, fName, lName, years;
    string line;

    // employee object
    Employee e;
    BinarySearchTree BST;

    // while each line of inFile has data get the whole line
    while (getline(inFile, line)) {

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
        e.Number = stoi(num);
        e.firstName = fName;
        e.lastName = lName;
        e.yearsOfService = stoi(years);

        // add employee object to tree
        BST.add(e);
    }

    return BST;
}

Employee makeEmployee() {
    int n, y;
    string f, l;

    cout << "Enter employee number: ";
    cin >> n;
    cout << "Enter employee first name: ";
    cin >> f;
    cout << "Enter employee last name: ";
    cin >> l;
    cout << "Enter employee years of service: ";
    cin >> y;

    Employee e;
    e.Number = n;
    e.firstName = f;
    e.lastName = l;
    e.yearsOfService = y;

    return e;
}

// show user methods
void printMenu() {
    cout << "--------------------" << endl;
    cout << "Enter 1: add()" << endl;
    cout << "Enter 2: remove()" << endl;
    cout << "Enter 3: count()" << endl;
    cout << "Enter 4: display()" << endl;
    cout << "--------------------" << endl;
    cout << "Enter choice: ";
}

int main()
{
    int input;
    char choice = 'Y';

    // attempt to open data file
    inFile.open("Employee.txt");

    // test if file opened successfully
    if (inFile.is_open()) {

        BinarySearchTree employeeBST = readDataFile();
        employeeBST.display();
        while (choice == 'Y')
        {
            printMenu();
            cin >> input;

            // switch for menu user options
            switch (input)
            {
            case 1:
                //add employee
                employeeBST.add(makeEmployee());
                employeeBST.display();
                break;
            case 2:

                // remove employee
                employeeBST.del(makeEmployee());
                break;

            case 3:
                // output employee count
                employeeBST.returnCount();
                break;

            case 4:
                // show all in tree
                employeeBST.display();
                break;

            default:
                cout << "invalid input";
                break;
            }

            cout << "Would you like to continue? (Y/N)";
            cin >> choice;
        }
    }

    else
    {
        cout << "File did not open";
        return 1;
    }
    system("PAUSE");

    return 0;
}