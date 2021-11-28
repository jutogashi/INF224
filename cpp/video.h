#pragma once
#ifndef VIDEO_H
#define VIDEO_H

#include "baseclass.h"
#include <string>
#include <iostream>

using namespace std;

//This classes being simple, we can implement it in the header.

class Video : public BaseClass
{
	int duration = 0;

public:
	// Constructor
	Video() {} //Implicit constructor chaining
	Video(string _name, string _path, int duration) : BaseClass(_name, _path), duration{ duration } {}

	//getters
	int getDuration() const { return duration; }

	//setters
	void setDuration(int _duration) { duration = _duration; }

	//display method to show the values of variables of the objects
	void displayMethod(ostream& stream) const {
		BaseClass::displayMethod(stream);
		stream << "Class : 'Video';\nName: " << getName() << "\nPath: " << getPath() << "\nDuration: " << getDuration() << endl;
	}

	// Method that allows you to play the multimedia object
	void play() const override {
		string str = "mpv " + getPath() + " &";
		system(str.c_str());
	}

};

#endif // VIDEO_H