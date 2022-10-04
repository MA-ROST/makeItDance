#include "drawing.h"

void Drawing::drawBackground () const
{
	if (isLightOn) {
		const int divisionsBG{ 6 };
		for (int i = 0; i < divisionsBG; ++i) {
			// Lowers the opacity as the background generates
			ofSetColor(ofColor::black, 200 - 200 / divisionsBG * i);
			ofDrawRectangle (i * ofGetWidth() / divisionsBG, 0,
			                 ofGetWidth() / divisionsBG, ofGetHeight());
		}
	}
	else {
		ofSetColor(ofColor::black, 200);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	}
}

void Drawing::drawBulb () const
{
	// -- Bulb
	if (isLightOn) ofSetColor(ofColor::yellow);
	else		   ofSetColor(ofColor::black);
	ofDrawCircle(800, 250, 25);
}

void Drawing::drawLamp () const
{
	int lampX{ 800 };
	int lampY{ 250 };

	drawBulb ();
	// -- Chain
	ofNoFill();
	ofSetLineWidth(4);
	ofSetColor(grey5);
	for (int i = 0; i < 9; ++i) {
		ofDrawCircle(800, (10 * 2) * i, 10);
	}
	ofFill();
	// -- Cover
	ofSetColor(grey15);
	
	ofDrawTriangle(lampX - 75, lampY, 
	               lampX + 75, lampY, 
	               lampX,		  lampY-85);
	// -- Rays
	if (isLightOn) {
		ofSetColor(ofColor::yellow);
		ofSetLineWidth(2);
		ofDrawLine (lampX - 50, 290, lampX - 125, 400);
		ofDrawLine (lampX,	   300, lampX,       450);
		ofDrawLine (lampX + 50, 290, lampX + 125, 400);
	}
	
}

void Drawing::drawPerson () const
{
	ofSetColor(grey5);
	ofDrawRectangle(210, 350, 75, 200); // Neck
	ofSetColor(ofColor::black);
	ofSetCircleResolution(25);
	ofDrawEllipse(250, 350, 200, 250); // Face
	ofDrawRectRounded(125, 500, 250, 400, 90); // Body
}

void Drawing::drawEyes () const
{
	ofSetColor(ofColor::yellow);
	ofDrawTriangle(170, 375, 230, 375, 200, 355);
	ofDrawTriangle(270, 375, 330, 375, 300, 355);
}

void Drawing::drawIris (const int& mouseX, const int& mouseY) const
{
	// Make the irises follow the mouse while constraining them to the eyes.
	// Using a gap of 100 the left iris is shifted to the left eye
	ofSetColor(ofColor::black); //270 - 330 , 355 - 375
	// rIris
	ofDrawEllipse(ofMap(mouseX, 0, ofGetWidth(), 280, 320),       
	              ofMap(mouseY, 0, ofGetHeight(), 355, 375), 
	              40, 40); 
	// lIris
	ofDrawEllipse (ofMap (mouseX, 0, ofGetWidth(), 280, 320) - 100,
	               ofMap (mouseY, 0, ofGetHeight(), 355, 375), 
	               40, 40); 
}
