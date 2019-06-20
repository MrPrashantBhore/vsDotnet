
#ifndef __LL_H__
#define __LL_H__

#include <iostream>
#include "Node.h"

using namespace std;

class DLinkedList
{
	Node* head;
	Node* tail;
	void deleteAll(); 
	void _RPrint(Node *ptr); 
public:
	DLinkedList();
	~DLinkedList();
	DLinkedList(DLinkedList&);
	void operator=(DLinkedList&);
	void insert(int adata);
	void append(int adata);
	friend ostream& operator<<(ostream& out, DLinkedList& x);
	void RPrint(); 
	
	void deleteFirst();
	void deleteLast();
	void insertByPos(int adata, int pos);
	void deleteByPos(int pos);
	void reverse();
		
};

#endif


