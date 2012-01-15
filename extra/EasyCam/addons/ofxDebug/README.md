You can use like std::cout but automatic newline and separator space are added.

ofTypes and ofxVectorMath types are convert for easy to read format.

	ofxDebug() << "this" << "is" << "output" << "test" << 123;
	// output: this is output test 123
	
	ofPoint pos(1,2,3);
	ofxDebug() << "pos is:" << pos;
	// output: pos is: ofPoint(1,2,3) 


If you want to string data, simply you will use std::stringstream.

	std::stringstream ss;
	
	ofxDebug(ss) << "output to string with std::stringstream\n"
	<< "MouseX:" << mouseX << "mouseY:" << mouseY;
	
	ofDrawBitmapString(ss.str(), mouseX, mouseY);
