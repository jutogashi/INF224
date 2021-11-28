#include "pch.h"
#include "group.h"

using namespace std;

void Group::displayMethod(ostream& stream) const
	{
		stream << "-Reading group " << getName() << "..." << endl;
		//Getting every item form the list
		for (auto &it : *this) {
			if (it) {
				// Calling display method from the object Class
				it->displayMethod(stream);
			}
			stream << "-Reading done. " << endl;
		}
	}