#include "DLinkedList.h"
#include <cstdlib>

ostream& operator<<(ostream& out, DLinkedList& x)
{
	Node * it = x.head;
	while(it != NULL)
	{
		out<<*it<<"-->";
		it=it->getNext();
		//system("pause");
	}	
	return out;
}

DLinkedList::DLinkedList() 
{
	head=tail=NULL;
}

DLinkedList::~DLinkedList() 
{
	deleteAll();
}

DLinkedList::DLinkedList(DLinkedList& x)
{
	//DLinkedList l2=l1
	///this == l2
	/// x == l1	
	
	this->head=NULL;
	this->tail=NULL;
	
	Node *it = x.head;
	while(it != NULL)
	{
		this->append(it->getData());
		it=it->getNext();
	}	
}


void DLinkedList::operator=(DLinkedList& x)
{
	//l2=l1
	///this == l2
	/// x == l1	
	this->deleteAll();
	this->head=NULL;
	this->tail=NULL;
	
	Node *it = x.head;
	while(it != NULL)
	{
		this->append(it->getData());
		it=it->getNext();
	}	
}

void DLinkedList::deleteAll() 
{
	//LL empty?
	while(head != NULL)
	{
		Node * it = head;	
		head=head->getNext();
		delete it;
	}
	
	head=tail=NULL;	
}

void DLinkedList::insert(int adata)
{
	Node* tmp = new Node();	
	tmp->setData(adata);
	tmp->setNext(NULL);
	tmp->setPrev(NULL);
	
	//first node????
	if(head==NULL)
	{
		head=tail=tmp;			
	}
	else
	{
		tmp->setNext(head);
		head->setPrev(tmp);
		head=tmp;
	}
}

void DLinkedList::append(int adata)
{
	Node* tmp = new Node();	
	tmp->setData(adata);
	tmp->setNext(NULL);
	tmp->setPrev(NULL);
	
	//first node????
	if(head==NULL)
	{
		head=tail=tmp;			
	}
	else
	{
		tmp->setPrev(tail);
		tail->setNext(tmp);
		tail=tmp;
	}	
}


void DLinkedList::deleteFirst()
{
	//check for empty LL...
	if(head != NULL)
	{
		if(head==tail)
		{
			Node *tmp = head;
			head=tail=NULL;
			delete tmp;	
		}
		else
		{
			Node *tmp = head;
			head = tmp->getNext();
			head->setPrev(NULL);
			
			tmp->setNext(NULL);
			tmp->setPrev(NULL);
			delete tmp;	
		}		
	}
}

void DLinkedList::deleteLast()
{
		//check for empty LL...
	if(head != NULL)
	{
		if(head==tail)
		{
			Node *tmp = head;
			head=tail=NULL;
			delete tmp;	
		}
		else
		{
			Node *tmp = tail;
			tail = tmp->getPrev();
			tail->setNext(NULL);
			delete tmp;	
		}		
	}
}

void DLinkedList::RPrint() 
{
	Node * it = tail;
	while(it != NULL)
	{
		cout<<*it<<"-->";
		it=it->getPrev();
	}	
}

void DLinkedList::insertByPos(int adata, int pos)
{
	int count=0;
	
	Node*it = head;
	while(it != NULL)
	{
		count++;
		it=it->getNext();
	}

	if(pos == 1)
		insert(adata);
	else if(pos == count+1)
		append(adata);
	else if(pos<1 || pos > count+1)
	{
		char *err = new char[50];
		sprintf(err,"invalid pos:%d", pos);
		throw err;
	}		
	else
	{
		int x=pos-1;
		it = head;
		
		while(--x)
		{
			it = it->getNext();
		}
		
		///
		Node* tmp = new Node();	
		tmp->setData(adata);
		
		tmp->setNext(it->getNext());
		tmp->setPrev(it);
		
		it->setNext(tmp);
		tmp->getNext()->setPrev(tmp);		
	
	}

}

void DLinkedList::deleteByPos(int pos)
{
	int count=0;
	
	Node*it = head;
	while(it != NULL)
	{
		count++;
		it=it->getNext();
	}

	if(pos == 1)
		deleteFirst();
	else if(pos == count)
		deleteLast();
	else if(pos<1 || pos > count)
	{
		char *err = new char[50];
		sprintf(err,"invalid pos:%d", pos);
		throw err;
	}		
	else
	{
		int x=pos-1;
		it = head;
		
		while(--x)
		{
			it = it->getNext();
		}
		
		///
		//it->next->prev=
		Node *tmp = it->getNext();
		//it->getNext()->setPrev(it);
		it->setNext(tmp->getNext());
		tmp->getNext()->setPrev(it);
		
		tmp->setNext(NULL);
		tmp->setPrev(NULL);
		delete tmp;
	}
}

void DLinkedList::reverse()
{
	
	Node *it = head;
	
	while(it!=NULL)
	{
		//Node *tmp=it->next;
		//it->next = it=>prev;
		//it->prev=tmp;
		Node *tmp = it->getNext();
		it->setNext(it->getPrev());
		it->setPrev(tmp);
		
		it= tmp;
	}
	
	///
	it=head;
	head=tail;
	tail=it;
}





