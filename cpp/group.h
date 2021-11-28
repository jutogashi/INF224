#pragma once
#ifndef GROUP_H
#define GROUP_H

#include "baseclass.h"
#include <list>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

/*create a group class which inherits a list of objects 
(the list is then inherited from the parent class)
 */

 /* We define a list of smart pointers.
 It needs to be a list of pointers because the list will contain objects form multiple classes.
 That is, at the same time we can have photos, videos and films in the list.
 (Pointers needed if polymorphism)
 */
class Group : public list<shared_ptr<BaseClass>>
{
	string name = "";

public:

	// Constructor
	Group() : list<shared_ptr<BaseClass>>() {}
	Group(string name) : name{ name } {}

	/* Destructor
	The group must not destroy the objects when it is destroyed, 
	because an object can belong to more than one group
	Question 9: with smart Pointers, there is no need to manually delete the pointer.
	*/ 
	~Group() { cerr << "Destruction of Group " << name << "\n"; }

	//  getters
	string getName() const { return name ;}

	//display method to show the values of variables of the objects
	void displayMethod(ostream& stream) const;
};

#endif // GROUP_H