#pragma once
#include "ofMain.h"

class Drawing {
	const ofColor grey5{ 5 };
	const ofColor grey15{ 15 };
	
public:
	bool isLightOn = true;
	void drawBackground() const;

	void drawBulb () const;
	void drawLamp() const;

	void drawPerson() const;
	void drawEyes() const;
	void drawIris(const int& mouseX, const int& mouseY) const;
};
