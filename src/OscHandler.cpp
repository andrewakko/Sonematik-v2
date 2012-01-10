/*
 *  OscHandler.cpp
 *  _3_Sonematik
 *
 *  Created by Andre Hostalacio on 11/8/11.
 *  Copyright 2011 Deutsche Telekom Laboratories. All rights reserved.
 *
 */

#include "OscHandler.h"

OscHandler::OscHandler(){
	
}


void OscHandler :: setup(int p ){
	
	port = p;
	////// OSC 
	// listen on the given port
	cout << "listening for osc messages on port " << port << "\n";
	receiver.setup( port );
	
}

void OscHandler::setData(DataModel* d){
	data = d;
}



void OscHandler :: update(){
	
	///// OSC
	// hide old messages
	for ( int i=0; i<NUM_MSG_STRINGS; i++ )
	{
		if ( timers[i] < ofGetElapsedTimef() )
			msg_strings[i] = "";
	}
	
	// check for waiting messages
	while( receiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m );
		////
		if (data != 0){
			
			////////////////// global
			
			if ( m.getAddress() == "/live/Global/blackWhite" )
			{
				data->blackWhite = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Global/camPos" )
			{
				data->camPos = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Global/rotateX" )
			{
				data->rotateX = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Global/rotateY" )
			{
				data->rotateY = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Global/rotateZ" )
			{
				data->rotateZ = m.getArgAsFloat( 0 );
			}
			
			
			///////////////////////////////////////////// Mesh
			
			if ( m.getAddress() == "/live/Mesh1/form" )
			{
				data->M1_form = m.getArgAsInt32(0);
			}
			
			
			if ( m.getAddress() == "/live/Mesh1/render" )
			{
				data->M1_render  = m.getArgAsInt32(0);
			}
			
			
			
			
			if ( m.getAddress() == "/live/Mesh1/kr1" )
			{
				float f = m.getArgAsFloat(0);
				data->M1_kr1 = f;
				
			}
			
			if ( m.getAddress() == "/live/Mesh1/kr2" )
			{
				data->M1_kr2 = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/kr3" )
			{
				data->M1_kr3 = m.getArgAsFloat( 0 );
			}
			////
			
			if ( m.getAddress() == "/live/Mesh1/uCount" )
			{
				data->M1_uCount = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/uMin" )
			{
				data->M1_uMin = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/uMax" )
			{
				data->M1_uMax = m.getArgAsFloat( 0 );
			}
			
			///
			
			if ( m.getAddress() == "/live/Mesh1/vCount" )
			{
				data->M1_vCount = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/vMin" )
			{
				data->M1_vMin = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/vMax" )
			{
				data->M1_vMax = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Mesh1/line" )
			{
				data->M1_line = m.getArgAsFloat( 0 );
				
			}
			
			if ( m.getAddress() == "/live/Mesh1/scaleBase" )
			{
				data->M1_scaleBase = m.getArgAsFloat( 0 );
				
			}
			
			// Mesh rotation
			
			if ( m.getAddress() == "/live/Mesh1/angleM" )
			{
				data->M1_angleM = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Mesh1/rotateMX" )
			{
				data->M1_rotateMX = m.getArgAsFloat( 0 );
				
			}
			
			if ( m.getAddress() == "/live/Mesh1/rotateMY" )
			{
				data->M1_rotateMY = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Mesh1/rotateMZ" )
			{
				data->M1_rotateMZ = m.getArgAsFloat( 0 );
				
			}
			
			////
			if ( m.getAddress() == "/live/Mesh1/controlKick" )
			{
				data->M1_controlKick = m.getArgAsFloat( 0 );
			}
			
			/////
			
			
			if ( m.getAddress() == "/live/Mesh1/alpha" )
			{
				data->M1_alpha = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/noise" )
			{
				data->M1_noise = m.getArgAsFloat( 0 );
			}
			
			
			// vertex control
			
			if ( m.getAddress() == "/live/Mesh1/v1x" )
			{
				data->M1_v1x = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/v1y" )
			{
				data->M1_v1y = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/v1z" )
			{
				data->M1_v1z = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Mesh1/v2x" )
			{
				data->M1_v2x  = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/v2y" )
			{
				data->M1_v2y = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/v2z" )
			{
				data->M1_v2z = m.getArgAsFloat( 0 );
			}
			
			
			
			if ( m.getAddress() == "/live/Mesh1/v3x" )
			{
				data->M1_v3x = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/v3y" )
			{
				data->M1_v3y = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/v3z" )
			{
				data->M1_v3z = m.getArgAsFloat( 0 );
			}
			
			
			
			if ( m.getAddress() == "/live/Mesh1/v4x" )
			{
				data->M1_v4x = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/v4y" )
			{
				data->M1_v4y = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/v4z" )
			{
				data->M1_v4z = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Mesh1/v5x" )
			{
				data->M1_v4x = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/v5y" )
			{
				data->M1_v4y = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh1/v5z" )
			{
				data->M1_v4z = m.getArgAsFloat( 0 );
			}
			
			///////////////////////////////////////////////////// MESH2
			
			
			if ( m.getAddress() == "/live/Mesh2/form" )
			{
				data->M2_form = m.getArgAsInt32(0);
			}
			
			
			if ( m.getAddress() == "/live/Mesh2/render" )
			{
				data->M2_render  = m.getArgAsInt32(0);
			}
			
			//
			
			if ( m.getAddress() == "/live/Mesh2/kr1" )
			{
				float f = m.getArgAsFloat(0);
				data->M2_kr1 = f;
				//std::cout << "new kr1 message: "<< f <<std::endl;
			}
			
			if ( m.getAddress() == "/live/Mesh2/kr2" )
			{
				data->M2_kr2 = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/kr3" )
			{
				data->M2_kr3 = m.getArgAsFloat( 0 );
			}
			
			//
			
			if ( m.getAddress() == "/live/Mesh2/uCount" )
			{
				data->M2_uCount = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/uMin" )
			{
				data->M2_uMin = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/uMax" )
			{
				data->M2_uMax = m.getArgAsFloat( 0 );
			}
			
			///
			
			if ( m.getAddress() == "/live/Mesh2/vCount" )
			{
				data->M2_vCount = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/vMin" )
			{
				data->M2_vMin = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/vMax" )
			{
				data->M2_vMax = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Mesh2/line" )
			{
				data->M2_line = m.getArgAsFloat( 0 );
				
			}
			
			if ( m.getAddress() == "/live/Mesh2/scaleBase" )
			{
				data->M2_scaleBase = m.getArgAsFloat( 0 );
				
			}
			
			//
			
			
			if ( m.getAddress() == "/live/Mesh2/angleM" )
			{
				data->M2_angleM = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Mesh2/rotateMX" )
			{
				data->M2_rotateMX = m.getArgAsFloat( 0 );
				
			}
			
			if ( m.getAddress() == "/live/Mesh2/rotateMY" )
			{
				data->M2_rotateMY = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Mesh2/rotateMZ" )
			{
				data->M2_rotateMZ = m.getArgAsFloat( 0 );
				
			}
			
			////
			if ( m.getAddress() == "/live/Mesh2/controlKick" )
			{
				data->M2_controlKick = m.getArgAsFloat( 0 );
			}
			
			/////
			
			
			if ( m.getAddress() == "/live/Mesh2/alpha" )
			{
				data->M2_alpha = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/noise" )
			{
				data->M2_noise = m.getArgAsFloat( 0 );
			}
			
			
			// vertex control
			
			if ( m.getAddress() == "/live/Mesh2/v1x" )
			{
				data->M2_v1x = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/v1y" )
			{
				data->M2_v1y = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/v1z" )
			{
				data->M2_v1z = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Mesh2/v2x" )
			{
				data->M2_v2x  = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/v2y" )
			{
				data->M2_v2y = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/v2z" )
			{
				data->M2_v2z = m.getArgAsFloat( 0 );
			}
			
			
			
			if ( m.getAddress() == "/live/Mesh2/v3x" )
			{
				data->M2_v3x = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/v3y" )
			{
				data->M2_v3y = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/v3z" )
			{
				data->M2_v3z = m.getArgAsFloat( 0 );
			}
			
			
			
			if ( m.getAddress() == "/live/Mesh2/v4x" )
			{
				data->M2_v4x = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/v4y" )
			{
				data->M2_v4y = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/v4z" )
			{
				data->M2_v4z = m.getArgAsFloat( 0 );
			}
			
			
			if ( m.getAddress() == "/live/Mesh2/v5x" )
			{
				data->M2_v4x = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/v5y" )
			{
				data->M2_v4y = m.getArgAsFloat( 0 );
			}
			
			if ( m.getAddress() == "/live/Mesh2/v5z" )
			{
				data->M2_v4z = m.getArgAsFloat( 0 );
			}
		}
		
		// print all in the screen
		
		// unrecognized message: display on the bottom of the screen
		string msg_string;
		msg_string = m.getAddress();
		msg_string += ": ";
		for ( int i=0; i<m.getNumArgs(); i++ )
		{
			// get the argument type
			msg_string += m.getArgTypeName( i );
			msg_string += ":";
			// display the argument - make sure we get the right type
			if( m.getArgType( i ) == OFXOSC_TYPE_INT32 )
				msg_string += ofToString( m.getArgAsInt32( i ) );
			else if( m.getArgType( i ) == OFXOSC_TYPE_FLOAT )
				msg_string += ofToString( m.getArgAsFloat( i ) );
			else if( m.getArgType( i ) == OFXOSC_TYPE_STRING )
				msg_string += m.getArgAsString( i );
			else
				msg_string += "unknown";
		}
		// add to the list of strings to display
		msg_strings[current_msg_string] = msg_string;
		timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
		current_msg_string = ( current_msg_string + 1 ) % NUM_MSG_STRINGS;
		// clear the next line
		msg_strings[current_msg_string] = "";
		
	}
	
}


void OscHandler::draw(){
	
	
	// -------  OSC
	
	string buf;
	buf = "listening for osc messages on port" + ofToString( port );
	ofDrawBitmapString( buf, 10, 20 );
	
	for ( int i=0; i<NUM_MSG_STRINGS; i++ )
	{
		ofDrawBitmapString( msg_strings[i], 10, 40+15*i );
	}
	
}




