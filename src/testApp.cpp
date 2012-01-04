#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	
	myOsc.setData(&data);
	myOsc.setup(12345);
	myMesh.setData(&data);
	myMesh2.setData(&data);

	ofEnableSmoothing(); // only on strokes
	ofEnableAlphaBlending();	// turn on alpha blending
	ofSetVerticalSync(true);
	ofSetBackgroundAuto(true);  // set background to refresh always
	//	LINE
	glEnable(GL_NORMALIZE);
	glEnable(GL_LINE_SMOOTH);
	ofEnableSmoothing();
	// shade
	glShadeModel (GL_SMOOTH);
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);  
	glEnable(GL_POINT_SPRITE);  	
	glEnable(GL_SAMPLE_ALPHA_TO_ONE);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
		
	glEnable(GL_POINT_SMOOTH_HINT);
	glEnable(GL_LINE_SMOOTH_HINT);
	glEnable(GL_POLYGON_SMOOTH_HINT);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//
	glClearColor (0.0, 0.0, 0.0, 0.0);
	cam.setNearClip(0.01);
	cam.setFarClip(1000); // range of my view
	cam.setGlobalPosition(ofVec3f(0,0,100));
	///
	
	
	
	
	showMsg = true; // for the info toggle
	// play in center // im not using thissss
	centerX = ofGetScreenWidth() * 0.5;
	centerY = ofGetScreenHeight() * -0.5;
	// fog
	lightDensity = 0.5;
	fogStart=4.0;
	fogEnd= 100.0;
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	myOsc.update();
	//cout << "testApp: "<< data.kr1 << endl;
///////////////////
	
}

// --------------------------------------------------------------
void testApp::draw(){
	
	glClearColor(data.blackWhite, data.blackWhite, data.blackWhite, 1.0); 
	
	glClear(GL_COLOR_BUFFER_BIT); 
	glDisable(GL_FOG); //dis the fog
	//ofDisableAlphaBlending();
 
	ofPushStyle();
	ofEnableAlphaBlending();
	//  -- Start Camera
	cam.begin();	
	ofRotateX(data.rotateX);
	ofRotateY(-data.rotateY);
	ofRotateZ(data.rotateZ);
	cam.setDistance(data.camPos);	
	
	myMesh.draw();
	myMesh2.draw();
	
	cam.end();
	ofPopStyle();
	
	
	// INFO 
	
	if (showMsg) {
		showInfo();
	}
}


void testApp::showInfo(){
	ofPushStyle();	
	myOsc.draw();
	ofSetColor(255,255,0,255);
	string msg = ofToString("Use 'f' to toggle full");
	msg += "\nfps: " + ofToString(ofGetFrameRate(), 2);
	msg +=  "\ncamPos: " + ofToString(data.camPos,1);
	msg +=  "\nlightDensity: " + ofToString(lightDensity,1);
	msg +=  "\nfogStart: " + ofToString(fogStart,1);
	msg +=  "\nfogEnd: " + ofToString(fogEnd,1);
	ofDrawBitmapString(msg, 10, 500);
	ofPopStyle();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	switch(key) {
			
		case'A':
		case 'a':
			showMsg = !showMsg;	break;
			
		case 'F':
		case 'f': ofToggleFullscreen(); break;	
			
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


