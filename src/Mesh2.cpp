

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

	
	data->M1_scale = data->M2_scaleBase + data->M2_controlKick;
	
	ofScale(data->M1_scale,data->M1_scale,data->M1_scale);
	glRotatef(data->M2_angleM*2, sin(data->M2_rotateMX)*2, cos(data->M2_rotateMY)*2, -sin(data->M2_rotateMZ)*2);
	
	// draw mesh
	glMatrixMode(GL_MODELVIEW);
	glLineWidth(data->M2_line);	
	
	if (data != 0){
		
		for (float iv = 0; iv <= data->M2_vCount; iv+=1) {
			
			
	
			switch (data->M2_render) {
					
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
					
				case 5:
					glBegin(GL_LINE_LOOP);
					break;
					
				default:
					glBegin(GL_LINE_STRIP);
					break;
					
			}
			
			
			
			for (float iu = 0; iu <= data->M2_uCount; iu+=1) {
				float u = ofMap(iu, 0, data->M2_uCount, data->M2_uMin, data->M2_uMax);
				float v = ofMap(iv, 0, data->M2_vCount, data->M2_vMin, data->M2_vMax);
				
				
				switch(data->M2_form) {
						
					float x;
					float y;
					float z;
						
						
				case 1:
						
						x = data->M2_kr1 * ofRandom(1,data->M2_noise) * 0.5 * cos(v);
						y = data->M2_kr2 * ofRandom(1,data->M2_noise) * 0.5 * cos(v) * 0.75 * sin(u);
						z = data->M2_kr3 * ofRandom(1,data->M2_noise) * 0.5 * cos(u) ;
						
						glColor4f(1.0,1.0,1.0,data->M2_alpha);
						glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
						glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); 
						glVertex3f(x * 1.25 * data->M2_v3x, y * 1.75 * data->M2_v3y, z * data->M2_v3z);
						
						
						
						break;
						
						
				case 2:
						
						x = data->M2_kr1 * ofRandom(1,data->M2_noise) * 0.5 * sin(u+v);
						y = data->M2_kr2 * ofRandom(1,data->M2_noise) * 0.5 * sin(u) * 0.75 * sin(v);
						z = (data->M2_kr3 * ofRandom(1,data->M2_noise) + cos(v))* sin(u) ;
						
						glColor4f(1.0,1.0,1.0,data->M2_alpha);
						glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
						glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); 
						glVertex3f(x * 1.25 * data->M2_v3x, y * 1.75 * data->M2_v3y, z * data->M2_v3z);
						
						
						
						break;
						
						
						
				case 3:
						
						x = data->M2_kr1 * ofRandom(1,data->M2_noise) * 0.5 * sin(u*v) * cos(u-v);
						y = data->M2_kr2 * ofRandom(1,data->M2_noise) * 0.5 * cos(u) * 0.75 * (sin(v)*cos(u))/2 ;
						z = (data->M2_kr3 * ofRandom(1,data->M2_noise) + sin(v)) * cos(u) ;
						
						glColor4f(1.0,1.0,1.0,data->M2_alpha);
						glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
						glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); 
						glVertex3f(x * 1.25 * data->M2_v3x, y * 1.75 * data->M2_v3y, z * data->M2_v3z);
						
						
						
						break;
						
						
				case 4:
						
						x = data->M2_kr1 * ofRandom(1,data->M2_noise) * 0.5 * sin(2*TWO_PI*v) * sin(2*TWO_PI*u) * 0.75;
						y = data->M2_kr2 * ofRandom(1,data->M2_noise) * 0.5 * cos(2*TWO_PI*v) * sin(2*TWO_PI*u) * 0.75;
						z = data->M2_kr3 * ofRandom(1,data->M2_noise) * cos(TWO_PI*u) * 0.75 ;
						
						glColor4f(1.0,1.0,1.0,data->M2_alpha);
						glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
						glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); 
						glVertex3f(x * 1.25 * data->M2_v3x, y * 1.75 * data->M2_v3y, z * data->M2_v3z);
						glVertex3f(x * 2.05 * data->M2_v3x, y * 2.05 * data->M2_v3y, z * data->M2_v3z);
						
						
						break;
						
						
				case 5:
						
						x = data->M2_kr1 * ofRandom(1,data->M2_noise) * 0.5 * cos(u) / (sqrt(2) + sin(v)) ;
						y = data->M2_kr2 * ofRandom(1,data->M2_noise) * 0.5 * sin(u)/ (sqrt(2) + sin(v));
						z = data->M2_kr3 * ofRandom(1,data->M2_noise) * 0.5 * 1/ (sqrt(2)+cos(v)) ;
						
						glColor4f(1.0,1.0,1.0,data->M2_alpha);
						glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
						glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); 
						glVertex3f(x * 1.25 * data->M2_v3x, y * 1.75 * data->M2_v3y, z * data->M2_v3z);
						glVertex3f(x * 0.25 * data->M2_v3x, y * 0.25 * data->M2_v3y, z * data->M2_v3z);
						
						
						break;
						
						
				case 6:
						
						x = data->M2_kr1 * ofRandom(1,data->M2_noise) * (u* cos(v)) * sin(TWO_PI * u) *0.5 ;
						y = data->M2_kr2 * ofRandom(1,data->M2_noise) * (u * cos(v)) * cos(TWO_PI *u) +2 * u *0.5;
						z = data->M2_kr3 * ofRandom(1,data->M2_noise) * u * sin(v) *0.5 ;
						
						glColor4f(1.0,1.0,1.0,data->M2_alpha);
						glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
						glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); 
						glVertex3f(x * 1.25 * data->M2_v3x, y * 1.75 * data->M2_v3y, z * data->M2_v3z);
						glVertex3f(x * 0.25 * data->M2_v3x, y * 0.25 * data->M2_v3y, z * data->M2_v3z);
						
						
						break;
						
				case 7:
						
						x = data->M2_kr1 * ofRandom(1,data->M2_noise) * 0.5 * u * cos(v)*sin(u);
						y = data->M2_kr2 * ofRandom(1,data->M2_noise) * 0.5 * u * cos(u)*cos(v);
						z = data->M2_kr3 * ofRandom(1,data->M2_noise) * 0.5 * -u * sin(v);
						
						glColor4f(1.0,1.0,1.0,data->M2_alpha);
						glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
						glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); 
						glVertex3f(x * 1.25 * data->M2_v3x, y * 1.75 * data->M2_v3y, z * data->M2_v3z);
						glVertex3f(x * 0.25 * data->M2_v3x, y * 0.25 * data->M2_v3y, z * data->M2_v3z);
						
						
						break;
						
				case 8:
						
						x = data->M2_kr1 * ofRandom(1,data->M2_noise) * 0.75 * (0.5 + cos(v))* cos(u);
						y = data->M2_kr2 * ofRandom(1,data->M2_noise) * 0.75 * (0.5 + cos(v))* sin(u);
						z = data->M2_kr3 * ofRandom(1,data->M2_noise) * 0.75 * (sin(v) + cos(v));
						
						glColor4f(1.0,1.0,1.0,data->M2_alpha);
						glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
						glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); 
						glVertex3f(x * 1.25 * data->M2_v3x, y * 1.75 * data->M2_v3y, z * data->M2_v3z);
						glVertex3f(x * 0.25 * data->M2_v3x, y * 0.25 * data->M2_v3y, z * data->M2_v3z);
						
						
						break;
						
				case 9:
						
						x = data->M2_kr1 * ofRandom(1,data->M2_noise) * 0.75 * sin(u) * (1 + cos(v));
						y = data->M2_kr2 * ofRandom(1,data->M2_noise) * 0.75 * sin(u + (2 * PI) / 3) * (1 + cos(v + (2*PI) / 3)) ;
						z = data->M2_kr3 * ofRandom(1,data->M2_noise) * 0.75 * sin(u + (4 * PI) / 3)* (1 + cos(v + (4*PI) / 3)) ;
						
						glColor4f(1.0,1.0,1.0,data->M2_alpha);
						glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
						glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); 
						glVertex3f(x * 1.25 * data->M2_v3x, y * 1.75 * data->M2_v3y, z * data->M2_v3z);
						glVertex3f(x * 0.25 * data->M2_v3x, y * 0.25 * data->M2_v3y, z * data->M2_v3z);
						
						
						break;
						
				default:	
						
						x = data->M2_kr1 * ofRandom(1,data->M2_noise) * 0.5 * sin(v);
						y = data->M2_kr2 * ofRandom(1,data->M2_noise) * 0.5 * cos(u) * cos(v);
						z = data->M2_kr3 * ofRandom(1,data->M2_noise) * 0.5 * sin(u) ;
				
						glColor4f(1.0,1.0,1.0,data->M2_alpha);
						glVertex3f(x * data->M2_v1x, y * data->M2_v1y, z * data->M2_v1z);
						glVertex3f(x * 0.75 * data->M2_v2x, y * 0.75 * data->M2_v2y, z * data->M2_v2z); 
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


