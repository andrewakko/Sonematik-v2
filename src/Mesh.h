/*
 *  cShape.h
 *  emptyExample
 *
 *  Created by Andre Hostalacio on 10/17/11.
 *  Copyright 2011 Deutsche Telekom Laboratories. All rights reserved.
 *
 */

//#pragma once

#import "ofMain.h"
#include "DataModel.h"

#ifndef _MESH_
#define _MESH_


class Mesh
{
		
public:
	
	Mesh();
	
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
	
	void setData(DataModel* d);
		
private:
	
	DataModel* data;
		
};


#endif