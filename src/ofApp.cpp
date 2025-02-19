#include "ofApp.h"
#include "linkedList.cpp"

// Global variables
int maxAmplitude;
int ampOffset;

LinkedList ll = LinkedList();

//--------------------------------------------------------------
void ofApp::setup(){
	maxAmplitude = 20;

	// For testing
	ll.insertAtHead(50);
	ll.insertAtHead(30);
	ll.insertAtTail(25);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	int yOffset = maxAmplitude;
	int xOffset = 0;

	if (ll.head != NULL) {
		Node* curr = ll.head;
		while (curr != NULL) {
			if (curr->data + maxAmplitude > yOffset) {
				yOffset = curr->data + maxAmplitude;
			}
			curr = curr->next;
		}

		curr = ll.head;
		while (curr != NULL) {
			ofDrawCircle(xOffset + curr->data, yOffset, curr->data);
			xOffset += 2 * curr->data + 25;
		}


	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
