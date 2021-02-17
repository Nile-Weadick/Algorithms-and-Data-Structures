// TowersOfHanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Method to caluclate the required move
void moveRing(int rings, int PegA, int PegC, int PegB) {
    if (rings > 0) {

        // use recrusiosn to call the moveRing method inside moveRing method
        //move smallest ring and relabel pegs
        moveRing(rings - 1, PegA, PegB, PegC);

        // Display to the user each move required to be made in order to solve the problem
        cout << "Move Ring " << rings << " From Peg " << PegA << " To Peg " << PegC << "\n";

        // change ring and relabel pegs
        moveRing(rings - 1, PegB, PegC, PegA);
    }
}


int main() {

    // int number of disk
    int ringNum = 5;
    // call method
    moveRing(ringNum, 1, 3, 2);

    system("PAUSE");
    return 0;
}
