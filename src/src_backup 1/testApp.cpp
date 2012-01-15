#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	ofEnableAlphaBlending();	// turn on alpha blending
	ofSetVerticalSync(true);
	ofSetBackgroundAuto(true);  // set background to refresh always
	ofBackground(ofColor::black); 
	
	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST); 
	
	
	
	// ofBox uses texture coordinates from 0-1, so you can load whatever
	// sized images you want and still use them to texture your box
	// but we have to explicitly normalize our tex coords here
	ofEnableNormalizedTexCoords();
	
	
	
	// more setup
	ofHideCursor();
	ofEnableSmoothing();
	
	// play in center
	centerX = ofGetScreenWidth() / 2;
	centerY = ofGetScreenHeight() / 2;
	
	
	// where is camera
	camPos = 100;
	scale = 2;
	cam.setDistance(camPos);
	
	for (int i=0; i<size; i++) p[i] = new aShape();
	
}

//--------------------------------------------------------------
void testApp::update(){
	

}

// --------------------------------------------------------------
void testApp::draw(){
	
	
	
	// center translation
	// ofTranslate(centerX, centerY);
	
	//  -- Start Camera
	cam.begin();		
		ofRotateX(ofRadToDeg(.5));
		ofRotateY(ofRadToDeg(-.5));
	
	// this sets the camera's distance from the object

	
	// ------------------------- INSIDE THE CAM DO:
	
	ofScale(scale, scale, scale);
		
	/* ofSetColor(255,0,0);
	ofFill();
	ofBox(30);
	ofNoFill();
	ofSetColor(0);
	ofBox(30);
	*/
	 
	
	// draw loops
	for (int i=0; i<size; i++) p[i]->draw();
	
	
	
	// INFO
	ofSetColor(255, 255);
	ofDrawBitmapString("ALOHA", 10, 20);
	
	
	// -------------------------
	
	
	// -- Camera FInish
	
	
	cam.end();
	
	// INFO
	ofSetColor(255, 255);
	string msg = ofToString("Use 'a' to toggle");
	msg += "\nfps: " + ofToString(ofGetFrameRate(), 2);
	msg +=  "\nuCount: ";
	ofDrawBitmapString(msg, 10, 20);
	
	
	ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	switch(key) {
	
case 'F':
case 'f':
	ofToggleFullscreen();
	break;	
	}
	
	}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
	
}


