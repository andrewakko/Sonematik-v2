/*
 *  cShape.cpp
 *  emptyExample
 *
 *  Created by Andre Hostalacio on 10/17/11.
 *  Copyright 2011 Deutsche Telekom Laboratories. All rights reserved.
 *
 */

#include "Mesh.h"

Mesh::Mesh()  {
	
	
}

void Mesh::setup(){
	
}

void Mesh::setData(DataModel* d){
	data = d;
}


void Mesh::update(){
	
}

void Mesh::draw(){
	ofEnableAlphaBlending();
	
	// --  O
	
	glPushMatrix();
	ofPushStyle();
	
	
	//scale = scale +m controlKick;
	
	data->M1_scale = data->M1_scaleBase + data->M1_controlKick; // SCALEBASE change overAll
	
	ofScale(data->M1_scale,data->M1_scale,data->M1_scale);
	glRotatef(data->M1_angleM*2, sin(data->M1_rotateMX)*2, cos(data->M1_rotateMY)*2, -sin(data->M1_rotateMZ)*2);
	
	// draw mesh
	glMatrixMode(GL_MODELVIEW);
	glLineWidth(data->M1_line);	
	
	
	if (data != 0)
	{
		
		//std::cout << "FormA Mesh Draw(): "<< data->formA << std::endl;
		for (float iv = 0; iv <= data->M1_vCount; iv+=1) 
		{
			
			
				switch (data->renderA) {
						
					case 1:
						glBegin(GL_POINTS);
						break;
						
					case 2:
						glBegin(GL_TRIANGLES);
						break;
						
					case 3:
						glBegin(GL_TRIANGLE_STRIP);
						break;
						
					case 4:
						glBegin(GL_QUAD_STRIP);
						break;
						
						
					default:
						glBegin(GL_LINE_STRIP);
						break;
						
				}
			
			
			//	glBegin(GL_POINTS); // sky
			//	glBegin(GL_LINES);
			//	glBegin(GL_LINE_STRIP); // looks good, almost no line difference from all
			//	glBegin(GL_LINE_LOOP);
			//  glBegin(GL_TRIANGLES); // fragment
			//	glBegin(GL_TRIANGLE_STRIP); full form inside
			//	glBegin(GL_TRIANGLE_FAN);
			//	glBegin(GL_QUADS); cool, strange direction
		    //	glBegin(GL_QUAD_STRIP); //cool
			//	glBegin(GL_POLYGON); same as quad...

			//
			for (float iu = 0; iu <= data->M1_uCount; iu+=1) 
			{
				float u = ofMap(iu, 0, data->M1_uCount, data->M1_uMin, data->M1_uMax);
				float v = ofMap(iv, 0, data->M1_vCount, data->M1_vMin, data->M1_vMax);
				
				//
				switch(data->formA) {
						
						float x;
						float y;
						float z;
						
					case 1:
						
						
						x = cos(u) * (3*cos(v)  * data->M1_kr1 * ofRandom(1,data->M1_noise) - cos(3*v));
						y = sin(u) * (3*cos(v)  * data->M1_kr2 * ofRandom(1,data->M1_noise) - cos(3*v));
						z = 3 * sin(v) - sin(3*v) * data->M1_kr3 * ofRandom(1,data->M1_noise);
						
						glColor4f(1.0,1.0,1.0,data->M1_alpha);
						glVertex3f(x * data->M1_v1x, y * data->M1_v1y, z * data->M1_v1z);
						glVertex3f(x * -0.5 * data->M1_v2x, y * 0.5 * data->M1_v2y, z * data->M1_v2z); // add a multiplier in the control...
						glVertex3f(x * -1.25 * data->M1_v3x, y * -1.75 * data->M1_v3y, z * data->M1_v3z);
						
						break;
						
					case 2:
						
						// case formB	
						
						// SECOND FORM
						x = 2 * sin(u) * data->M1_kr1 * ofRandom(1,data->M1_noise);
						y = 2 * sin(v * data->M1_kr2 * ofRandom(1,data->M1_noise));
						z = 2 * sin(u+v) * data->M1_kr3 * ofRandom(1,data->M1_noise);
						
						glColor4f(1.0,1.0,1.0,data->M1_alpha);
						glVertex3f(x * data->M1_v1x, y * data->M1_v1y, z * data->M1_v1z);
						glVertex3f(x * 5.75 * data->M1_v2x, y * 5.75 * data->M1_v2y, z * data->M1_v2z); // add a multiplier in the control...
						glVertex3f(x * -1.25 * data->M1_v3x, y * -1.75 * data->M1_v3y, z * data->M1_v3z);
						
						break;
						//	*/
						
					default:
						
						x = 0.75 * sin(u) * data->M1_kr1 * ofRandom(1,data->M1_noise);
						y = sin(v) * 0.50 * data->M1_kr2 * ofRandom(1,data->M1_noise);
						z = cos(u) * cos(v) * data->M1_kr3 * ofRandom(1,data->M1_noise);
						
						glColor4f(1.0,1.0,1.0,data->M1_alpha);
						glVertex3f(x * data->M1_v1x, y * data->M1_v1y, z * data->M1_v1z);
						glVertex3f(x * 0.75 * data->M1_v2x, y * 0.75 * data->M1_v2y, z * data->M1_v2z); // add a multiplier in the control...
						glVertex3f(x * 1.25 * data->M1_v3x, y * 1.75 * data->M1_v3y, z * data->M1_v3z);
						glVertex3f(x * 3.25 * data->M1_v4x, y * 3.75 * data->M1_v4y , z * data->M1_v4z);
						glVertex3f(x * 2.25 * data->M1_v5x, y * 2.275 * data->M1_v5y , z * data->M1_v5z);	
						
						break;
				}
		
			}
		}
	}
		
	glEnd();
	ofPopStyle();
	glPopMatrix();
	ofDisableAlphaBlending();
	// --  X
	//glFlush();
	
	
	// -----------------------------
}


