#include "pch.h"
#include "film.h"

using namespace std;

void Film::setChaps(int *_duration_table, unsigned int _n_chaps)
{
	//Setting method defined similary in a similar way to the costructor.
	delete[] duration_table;
	n_chaps = _n_chaps;
	if (n_chaps != 0)
	{
		for (unsigned int i = 0; i < n_chaps; i++)
		{
			duration_table[i] = _duration_table[i];
		}
	}
}

void Film::displayMethod(ostream &stream) const
{
	BaseClass::displayMethod(stream);
	stream << "Class : 'Film';\nName: " <<getName()<< "\nPath: "<<getPath() << "\nDuration: "  << getDuration() << "\nNumber of Chapters: "<< getNumChap() <<"\n";
	for (unsigned int i = 0; i < n_chaps; ++i) {
		stream << "Chapter" << i << " : '" << duration_table[i] << "' ";
	}
	stream << endl;
}
