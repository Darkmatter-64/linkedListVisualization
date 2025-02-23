#include <iostream>
#include <cstddef>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	// Constructors
	Node() {
		data = 0;
		next = NULL;
	}

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList
{

public:
	Node* head;


	LinkedList() {
		head = NULL;
	}

	void insertAtHead(int data) {

		// Create the new Node
		Node* newNode = new Node(data);

		// Assign to head of the list is empty
		if (head == NULL) {
			head = newNode;
			return;
		}

		// Insert the newly created linked list at the head
		newNode->next = this->head;
		this->head = newNode;
	}

	void insertAtTail(int data) {
		Node* temp = head;

		// Check for empty list
		if (head == NULL) {
			head = new Node(data);
			return;
		}

		// Traverse the list
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new Node(data);
	}

	void print() {
		Node* temp = head;

		// Check for empty list
		if (head == NULL) {
			cout << "List empty" << endl;
			return;
		}

		// Traverse the list
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void deleteHead() {
		this->head = this->head->next;
	}

	void deleteTail() {
		Node* temp = head;

		// Check for empty list
		if (head == NULL) {
			return;
		}

		// Traverse the list
		while (temp->next != NULL) {
			if (temp->next->next == NULL) {
				temp->next = NULL;
				return;
			}
			temp = temp->next;
		}
	}


};
