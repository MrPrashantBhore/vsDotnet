
#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <ostream>

using namespace std;


class Node
{
	int data;
	Node* next;
	
public:
	Node();	
	~Node();		
	friend ostream& operator<<(ostream& out, Node& x);	
	friend class LinkedList;
	Node* getNext()
	{
		return next;
	}
};

#endif

