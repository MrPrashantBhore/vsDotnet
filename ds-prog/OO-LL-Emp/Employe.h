
#ifndef __EMPLOYE_H__
#define __EMPLOYE_H__
#include <iostream>
#include <ostream>
using namespace std;

class Employe
{
	char *name;
	int id;
	
public:
	Employe(const char *str, int id);
	~Employe();
	void operator=(Employe &x);
	Employe(Employe &x);
	bool isSameId(Employe &x);
	bool isSameName(Employe &x);
	bool operator==(Employe &x);
	friend ostream& operator<<(ostream& out, Employe& x);
	char * getName() {return name;}
	int getID() {return id;}
};

#endif

