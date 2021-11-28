#pragma once
#ifndef PHOTO_H
#define PHOTO_H

#include "baseclass.h"
#include <string>
#include <iostream>

using namespace std;

//This classes being simple, we can implement it in the header.

class Photo : public BaseClass
{

	double latitude = 0;
	double longitude = 0;

public:
	
	// Constructor
	Photo() {} //Implicit constructor chaining
	Photo(string _name, string _path, double latitude, double longitude) : BaseClass(_name, _path), latitude{ latitude }, longitude{ longitude } {}

	//getters
	double getLatitude() const { return latitude; }
	double getLongitude() const { return longitude; }

	//setters
	void setLatitude(double _latitude) { latitude = _latitude; }
	void setLongitude(double _longitude) { longitude = _longitude; }

	//display method to show the values of variables of the objects
	void displayMethod(ostream& stream) const {
		BaseClass::displayMethod(stream);
		stream << "Class : 'Photo';\nName: " << getName() << "\nPath: " << getPath() << "\nLatitude:" << getLatitude() << "\nLongitude:" << getLongitude() << endl;
	}

	// Method that allows you to play the multimedia object
	void play() const override {
		string str = "imagej " + getPath() + " &";
		system(str.c_str());
	};

};

#endif //PHOTO_H

