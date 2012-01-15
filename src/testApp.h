#pragma once

#include "ofMain.h"
#include "OscHandler.h"
#include "DataModel.h"	


#include "Mesh.h"
#include "Mesh2.h"

#include "ofxQuadWarp.h"

#ifndef _TEST_APP
#define _TEST_APP

class testApp : public ofBaseApp{
	
public:
	
	//testApp();
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);		
	
	 
	ofxQuadWarp warper; // quad warper
	
	ofEasyCam cam; // add mouse controls for camera movement
		
	// ajust translation center but can complicate with the vertex. check this out.
	float centerX;
	float centerY;
	
	float lastWidth;
	float lastHeight;
	
	// INFOS
	bool showMsg;
	
	// FOG
	float fogColor[4];
	// fog
	float lightDensity;
	float fogStart;
	float fogEnd;

	
	// dispansable
	int				mouseX, mouseY;
	string			mouseButtonState;
	
private:
	DataModel data;

	Mesh myMesh;
	Mesh2 myMesh2;
	
	OscHandler myOsc;
	
	void showInfo();
	
	ofFbo fbo;
	
};


#endif
