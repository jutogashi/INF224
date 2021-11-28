// INF224_TOGASHI_DE_MIRANDA_Julia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "baseclass.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "manager.h"

#include <list>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>

#include "tcpserver.h"

static const std::string HOST = "127.0.0.1";
static const int PORT = 3331;

using namespace std;


// MAIN USED FOR TESTS DURING THE PROJECT
/*
int main(int argc, const char* argv[])
{
	//Question 3 test
	cout << "Midias test (Question 3):" << endl;

	Video * v1 = new Video("Video1", "samples/video_1.flv",1);
	Photo * p1 = new Photo("Photo1", "samples/lena.tif",3,2);

	cout << v1->getName() <<endl;
	cout << v1->getDuration() << endl;
	v1->setDuration(2);
	cout << v1->getDuration() << endl;
	cout << p1->getName() <<endl;

	//Question 5 test
	cout << "\nTest of loop with polymorphism (Question 5):\n" << endl;

	// OO permits that thanks to polymorphism.
	BaseClass ** medias = new BaseClass *[2];

	medias[0] = v1;
	medias[1] = p1;

	for (int i = 0; i < 2; i++)
	{
		cout << "\nMedia " << i << " name: " << medias[i]->getName() << endl;
		cout << "Media " << i << " path: " << medias[i]->getPath() << "\n" << endl;
		medias[i]->play();
	}

	//avoiding memory leaks.
	delete p1;
	delete v1;
	delete[] medias;

	//Question 7 test
	cout << "\nTest of destruction and copying of objects (Question 7):\n" << endl;

	unsigned int n = 10;
	int * chaps = new int[n];

	for (unsigned int i = 0; i< n; i++)
	{
		chaps[i] = i;
	}

	//Creating new istance of a film object
	Film * f1 = new Film("film1", "samples/film1", 120, chaps, n);

	unsigned int n_chaps_f1 = f1->getNumChap();
	const int * chaps_f1 = f1->getChaps();

	cout << "Number of chapters is " << n_chaps_f1 << endl;
	cout << "Chapters: " << endl;

	for (unsigned int i = 0; i < n_chaps_f1; i++)
	{
		cout << chaps_f1[i] << "; ";
	}
	cout << endl;
	// This will call the film destructor.
	delete f1;
	//avoiding memory leaks.
	//delete chaps;

	//Question 8/9 Test
	cout << "\nTest of groups/ automatic memory management(Question 8/9):\n" << endl;

	shared_ptr<Video> v2(new Video("Video2", "samples/video_2.mkv", 1));
	shared_ptr<Photo> p2(new Photo("Photo2", "samples/cell.png", 3, 2));
	shared_ptr<Film> f2(new Film("film2", "samples/film2", 120, chaps, n));
	// Creating new group
	shared_ptr<Group> gr1(new Group("Test group 1"));
	
	// Putting elements in the group
	gr1->push_back(v2);
	gr1->push_back(p2);
	gr1->push_back(f2);

	if (gr1.use_count() != 0)
	{
		// Printing elements one by one, like in the display method
		cout << "print of group 1 : \n" << endl;
		for (auto & it : *gr1)
		{
			cout << "media name : " << it->getName() << endl;
		}
	}

	// if p is a smart pointer p.reset () makes sure that it no longer points to anything
	gr1.reset();

	//Checking if after reset the group still exists
	if (gr1.use_count() != 0) { cout << "group 1 is still here." << endl;}
	else { cout << "none left" << endl; }

}
*/


 //SERVER MAIN: Function copied from Server.cpp Version 1

int main(int argc, char* argv[])
{
  // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer());
  
  // cree l'objet qui gère les données
  shared_ptr<Manager> base(new Manager());

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*base, &Manager::processRequest);
  
  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);
  
  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }
  
  return 0;
}





