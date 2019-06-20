

#ifndef __LL_H__
#define __LL_H__

#include <iostream>
#include "Node.h"

using namespace std;

class CLinkedList
{
	Node* head;
	void deleteAll(); 
	
	
public:
	CLinkedList();
	~CLinkedList();
	CLinkedList(CLinkedList&);
	void operator=(CLinkedList&);
	
	void insert(int adata);
	void append(int adata);
	friend ostream& operator<<(ostream& out, CLinkedList& x);
	
	void deleteFirst();
	void deleteLast();
	
		
};

#endif


