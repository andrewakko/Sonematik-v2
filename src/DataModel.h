//#pragma once

#import "ofMain.h"

#ifndef _DATA_
#define _DATA_



class DataModel {
	
public:
	
	DataModel();
	~DataModel(); // disctructer
	
	//setters and getters not being used yet-- for testing variables are all Public and accessed Directly.
	/*void setMesh1Param(string paramToSet,int val );
	int getParam(string paramToGet);*/

	//Global
	float camPos;
	float blackWhite;
	
	float rotateX;
	float rotateY;
	float rotateZ;
	
	float scale;
	
	float maskSize;
	float maskPosX;
	float maskPosY;
	
	// Mesh

	
	//
	
	int M1_render;
	int M1_form;
	
	float M1_kr1;
	float M1_kr2;
	float M1_kr3;
		
	float M1_line;
	float M1_scale;
	float M1_scaleBase;
	float M1_controlKick; 
	float M1_alpha;
	float M1_noise; 
	
	float M1_uMin;
	float M1_uMax;
	float M1_uCount;
	
	float M1_vMin;
	float M1_vMax;
	float M1_vCount;
	
	float M1_uControl;
	float M1_vControl;
	
	float M1_rotateMX;
	float M1_rotateMY;
	float M1_rotateMZ;
	float M1_angleM;

	float M1_v1x ;
	float M1_v1y ;
	float M1_v1z ;
	
	float M1_v2x ;
	float M1_v2y ;
	float M1_v2z ;
	
	float M1_v3x ;
	float M1_v3y ;
	float M1_v3z ;
	
	float M1_v4x ;
	float M1_v4y ;
	float M1_v4z ;
	
	float M1_v5x ;
	float M1_v5y ;
	float M1_v5z ;
	
	
	// Mesh2
	
	int M2_render;
	int M2_form;
	
	float M2_kr1;
	float M2_kr2;
	float M2_kr3;
	
	float M2_leftMov;
	float M2_rightMov;
	float M2_downMov;
	float M2_upMov;
	
	float M2_line;
	float M2_scale;
	float M2_scaleBase;
	float M2_controlKick; 
	float M2_alpha;
	float M2_noise; 
	
	float M2_uMin;
	float M2_uMax;
	float M2_uCount;
	
	float M2_vMin;
	float M2_vMax;
	float M2_vCount;
	
	float M2_uControl;
	float M2_vControl;
	
	float M2_rotateMX;
	float M2_rotateMY;
	float M2_rotateMZ;
	float M2_angleM;
	
	
	
	float M2_v1x ;
	float M2_v1y ;
	float M2_v1z ;
	
	float M2_v2x ;
	float M2_v2y ;
	float M2_v2z ;
	
	float M2_v3x ;
	float M2_v3y ;
	float M2_v3z ;
	
	float M2_v4x ;
	float M2_v4y ;
	float M2_v4z ;
	
	float M2_v5x ;
	float M2_v5y ;
	float M2_v5z ;
	
	
	
	
	
	
	
	
	
	
private:
	
	//std::map <string, int> mesh1;

};

#endif
