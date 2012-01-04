#include "testApp.h"

#include "ofxDebug.h"

void testApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0, 0, 0);
	ofSetColor(255, 255, 255);
	
	ofxDebug() << "this" << "is" << "output" << "test" << 123;
	
	ofPoint pos(1,2,3);
	ofxDebug() << "pos is:" << pos;
}

void testApp::update()
{
}

void testApp::draw()
{
	std::stringstream ss;
	
	ofxDebug(ss) << "output to string with std::stringstream\n"
	<< "MouseX:" << mouseX << "mouseY:" << mouseY;
	
	ofDrawBitmapString(ss.str(), mouseX, mouseY);
}

void testApp::keyPressed(int key)
{
}

void testApp::keyReleased(int key)
{
}

void testApp::mouseMoved(int x, int y)
{
}

void testApp::mouseDragged(int x, int y, int button)
{
}

void testApp::mousePressed(int x, int y, int button)
{
}

void testApp::mouseReleased(int x, int y, int button)
{
}

void testApp::windowResized(int w, int h)
{
}
