#pragma once

#include <sstream>

#include "ofMain.h"

class ofxDebug
{
	ostream *output;
	
public:
	
	ofxDebug()
	{
		output = &cout;
		*output << setprecision(3);
	}
	
	ofxDebug(ostream &s)
	{
		output = &s;
		*output << setprecision(3);
	}
	
	~ofxDebug()
	{
		*output << endl;
		output = NULL;
	}

	template<class T>
	ofxDebug& operator<<(const T& o)
	{
		*output << o << " ";
		return *this;
	}

	ofxDebug& operator<<(const ofPoint& o)
	{
		*output << "ofPoint(" 
			<< o.x << "," 
			<< o.y << "," 
			<< o.z << ") ";
		return *this;
	}

	ofxDebug& operator<<(const ofRectangle& o)
	{
		*output << "ofRectangle(" 
			<< o.x << "," 
			<< o.y << "," 
			<< o.width << "," 
			<< o.height << ") ";
		return *this;
	}

	ofxDebug& operator<<(const ofColor& o)
	{
		*output << "ofColor(" 
		<< o.r << "," 
		<< o.g << "," 
		<< o.b << "," 
		<< o.a << ") ";
		return *this;
	}
	
#ifdef OFX_VECTOR_MATH
	
	ofxDebug& operator<<(const ofxVec2f& o)
	{
		*output << "ofxVec2f(" 
		<< o.x << "," 
		<< o.y << ") ";
		return *this;
	}

	ofxDebug& operator<<(const ofxVec3f& o)
	{
		*output << "ofxVec3f(" 
		<< o.x << "," 
		<< o.y << "," 
		<< o.z << ") ";
		return *this;
	}

	ofxDebug& operator<<(const ofxVec4f& o)
	{
		*output << "ofxVec4f(" 
		<< o.x << "," 
		<< o.y << "," 
		<< o.z << "," 
		<< o.w << ") ";
		return *this;
	}
	
	ofxDebug& operator<<(const ofxQuaternion& o)
	{
		*output << "ofxQuaternion(" 
		<< o.x() << "," 
		<< o.y() << "," 
		<< o.z() << "," 
		<< o.w() << ") ";
		return *this;
	}
	
	ofxDebug& operator<<(const ofxMatrix3x3& o)
	{
		const int w = 6;
		*output << "ofxMatrix3x3(\n" 
		<< "\t" << setw(w) << o.a << "," << setw(w) << o.b << "," << setw(w) << o.c << ",\n" 
		<< "\t" << setw(w) << o.d << "," << setw(w) << o.e << "," << setw(w) << o.f << ",\n" 
		<< "\t" << setw(w) << o.g << "," << setw(w) << o.h << "," << setw(w) << o.i << ",\n" 
		<< ")";
		return *this;
	}

	ofxDebug& operator<<(const ofxMatrix4x4& o)
	{
		const int w = 6;
		*output << "ofxMatrix4x4(\n" 
		<< "\t" << setw(w) << o(0,0) << "," << setw(w) << o(0,1) << "," << setw(w) << o(0,2) << "," << setw(w) << o(0,3) << ",\n" 
		<< "\t" << setw(w) << o(1,0) << "," << setw(w) << o(1,1) << "," << setw(w) << o(1,2) << "," << setw(w) << o(1,3) << ",\n" 
		<< "\t" << setw(w) << o(2,0) << "," << setw(w) << o(2,1) << "," << setw(w) << o(2,2) << "," << setw(w) << o(2,3) << ",\n" 
		<< "\t" << setw(w) << o(3,0) << "," << setw(w) << o(3,1) << "," << setw(w) << o(3,2) << "," << setw(w) << o(3,3) << ",\n" 
		<< ")";
		return *this;
	}
	
	
#endif
	
};