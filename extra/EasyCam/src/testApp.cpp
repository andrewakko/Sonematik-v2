#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);

	cam.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, -664));
	lookat.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 0));
	
	for (int i = 0; i < 200; i++) {
		float xg = ofxGaussian();
		float yg = ofxGaussian();
		float zg = ofxGaussian();
		ofPoint p;
		p.set(xg*100, yg*100, zg*4000);
		p.x += ofGetWidth()/2; 
		p.y += ofGetHeight()/2;
		p.z += 100;
		ofColor col;
		col.set(ofRandom(255), ofRandom(255), ofRandom(255));
		Node node;
		node.setPosition(p);
		node.col = col;
		nodes.push_back(node);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	
	cam.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, -664));
	lookat.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 7750-664));
	
	t = ofSignedNoise(ofGetElapsedTimeMillis()*0.0004);;
	b = ofSignedNoise(ofGetElapsedTimeMillis()*0.0006);;
	d = ofSignedNoise(ofGetElapsedTimeMillis()*0.0005);;
	lookat.truck(t*1500);
	lookat.boom(b*1500);
	
	cam.lookAt(lookat, ofVec3f(t*0.1,-1+b*0.1,d*0.1));	

}

//--------------------------------------------------------------
void testApp::draw(){

	glEnable(GL_DEPTH_TEST);
	
	cam.begin();
	
	ofCircle(0, 0, 10);
	
	for (int i = 0; i < nodes.size(); i++) {
		nodes.at(i).draw();
	}
	
	cam.end();
	
	ofxDebug() << lookat.getPosition();

	ofDrawBitmapString(ofToString(t), 10, 20);	
	ofDrawBitmapString(ofToString(b), 10, 40);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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