
#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <ostream>
#include "Employe.h"

using namespace std;

class Node
{
	Employe data;
	Node* next;
	
public:
	Node(const char* a_name, const int a_id);	
	~Node();		
	friend ostream& operator<<(ostream& out, Node& x);	
	friend class LinkedList;
	Node* getNext()
	{
		return next;
	}
};

#endif

