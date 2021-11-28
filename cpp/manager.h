#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <memory>
#include <string>
#include <sstream>

#include "baseclass.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "tcpserver.h"

using namespace std;
using namespace cppu;

class Manager
{
	using ObjDict = map<string, shared_ptr<BaseClass>>;
	using GroupDict = map<string, shared_ptr<Group>>;

	ObjDict objDict;
	GroupDict groupDict;

public:
	/*In order to allow elements to be found efficiently from their name,
	we will use associative tables (template map class)
	*/
	Manager() : objDict(), groupDict() {}

	/*Create a Photo, Video, Movie, Group and add it to the appropriate table.
	Note that a method is needed for each type, returning the created object.
	*/

	/*To prevent that an object is created with new out of the Manager Class,
	meaning it wouldn't be added to the list,
	we could make the constructors of photo, video, film, group, protected.
	for objects of this class (by default) and also for subclasses.
	*/
	shared_ptr<BaseClass> newPhoto(string _name, string _path, double _latitude, double _longitude);
	shared_ptr<BaseClass> newVideo(string _name, string _path, int _duration);
	shared_ptr<BaseClass> newFilm(string _name, string _path, int _duration, int * _duration_table, unsigned int _n_chaps);
	shared_ptr<Group> newGroup(string name);

	// Find and Display a multimedia object or a group from its name, given as an argument
	shared_ptr<BaseClass> findObj(string _name) const;
	shared_ptr<Group> findGroup(string _name) const;

	// Play a multimedia object
	void playObj(string _name) const;

	//processRequest for Client/Server
	bool processRequest(TCPConnection& cnx,const string& request, string& response);

};

#endif // MANAGER_H