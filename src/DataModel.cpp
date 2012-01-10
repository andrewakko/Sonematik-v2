/*
 *  DataModel.cpp
 *  _3_Sonematik
 *
 *  Created by Andre Hostalacio on 11/15/11.
 *  Copyright 2011 Deutsche Telekom Laboratories. All rights reserved.
 *
 */

#include "DataModel.h"

DataModel::DataModel(){
	
	// global
	blackWhite=0;
	camPos = 38.0;
	
	rotateX = 1;
	rotateY = 1;
	rotateZ = 1;
		
	// MESH
	
	M1_form = true;
	M2_form = true;
	
	M1_render = 5;
	M2_render = 5;
	
	
	// max that for loop goes U horizontal
	M1_uCount = 5;
	M1_uMin = -PI;
	M1_uMax = PI;
	
	// grid definition vertical
	M1_vCount = 20;
	M1_vMin = -PI;
	M1_vMax = PI;
	
	M1_scale= 0.0; // if I change the scale the shadow is also scaled
	M1_scaleBase = 5.0;
	
	M1_line= 1.0;
	M1_alpha= 0.2;
	M1_noise = 1;
	
	M1_kr1 = 1;
	M1_kr2 = 1;
	M1_kr3 = 1;
	
	M1_angleM = 45;
	M1_rotateMX= 100;
	M1_rotateMY= 60;
	M1_rotateMZ= 1;
	M1_controlKick = 0;
	
	M1_uControl= 20;
	M1_vControl= 20;
	
	// inter
	
	M1_v1x = 1;
	M1_v1y = 1;
	M1_v1z = 1;
	
	M1_v2x = 1;
	M1_v2y = 1;
	M1_v2z = 1;
	
	M1_v3x = 1;
	M1_v3y = 1;
	M1_v3z = 1;
	M1_v4x = 1;
	M1_v4y = 1;
	M1_v4z = 1;
	
	
	//MESH2
	
	// max that for loop goes U horizontal
	M2_uCount = 5;
	M2_uMin = -PI;
	M2_uMax = PI;
	
	// grid definition vertical
	M2_vCount = 20;
	M2_vMin = -PI;
	M2_vMax = PI;
	
	M2_scale= 0.0; // if I change the scale the shadow is also scaled
	M2_scaleBase = 5.0;
	
	M2_line= 1.0;
	M2_alpha= 0.2;
	M2_noise = 1;
	
	M2_kr1 = 1;
	M2_kr2 = 1;
	M2_kr3 = 1;
	
	M2_angleM = 45;
	M2_rotateMX= 100;
	M2_rotateMY= 60;
	M2_rotateMZ= 1;
	M2_controlKick = 0;
	
	M2_uControl= 20;
	M2_vControl= 20;
	
	// inter
	
	M2_v1x = 1;
	M2_v1y = 1;
	M2_v1z = 1;
	
	M2_v2x = 1;
	M2_v2y = 1;
	M2_v2z = 1;
	
	M2_v3x = 1;
	M2_v3y = 1;
	M2_v3z = 1;
	
	M2_v4x = 1;
	M2_v4y = 1;
	M2_v4z = 1;
	
	
}

DataModel:: ~DataModel(){ // disctructer


}

/*
void DataModel::setMesh1Param(string paramToSet,int val ){
	mesh1[paramToSet] = val;
}




int DataModel::getMesh1Param(string paramToget){
	return mesh1[paramToget];
}*/