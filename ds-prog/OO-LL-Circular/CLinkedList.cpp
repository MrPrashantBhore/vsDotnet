#include "CLinkedList.h"

ostream& operator<<(ostream& out, CLinkedList& x)
{
	Node * it = x.head;
	do
	{
		out<<*it<<"-->";
		it=it->getNext();
		
	}while(it != x.head);
	return out;
}

CLinkedList::CLinkedList() 
{
	head=NULL;
}

CLinkedList::~CLinkedList() 
{
	//LL empty?
	deleteAll();	
}

CLinkedList::CLinkedList(CLinkedList& x)
{
	//CLinkedList l2=l1
	///this == l2
	/// x == l1	
	
	this->head=NULL;
	
	Node * it = x.head;
	do
	{
		this->append(it->getData());
		it=it->getNext();
				
	}while(it != x.head);
		
}


void CLinkedList::operator=(CLinkedList& x)
{
	//l2=l1
	///this == l2
	/// x == l1	
	this->deleteAll();
	this->head=NULL;
	
	Node * it = x.head;
	do
	{
		this->append(it->getData());
		it=it->getNext();
				
	}while(it != x.head);	
}

void CLinkedList::deleteAll() 
{
	if(head != NULL)
	{
		Node *tmp = head->getNext();
		while(tmp!=head)
		{
			Node * it = tmp;	
			tmp=tmp->getNext();
			delete it;
		}
		head=NULL;
		delete tmp;	
	}	
}

void CLinkedList::insert(int adata)
{
	Node* tmp = new Node();	
	tmp->setData(adata);
	tmp->setNext(head);
	
	//first node????
	if(head==NULL)
	{
		head=tmp;
		head->setNext(head);			
	}
	else
	{
		tmp->setNext(head->getNext());
		//Swap;
		int t=head->getData();
		head->setData(tmp->getData());
		tmp->setData(t);		
		////
		head->setNext(tmp);
	}
}


void CLinkedList::deleteFirst()
{
	//check for empty LL...
	if(head != NULL)
	{
		//Only opne node..>?
		if(head->getNext() == head)
		{
			Node *tmp = head;
			head=NULL;
			delete tmp;
		}
		else
		{
			Node *tmp = head->getNext();
			//Swap;
			int t=head->getData();
			head->setData(tmp->getData());
			tmp->setData(t);		
			////

			head->setNext(tmp->getNext());
			delete tmp;		
		}
	
	}
}

void CLinkedList::deleteLast()
{
	//check for empty LL...
	if(head != NULL)
	{
		//Only opne node..>?
		if(head->getNext() == head)
		{
			Node *tmp = head;
			head=NULL;
			delete tmp;
		}
		else
		{
			Node *it = head;
			while(it->getNext()->getNext() != head)
			{
				//it=it->next;
				//it=it->getNext();
				it=(*it)++;		
			}
				
				
				
				
			Node *tmp = it->getNext();
			it->setNext(head);
			delete tmp;		
		}
	
	}
}


void CLinkedList::append(int adata)
{
	Node* tmp = new Node();	
	tmp->setData(adata);
	tmp->setNext(head);
	
	//first node????
	if(head==NULL)
	{
		head=tmp;
		head->setNext(head);
	}
	else
	{
		tmp->setNext(head->getNext());
		//Swap
		int t=head->getData();
		head->setData(tmp->getData());
		tmp->setData(t);
		///
		head->setNext(tmp);
		head=tmp;
	}	
}

