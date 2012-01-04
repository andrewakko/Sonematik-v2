/*
 *  Shape.cpp
 *  emptyExample
 *
 *  Created by Andre Hostalacio on 10/5/11.
 *  Copyright 2011 Deutsche Telekom Laboratories. All rights reserved.
 *
 */

#include "aShape.h"

aShape::aShape(){

	_x = ofRandomf();
    _y = ofRandomf();
    _z = ofRandomf();
    _vX = ofRandom(0, 4);
    _vY = ofRandom(0, 4);
    _vZ = ofRandom(0, 4);
    _radius = ofRandom(0, 1);
    _color = ofRandom(0, 0xFF0000);
    _age = 0;
    _dead = false;
    _maxAge = ofRandom(0, 50) + 100;


}

void aShape::setup(){
	
}


void aShape::update(){
	

		
}

void aShape::draw(){
	
	ofPushMatrix();
	
	ofTranslate(_x,_y,_z);
	ofSetColor(100,_color,_color);
	ofFill();
	ofBox(5);
	ofNoFill();
	ofSetColor(100,_color,_color);
	ofBox(_radius);
	ofPopMatrix();
    
    ofPopMatrix();
	
}