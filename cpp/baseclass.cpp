#include "pch.h"
#include "baseclass.h"
using namespace std;

string BaseClass::getName() const
{
	return name;
}

string BaseClass::getPath() const
{
	return path;
}

void BaseClass::displayMethod(ostream& stream) const
{
	stream << "->Name : '" << name << "' Path : '" << path << "' ";
}
