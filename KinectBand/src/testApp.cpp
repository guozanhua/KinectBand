#include "testApp.h"

void testApp::setup() {
	ofSetVerticalSync(true);
	ofSetWindowShape(1280, 480);
	context.setup();
	depth.setup(&context);
	image.setup(&context);
	user.setup(&context);
	
	context.toggleRegisterViewport();
	context.toggleMirror();
	
	band.setup(&depth, &user);
}

void testApp::update() {
	// update all nodes
	context.update();
	depth.update();
	image.update();
	user.update(); 
	band.update();
	
	/*if(user.getNumberOfTrackedUsers() > 0) {
		ofxTrackedUser* cur = user.getTrackedUser(1);
		
		if(cur != NULL) {
			ofxLimb& leftArm = cur->left_lower_arm;
			ofxLimb& rightArm = cur->right_lower_arm;
			
			XnPoint3D& leftHand = leftArm.position[1];
			XnPoint3D& rightHand = rightArm.position[1];
			
			depth.getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &leftHand, &leftHand);
			depth.getXnDepthGenerator().ConvertProjectiveToRealWorld(1, &rightHand, &rightHand);
			
			ofVec3f leftVec(leftHand.X, leftHand.Y, leftHand.Z);
			ofVec3f rightVec(rightHand.X, rightHand.Y, rightHand.Z);
			
			distance = (leftVec - rightVec).length();
			
			ofxOscMessage msg;
			msg.setAddress("/distance");
			msg.addFloatArg(distance);
			osc.sendMessage(msg);
		}
	}*/
}

void testApp::draw() {
	ofBackground(0);
	
	ofSetColor(255);
	depth.draw(0, 0, 640, 480);
	image.draw(640, 0, 640, 480);
	user.draw();
}