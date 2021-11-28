#include "pch.h"
#include "manager.h"

using namespace std;

shared_ptr<BaseClass> Manager::newPhoto(string _name, string _path, double _latitude, double _longitude)
{
	// Checking if item is already in media map (A Map requires all keys to be unique)
	auto it = objDict.find(_name);
	// If is not... add it
	if (it == objDict.end())
	{
		shared_ptr<Photo> photo(new Photo(_name, _path, _latitude, _longitude));
		objDict[_name] = photo;
	}
	// Message if it already is
	else { cout << "This photo already exists, try another name." << endl;  }
	return objDict[_name];
}

shared_ptr<BaseClass> Manager::newVideo(string _name, string _path, int _duration)
{
	// Checking if item is already in media map (A Map requires all keys to be unique)
	auto it = objDict.find(_name);
	// If is not... add it
	if (it == objDict.end())
	{
		shared_ptr<Video> video(new Video(_name, _path, _duration));
		objDict[_name] = video;
	}
	// Message if it already is
	else { cout << "This video already exists, try another name." << endl; }
	return objDict[_name];
}

shared_ptr<BaseClass> Manager::newFilm(string _name, string _path, int _duration, int * _duration_table, unsigned int _n_chaps) 
{
	// Checking if item is already in media map (A Map requires all keys to be unique)
	auto it = objDict.find(_name);
	// If is not... add it
	if (it == objDict.end())
	{
		shared_ptr<Film> film(new Film(_name, _path, _duration, _duration_table, _n_chaps));
		objDict[_name] = film;
	}
	// Message if it already is
	else { cout << "This video already exists, try another name." << endl; }
	return objDict[_name];
}

shared_ptr<Group> Manager::newGroup(string _name)
{
	// Checking if item is already in group map (A Map requires all keys to be unique)
	auto it = groupDict.find(_name);
	// If is not... add it
	if (it == groupDict.end())
	{
		shared_ptr<Group> group(new Group(_name));
		groupDict[_name] = group;
	}
	// Message if it already is
	else { cout << "This group already exists, try another name." << endl; }
	return groupDict[_name];
}

shared_ptr<BaseClass> Manager::findObj(string _name) const
{
	// Checking if item exists in media map
	auto it = objDict.find(_name);
	// If it does...
	if (it != objDict.end())
	{
		return it->second;
	}
	// If not...
	else
	{
		cout << "Object not found" << endl;
		return nullptr;
	}
}

shared_ptr<Group> Manager::findGroup(string _name) const
{
	// Checking if item exists in group map
	auto it = groupDict.find(_name);
	// If it does...
	if (it != groupDict.end())
	{
		return it->second;
	}
	// If not...
	else
	{
		cout << "Group not found" << endl;
		return nullptr;
	}
}

void Manager::playObj(string _name) const
{
	shared_ptr<BaseClass> media = findObj(_name);
	// If it exists...
	if (media != nullptr) { media->play(); }
	// If not...
	else { cout << "Object not found" << endl; }
}


bool Manager::processRequest(TCPConnection& cnx,const string &request, string &response)
{
	cerr << "\nRequest: '" << request << "'" << endl;

	// Request parsing
	string action, _name;
	stringstream str;
	str << request;
	str >> action;
	str >> _name;

	// Locking ressources
	TCPLock lock(cnx);

	// Treating request
	stringstream answer_str;
	bool searched, played;
	shared_ptr<BaseClass> search_obj;
	shared_ptr<Group> search_grp;
	searched = false;
	played = false;
	if (action == "search")
	{
		shared_ptr<BaseClass> obj = findObj(_name);
		if (obj != nullptr){
			obj->displayMethod(answer_str);
			searched = true;
		}
		else {
			shared_ptr<Group> grp = findGroup(_name);
			if(grp != nullptr){
				grp->displayMethod(answer_str);
				searched = true;
			}
		}
	}
	if (action == "play") { playObj(_name) ; }

	// Sending response
	if (played || searched)
		response = answer_str.str();
	else
		response = "Error : no such file";
	cerr << "response: " << response << endl;

	return true;
}