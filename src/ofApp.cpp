#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundColor(26, 49, 52);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	drawing.drawBackground();
	drawing.drawLamp();
	drawing.drawPerson();
	drawing.drawEyes();
	drawing.drawIris(ofGetMouseX(), ofGetMouseY());

	ofSetColor(ofColor::yellow);
	ofDrawBitmapString(
		"X: " + std::to_string(ofGetMouseX()) + " " +
		"Y: " + std::to_string(ofGetMouseY()),
		10, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 32) {
		if (drawing.isLightOn) drawing.isLightOn = false;
		else				   drawing.isLightOn = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
	ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
	ofShowCursor();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}