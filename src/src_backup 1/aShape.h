/*
 *  Shape.h
 *  emptyExample
 *
 *  Created by Andre Hostalacio on 10/5/11.
 *  Copyright 2011 Deutsche Telekom Laboratories. All rights reserved.
 *
 */

#import "ofMain.h"

#ifndef _A_SHAPE_
#define _A_SHAPE_


class aShape  
{
private:
    
    bool _dead;
    float _x, _y, _z;
    float _vX, _vY, _vZ;
    int _color, _radius, _age, _maxAge;
	
public:
	
	
	aShape();
    
	
	
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
	
};

#endif 
