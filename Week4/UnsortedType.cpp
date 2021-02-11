#include "UnsortedType.h"

UnsortedType::UnsortedType() {

    tail = NULL;
}

UnsortedType::UnsortedType(const UnsortedType& num) {

	
}

// class destructor
UnsortedType::~UnsortedType() {
	node* current = tail->next;
	while (current != NULL)
	{
		node* temp = current->next;
		delete current;
		current = temp;
	}
}

bool UnsortedType::IsFull() {

	node* head = tail->next;

	// if head node is empty then no data in list
	if (head == NULL) {
		return true;
	}
}

int UnsortedType::GetLength() {

	node* head = tail->next;
	int count = 0;

	// if head node is empty then no data in list
	if (head == NULL) {
		return count;
	}

	else {
		count++;
		// while current node is not empty
		while (head != tail) {
			count++;
			head = head->next;
		}
	}
	return count;
}

// method to find a number in the list and return location
void UnsortedType::RetrieveItem(int x) {

	node* head = tail->next;

	int counter = 0;

	// while we arent at the end of our list
	while (head != tail)
	{
		counter++;
		// test if values match
		if (head->number == x)
		{
			cout << "Number " << x;
			cout << " found at position " << counter << endl;
			return;
		}
		head = head->next;
	}

	// test if head node matches x
	if (head->number == x)
	{
		counter++;
		cout << "Number " << x;
		cout << " found at position " << counter << endl;
		return;
	}

	// not found in list
	cout << "Number " << x << " not found in the list" << endl;
}

void UnsortedType::InsertItem(int x) {

	// create a temp node of node type
	node* temp = new node;

	//deref
	temp->number = x;

	// if tail is emplty it becomes tail and and then tail makes it last in list
	if (tail == NULL) {
		tail = temp;
		temp->next = tail;
	}

	else {

		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}
}

// method to delete a searched item 
void UnsortedType::DeleteItem(int x) {

	node* temp;
	node* head = tail->next;

	// if list has only one item
	if (tail->next == tail && tail->number == x) {

		temp = tail;
		// set the only node to null
		tail = NULL;
		// free the memory of temp ptr
		free(temp);

		cout << "Number " << x;
		cout << " deleted from the list" << endl;

		return;
	}

	//delete the head node
	else if (head->number == x) {
		temp = head;
		tail->next = head->next;
		free(temp);

		cout << "Number " << x;
		cout << " deleted from the list" << endl;

		return;
	}

	// delete an element if its between head and tail
	//iterate though list until we reach tail
	while (head->next != tail)
	{
		//Deletion of Element in between
		if (head->next->number == x)
		{
			temp = head->next;
			head->next = temp->next;
			free(temp);

			cout << "Number " << x;
			cout << " deleted from the list" << endl;

			return;
		}
		// move to next node
		head = head->next;
	}

	cout << "Number " << x << " not found in the list" << endl;
}

void UnsortedType::ResetList() {

	// set tail to null will clear list
	tail = NULL;
}