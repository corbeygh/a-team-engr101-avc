/*
 * CameraControllerTest.cpp
 *
 *  Created on: 28/04/2016
 *      Author: mgoo
 */

#include  <stdio.h>
#include  <assert.h>
#include  "../src/CameraController.h"
#include "CameraControllerTest.h"

//runs the tests
void CameraControllerTest::runTests(){
	printf("Camera Test Running");
	CameraController *camera_controller =(CameraController*)CameraController::getInstance();

}

CameraControllerTest::CameraControllerTest() {
	// TODO Auto-generated constructor stub

}

CameraControllerTest::~CameraControllerTest() {
	// TODO Auto-generated destructor stub
}

