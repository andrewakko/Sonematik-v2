/*
 *  Mesh2.cpp
 *  _3_Sonematik
 *
 *  Created by Andre Hostalacio on 11/30/11.
 *  Copyright 2011 Deutsche Telekom Laboratories. All rights reserved.
 *
 */

#include "Mesh2.h"



/*
 *  cShape.cpp
 *  emptyExample
 *
 *  Created by Andre Hostalacio on 10/17/11.
 *  Copyright 2011 Deutsche Telekom Laboratories. All rights reserved.
 *
 */

#include "Mesh2.h"

Mesh2::Mesh2()  {
	
	
}

void Mesh2::setup(){
	
}

void Mesh2::setData(DataModel* d){
	data = d;
}


void Mesh2::update(){
	
}

void Mesh2::draw(){
	ofEnableAlphaBlending();
	
	// --  O
	
	glPushMatrix();
	ofPushStyle();
	
	
	//scale = scale +m controlKick;
	
	data->M1_scale = data->M2_scaleBase + data->M2_controlKick; // SCALEBASE change overAll
	
	ofScale(data->M1_scale,data->M1_scale,data->M1_scale);
	glRotatef(data->M2_angleM*2, sin(data->M2_rotateMX)*2, cos(data->M2_rotateMY)*2, -sin(data->M2_rotateMZ)*2);
	
	// draw mesh
	glMatrixMode(GL_MODELVIEW);
	glLineWidth(data->M2_line);	
	
	if (data != 0){
		
		for (float iv = 0; iv <= data->M2_vCount; iv+=1) {
			
			
	
			switch (data->renderB) {
					
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
			
			
			
			for (float iu = 0; iu <= data->M2_uCount; iu+=1) {
				float u = ofMap(iu, 0, data->M2_uCount, data->M2_uMin, data->M2_uMax);
				float v = ofMap(iv, 0, data->M2_vCount, data->M2_vMin, data->M2_vMax);
				
				
				switch(data->formB) {
						
					float x;
					float y;
					float z;
						
				default:	
					x = data->M2_kr1 * ofRandom(1,data->M2_noise) * 0.5 * sin(v);
					y = data->M2_kr2 * ofRandom(1,data->M2_noise) * 0.5 * cos(u) * cos(y);
					z = data->M2_kr3 * ofRandom(1,data->M2_noise) * 0.5 * sin(u) ;
				
				glColor4f(1.0,1.0,1.0,data->M2_alpha);
				glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
				glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); // add a multiplier in the control...
				glVertex3f(x * 1.25 * data->M2_v3x, y * 1.75 * data->M2_v3y, z * data->M2_v3z);
				//std::cout << data->kr1 << std::endl;
				//std::cout << data->kr1 << " x: " << x <<std::endl;
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


