/*
 *  Mesh2.h
 *  _3_Sonematik
 *
 *  Created by Andre Hostalacio on 11/30/11.
 *  Copyright 2011 Deutsche Telekom Laboratories. All rights reserved.
 *
 */



#import "ofMain.h"
#include "DataModel.h"

#ifndef _MESH_2_
#define _MESH_2_


class Mesh2
{
	
public:
	
	Mesh2();
	
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