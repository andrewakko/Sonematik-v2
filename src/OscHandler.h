/*
 *  OscHandler.h
 *  _3_Sonematik
 *
 *  Created by Andre Hostalacio on 11/8/11.
 *  Copyright 2011 Deutsche Telekom Laboratories. All rights reserved.
 *
 */
#pragma once
#import "ofMain.h"
#include "ofxOsc.h"
#include"DataModel.h"

#ifndef _OSC_
#define _OSC_

#define NUM_MSG_STRINGS 20


class OscHandler{

		
public:
	
	/////   OSC
	
	ofTrueTypeFont		font;
	ofxOscReceiver	receiver;
	
	
	int				current_msg_string;
	string			msg_strings[NUM_MSG_STRINGS];
	float			timers[NUM_MSG_STRINGS];
	
	
	
	OscHandler();
	
	void setup(int port );
	
	void update();
	void draw();
		
	void gotMessage(ofMessage msg);		
	void setData(DataModel* d);
	
	
	private:
	
	int port;
	DataModel* data;
	
};




#endif