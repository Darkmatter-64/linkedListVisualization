#include "ofMain.h"
#include "ofApp.h"
#include "LinkedList.cpp"


#include <iostream>
using namespace std;


//========================================================================
int main( ){

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();




	LinkedList ll = LinkedList();
	cout << ll.head << endl;
	ll.insertAtHead(6);
	cout << ll.head->data << endl;
	ll.print();
	ll.insertAtHead(8);
	Node* currHead = ll.head;
	cout << currHead->data << endl;
	currHead = currHead->next;
	cout << currHead->data << endl;

	ll.print();
	ll.insertAtTail(9);
	ll.print();
	ll.deleteHead();
	ll.print();
	ll.deleteAll();
	ll.print();
}





