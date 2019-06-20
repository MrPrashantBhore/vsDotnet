
#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
#include <ostream>

using namespace std;

class Node
{
	Node* prev;
	int data;
	Node* next;	
	
public:
	Node();	
	~Node();		
	friend ostream& operator<<(ostream& out, Node& x);	
	Node* getNext();
	Node* getPrev();
	int getData();
	void setData(int adata);
	void setPrev(Node* tmp);
	void setNext(Node* tmp);
};

#endif

