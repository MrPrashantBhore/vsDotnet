
#include "Employe.h"
#include <cstring>

Employe::Employe(const char *str, int id)
{	
	name = new char[strlen(str) + 1];
	strcpy(name, str);
	name[strlen(str)]='\0';
	this->id = id;
}

Employe::~Employe()
{	
	delete [] this->name;
}

void Employe::operator=(Employe &x)
{
	if(this != &x)
	{
		delete [] this->name;	
		this->name = new char[strlen(x.name)+1];
		strcpy(this->name, x.name);
		this->name[strlen(x.name)]='\0';	
		this->id = x.id;
	}
	
}

bool Employe::isSameId(Employe &x)
{
		if(this->id == x.id)
			return true;
		
		return false;
}

bool Employe::isSameName(Employe &x)
{
		if( !strcmp(this->name,x.name) )
			return true;
		
		return false;
}

bool Employe::operator==(Employe &x)
{
		if( !strcmp(this->name,x.name) )
		{
			if(this->id == x.id)
			return true;
		}
		return false;
}

Employe::Employe(Employe &x)
{
		this->name = new char[strlen(x.name)+1];
		strcpy(this->name, x.name);
		this->name[strlen(x.name)]='\0';	
		this->id = x.id;
}

ostream& operator<<(ostream& out, Employe& x)
{
	out<<"Emp Name:"<<x.name<<", Emp ID:"<<x.id;
	return out;
}


