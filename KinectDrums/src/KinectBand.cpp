/*
 *  KinectBand.cpp
 *  KinectBand
 *
 *  Created by Paulo Barcelos on 7/10/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#include "KinectBand.h"

///////////////////////////////////////////////////////////////////////////////////
// Constructor --------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
KinectBand::KinectBand()
{	
	userGenerator = NULL;
	depthGenerator = NULL;
}
///////////////////////////////////////////////////////////////////////////////////
// Destructor ---------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
KinectBand::~KinectBand()
{	
	if(userGenerator != NULL) delete userGenerator;
	if(depthGenerator != NULL) delete depthGenerator;
}
///////////////////////////////////////////////////////////////////////////////////
// setup --------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
void KinectBand::setup(ofxDepthGenerator* depthGenerator, ofxUserGenerator* userGenerator)
{	
	this->depthGenerator = depthGenerator;
	this->userGenerator = userGenerator;
	
	userGenerator->setMaxNumberOfUsers(1);
	drums.setup(depthGenerator);
}
///////////////////////////////////////////////////////////////////////////////////
// update -------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
void KinectBand::update()
{	
	ofxTrackedUser* drumsUser = userGenerator->getTrackedUser(1);
	drums.update(drumsUser);
}