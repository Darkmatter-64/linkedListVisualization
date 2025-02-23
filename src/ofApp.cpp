#include "ofApp.h"
#include "LinkedList.cpp"

// Global variables
ofCamera cam = ofCamera();
int maxAmplitude;
int ampOffset;
bool ampIncrease = true;
int gap = 25;

LinkedList ll = LinkedList();

//--------------------------------------------------------------
void ofApp::setup(){
	maxAmplitude = 20;
	ampOffset = 0;

	LinkedList ll = LinkedList();
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ampIncrease) {
		ampOffset += 1;
		if (ampOffset >= maxAmplitude) {
			ampIncrease = false;
		}
	}
	if (!ampIncrease) {
		ampOffset -= 1;
		if (ampOffset <= -1*maxAmplitude) {
			ampIncrease = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	

	int yOffset=0;
	int xOffset=0;
	Node* curr = ll.head;
	int radius;
	
	// Get largest radius
	while (curr) {
		if (curr->data > yOffset) {
			yOffset = curr->data;
		}
		curr = curr->next;
	}
	ofNoFill();
	curr = ll.head;
	int snake = 1;
	while (curr) {
		radius = curr->data;
		ofDrawCircle(xOffset + radius , yOffset + maxAmplitude + ampOffset * snake, radius);
		ofDrawBitmapString(to_string(radius), xOffset + radius, yOffset + maxAmplitude + ampOffset * snake);
		if (xOffset > 0) { // not first node
			ofDrawLine(xOffset - gap, yOffset + maxAmplitude, xOffset, yOffset+maxAmplitude + ampOffset*snake);
		}
		
		xOffset += 2 * radius + gap;
		snake *= -1;
		curr = curr->next;
	}

	//cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int randL;
	vector<int> items;
	Node* curr;
	switch (key) {
	case 'q':
		randL = rand() % 90 + 10;
		ll.insertAtHead(randL);
		break;
	case 'w':
		randL = rand() % 90 + 10;
		ll.insertAtTail(randL);
		break;
	case 'a':
		ll.deleteHead();
		break;
	case 's':
		ll.deleteTail();
		break;
	case 'z':
		maxAmplitude += 10;
		ampOffset = 0;
		ampIncrease = true;
		break;
	case 'x':
		maxAmplitude -= 10;
		if (maxAmplitude < 0)
			maxAmplitude = 0;
		ampOffset = 0;
		ampIncrease = true;
		break;
	case 'e':
		// Read data into vector
		curr = ll.head;
		while (curr) {
			items.push_back(curr->data);
			curr = curr->next;
		}
		// Sort the vector
		sort(items.begin(), items.end());
		// Read sorted vector into linked list
		curr = ll.head;
		for (int i = 0; i < items.size(); i++) {
			curr->data = items[i];
			curr = curr->next;
		}
		break;
	case OF_KEY_LEFT:
		cam.pan(-10);
		break;
	case OF_KEY_RIGHT:
		cam.pan(10);
		break;
	}
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
