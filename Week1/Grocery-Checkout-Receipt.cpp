// Grocery-Checkout-Receipt.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Nile Weadick 1/12/21

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// delcare item struct
struct item {
    string itemNumber;
    string itemDesc;
    double price;
    string tax;
};

// delcare order variable struct
struct order {
    string number;
    int quanity;
};

// delcare file names
ifstream inputFile;
ofstream outPutFile;

// delcare calculation variables
double total, itemTotal, totalTax, subtotal;

// fucntion to iterate through each line in dat file and push to a vector of type item
vector<item> readData() {

    string itemNum, itemName, itemPrice, itemTax, line;
    string delimeter = "><";
    vector<item> inventory;\
    // create a new item variable
    item itemData;

    // while each line has data
    while (getline(inputFile, line)) {

        //assign string to each item, then erase the substr from text line
        itemNum = line.substr(0, line.find(delimeter));
        line.erase(0, line.find(delimeter) + delimeter.length());

        itemName = line.substr(0, line.find(delimeter));
        line.erase(0, line.find(delimeter) + delimeter.length());

        itemPrice = line.substr(0, line.find(delimeter));
        line.erase(0, line.find(delimeter) + delimeter.length());

        itemTax = line.substr(0, line.find(delimeter));
        line.erase(0, line.find(delimeter) + delimeter.length());

        itemData.itemNumber = itemNum;
        itemData.itemDesc = itemName;
        itemData.price = stof(itemPrice);
        itemData.tax = itemTax;

        //push struct item to inventory vector
        inventory.push_back(itemData);
    }

    return inventory;
}

// function to take the vector of items and print to user and receipt
void printStoreItems(vector<item> inven) {

    cout << "-----------------------------" << endl;
    outPutFile << "-----------------------------" << endl;

    cout << "STORE ITEMS" << endl;
    outPutFile << "STORE ITEMS" << endl;

    cout << "-----------------------------" << endl;
    outPutFile << "-----------------------------" << endl;

    // for every item in the vector print the desired infortiom to proper location
    for (int i = 0; i < inven.size(); i++) {
        cout << inven[i].itemNumber << " " << inven[i].itemDesc << endl;
        outPutFile << inven[i].itemNumber << " " << inven[i].itemDesc << " " << inven[i].price << " " << inven[i].tax << endl;
    }

    cout << "-----------------------------" << endl;
    outPutFile << "-----------------------------" << endl;
}

// fucntion to get what the user wants to buy
vector<order>getUserOrders(){

    string userItemNumInput;
    int userItemQuanityInput;

    order userOrder;
    vector<order> userOrders;

    // as logn as the user input is not a 0 
    while (userItemNumInput != "0") {
        cout << "Enter a item number: ";
        cin >> userItemNumInput;

        if (userItemNumInput == "0") {

            return userOrders;
        }

        cout << "Enter a item quanity: ";
        cin >> userItemQuanityInput;

        // Test if useritemNum is a duplicate
        //Test if quanity is an int

        userOrder.number = userItemNumInput;
        userOrder.quanity = userItemQuanityInput;

        // push item order input to vector of orders
        userOrders.push_back(userOrder);
    }

    return userOrders;
}

// function to print all the user input to the reciept
void printUserData(vector<order> userOrders) {

    outPutFile << "From keyboard (Customer)" << endl;

    // iterate through each order and print in a desried format
    for (int i = 0; i < userOrders.size(); i++) {
        outPutFile << userOrders[i].number << " " << userOrders[i].quanity << endl;
        //test for item num matches
    }

    outPutFile << "-----------------------------" << endl;
}

// fucntion to caluate the totals
void calcTotals(vector<item> items, vector<order> orders) {

    double itemTax;
    string isItemTaxed;

    // iteate through all orders in vector
    for (int i = 0; i < orders.size(); i++) {

        // reset variable for temp item total 
        itemTotal = 0;
        // reset varaibel if the item is taxed or not
        isItemTaxed = "";

        // iterate through all items in the inventory vector
        for (int j = 0; j < items.size(); j++){

            // test if the user input is a store item that exist
            if (orders[i].number == items[i].itemNumber)
            {
                //test if the specfied item is taxed or not
                if (items[i].tax == "T") {

                    // caluate the itemtax
                    itemTax = (items[i].price * .075) * orders[i].quanity;
                    // add tax to running tax total
                    totalTax += itemTax;

                    // set string to TX so it can print to reciept
                    isItemTaxed = "TX";
                }

                // calcualet all other needed totals
                itemTotal = items[i].price * orders[i].quanity;
                outPutFile << items[i].itemDesc << " " << orders[i].quanity << " @ " << items[i].price << " " << itemTotal << " " << isItemTaxed << endl;
                subtotal += itemTotal;
                break;
            }

            else
            {
                outPutFile << "*** item " << orders[i].number << " does exist in inventory" << endl;
                break;
            }
        }
    }

    // print to receipt the totals of their checkout
    total = subtotal + totalTax;
    outPutFile << "Subtotal " << subtotal << endl;
    outPutFile << "Tax " << totalTax << endl;
    outPutFile << endl << "Total " << total << endl;
}

int main(){

    // open the input and output files
    inputFile.open("D:\\CC Spring 2021\\Algorithms and Data Structures\\Week1\\invent.dat");
    outPutFile.open("D:\\CC Spring 2021\\Algorithms and Data Structures\\Week1\\receipt.dat");

    //test if input file has opened
    if (inputFile.is_open()) {

        //test if output file has opened
        if (outPutFile.is_open()) {
            
            vector<item> items = readData();
            printStoreItems(items);
            vector<order> orders = getUserOrders();
            printUserData(orders);
            calcTotals(items, orders);
        }

        else
        {
            cout << "output File did not open";
            return 1;
        }
    }
    else
    {
        cout << "input File did not open";
        return 1;
    }

    // close files
    inputFile.close();
    outPutFile.close();
    system("pause");

    return 0;
}
