
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
	
	Node* getNext() {return next;}
	int getData() {return data;}
	void setNext(Node* tmp) {next=tmp;}
	void setData(int adata) {data=adata;}
	
	Node* operator++(int);
};

#endif

