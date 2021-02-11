#pragma once
#include <iostream>

using namespace std;

class UnsortedType
{

private:

	struct node {

		// each node will include an employee object for data
		int number;
		// pointer to point to the next node
		node* next;
	};

	public:

		node *head, *tail;

		// Class constructor
		UnsortedType();

		//destructor
		~UnsortedType();
		//~UnsortedType();

		//copy constructor
		UnsortedType(const UnsortedType& num);
		bool IsFull();
		int  GetLength();
		void RetrieveItem(int x);
		void InsertItem(int x);
		void DeleteItem(int x);
		void ResetList();
};

