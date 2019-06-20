

#ifndef __LL_H__
#define __LL_H__

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList
{
	
	class Node
	{
	
		public:	
		int data;
		Node* next;
		
			
		Node();	
		~Node();		
		friend ostream& operator<<(ostream& out, LinkedList::Node& x);
				
		Node* getNext()
		{
			return next;
		}
	};
	
	Node* head;
	void deleteAll(); 
	void _RPrint(Node *ptr);
	
	
 
public:
	LinkedList();
	~LinkedList();
	LinkedList(LinkedList&);
	void operator=(LinkedList&);
	void insert(int adata);
	void append(int adata);
	friend ostream& operator<<(ostream& out, LinkedList& x);
	friend ostream& operator<<(ostream& out, LinkedList::Node& x);
	void RPrint(); 
	
	void deleteFirst();
	void deleteLast();
	void insertByPos(int adata, int pos);
	void deleteByPos(int adata, int pos);
	void reverse();
		
};

#endif


