#pragma once

#include "ofMain.h"
#include "ofxDebug.h"
#include "ofxGaussian.h"

class Node : public ofNode {

public:
	ofColor col;
	
	virtual void customDraw() {
		ofPushStyle();
		ofSetColor(col);
		ofCircle(0, 0, 10);
		ofPopStyle();
	}
	
};

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
private:
	ofEasyCam	cam;
	ofNode		lookat;
	
	vector<Node> nodes;
	
	float t;
	float b;
	float d;

		
};
