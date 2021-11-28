// We first add the ifndef to stop form multiple inclusions in the case
// of multiple heritage.
#ifndef BASECLASS_H
#define BASECLASS_H

#include <string>
#include <iostream>

using namespace std;

class BaseClass
{
	string name = "";
	string path = "";

public:

	//Constructor without arguments
	BaseClass() : name{ "" }, path{ "" } {}

	//Constructor with arguments
	BaseClass(string name, string path) : name{ name }, path{ path } {}

	/*Destructor
	The destroyer signals that the object will be destroyed
	it does NOT destroy the object!(delete does it)
	It should be virtual because there are virtual methods.
	*/
	virtual ~BaseClass() { cerr << "Destruction of " << name << "\n"; }

	//getters
	string getName() const;
	string getPath() const;

	//setters
	void setName(string _name) { name = _name; }
	void setPath(string _path) { path = _path; }

	//display method to show the values of variables of the objects
	// VIRTUAL because the method is redefined.
	virtual void displayMethod(ostream& stream) const = 0;

	// VIRTUAL play method used in inherited classes
	//Abstract method = method without implementation
	virtual void play() const = 0;
};

#endif //BASECLASS_H

