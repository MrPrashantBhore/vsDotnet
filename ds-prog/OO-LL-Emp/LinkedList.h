

#ifndef __LL_H__
#define __LL_H__

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList
{
	Node* head;
	void deleteAll(); 
	void _RPrint(Node *ptr); 
	void append(Employe &e);
public:
	LinkedList();
	~LinkedList();
	LinkedList(LinkedList&);
	void operator=(LinkedList&);
	void insert(const char* a_name, const int a_id);
	void append(const char* a_name, const int a_id);
	friend ostream& operator<<(ostream& out, LinkedList& x);
	void RPrint(); 
	
	void deleteFirst();
	void deleteLast();
	void insertByPos(const char* a_name, const int a_id, int pos);
	void deleteByPos(const char* a_name, const int a_id, int pos);
	void reverse();
	
	int getIDByName(const char *name);
	char* getNameByID(int id);
};

#endif


