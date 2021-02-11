// Circular Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"UnsortedType.h"

// method to print menu 
void printMenu() {
    cout << "--------------------" << endl;
    cout << "Enter 1: isFull()" << endl;
    cout << "Enter 2: getLength()" << endl;
    cout << "Enter 3: RetrieveItem()" << endl;
    cout << "Enter 4: InsertItem()" << endl;
    cout << "Enter 5: DeleteItem()" << endl;
    cout << "Enter 6: ResetList()" << endl;
    cout << "--------------------" << endl;
    cout << "Enter choice: ";
}

int main()
{
    int input;
    char choice = 'Y';
    UnsortedType List;
    int num;

    while (choice == 'Y')
    {
        printMenu();
        cin >> input;

        // switch for menu user options
        switch (input)
        {
        case 1:
            if (List.IsFull() == true) {
                cout << "List is not full" << endl;
            }

            else {
                cout << "List is full" << endl;
            }
            break;
        case 2:
            cout << "Length of list: " << List.GetLength() << endl;
            break;

        case 3:
            cout << "Enter a number to retieve: ";
            cin >> num;
            List.RetrieveItem(num);
            break;

        case 4:
            cout << "Enter a number to insert: ";
            cin >> num;
            List.InsertItem(num);
            break;

        case 5:
            cout << "Enter a number to delete: ";
            cin >> num;
            List.DeleteItem(num);
            break;

        case 6:
            List.ResetList();
            cout << "List reset" << endl;
            break;

        default:
            cout << "invalid input";
            break;
        }

        cout << "Would you like to continue? (Y/N)";
        cin >> choice;
    }

    system("PAUSE");

    return 0;
}