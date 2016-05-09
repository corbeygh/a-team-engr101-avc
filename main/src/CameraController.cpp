/*
 * CameraController.cpp
 *
 *  Created on: 21/04/2016
 *      Primary Author:
 *      Author: mcghieandr
 *
 */

#include "CameraController.h"

extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int colour);
extern "C" int Sleep(int sec, int usec);

//Controller* CameraController::instance;

//This is the constructor
CameraController::CameraController(){
	WHITE_THRESHOLD = 140;
	center = 120;
	currentError = 0;
	prevousError = 0;
}

//this is the destructor
CameraController::~CameraController() {

}

CameraController* CameraController::makeInstance(){
	instance = new CameraController();
	return (CameraController*)instance;
}

//gets an array of 1's and 0's that indicate blank and white pixels
int[] CameraController::getWhiteArray(){
	take_picture();
	int white[320];
	for (int count = 0; count<320; count++){
		white[count]=get_pixel(count,120,3) > WHITE_THRESHOLD;
	}
	return white;
}

//gets the total sum of the white array * the position on the white pixels from the center
int CameraController::sum(int white[320]){
	int total = 0;
	for (int count = 0; count<320; count++){
		total += white[count]*(count-center);
	}
	return total;
}

//finds the change in error and updates the previous error variable
int CameraController::differential(int sum){
	int temp = previousError;
	previousError = sum;
	return (sum-temp)/temp;
}



