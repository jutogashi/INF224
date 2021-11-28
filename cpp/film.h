#pragma once
#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <string>
#include <iostream>

using namespace std;

class Film : public Video
{
	int * duration_table = nullptr;
	unsigned int n_chaps = 0;

public:
	// Constructor
	Film() :Video("", "", 0), duration_table{ nullptr }, n_chaps{ 0 } {}
	Film(string _name = "", string _path = "", int _duration = 0,
		int * _duration_table = nullptr, unsigned int _n_chaps = 0) : Video(_name, _path, _duration) {
		/* When we pass an array as an argument to a function,
		it is only the ADDRESS of the first element that is copied. 
		The function therefore has NO WAY to know the number of elements of the array.
		So we pass the number as argument and copy the array element by element.
		*/

		n_chaps = _n_chaps;
		if (n_chaps > 0)
		{
			duration_table = new int[n_chaps];
			for (unsigned int i = 0; i < n_chaps; i++)
			{
				duration_table[i] = _duration_table[i];
			}
		}


	}

	/* Destructor
	We need to define a destructor if it is necessary to "clean up".
	In this case, we need to free the memory space of the duration table.
	*/
	~Film() {
		delete[] duration_table;
		duration_table = nullptr;
	}

	// getters
	int * const getChaps() const { return duration_table ; }
	unsigned int getNumChap() const { return this->n_chaps ; }

	//setters
	//Setting method defined similary in a similar way to the costructor.
	void setChaps(int * _duration_table, unsigned int _n_chaps);

	//display method to show the values of variables of the objects
	void displayMethod(ostream& stream) const;

	//the method to play the object does not need to be redefined

	// Deep coopying
	/*The copie of an object can be a problem in the case of pointers. Because they point to the same object.
	So if we change one, we will change both, and we may try to delete sometinh that already exists.
	One solution would be to do a deep copy.
	Film(const Film& from);
	Film& operator=(const Film& from);
	*/
};
#endif // FILM_H

