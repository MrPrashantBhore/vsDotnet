#include "LinkedList.h"

ostream& operator<<(ostream& out, LinkedList& x)
{
	LinkedList::Node * it = x.head;
	while(it != NULL)
	{
		out<<*it<<"-->";
		it=it->getNext();
	}	
	return out;
}

LinkedList::LinkedList() 
{
	head=NULL;
}

LinkedList::~LinkedList() 
{
	//LL empty?
	while(head != NULL)
	{
		LinkedList::Node * it = head;	
		head=head->getNext();
		delete it;
	}	
}

LinkedList::LinkedList(LinkedList& x)
{
	//LinkedList l2=l1
	///this == l2
	/// x == l1	
	
	this->head=NULL;
	
	LinkedList::Node *it = x.head;
	while(it != NULL)
	{
		this->append(it->data);
		it=it->getNext();
	}	
}


void LinkedList::operator=(LinkedList& x)
{
	//l2=l1
	///this == l2
	/// x == l1	
	this->deleteAll();
	this->head=NULL;
	
	LinkedList::Node *it = x.head;
	while(it != NULL)
	{
		this->append(it->data);
		it=it->getNext();
	}	
}

void LinkedList::deleteAll() 
{
	//LL empty?
	while(head != NULL)
	{
		LinkedList::Node * it = head;	
		head=head->getNext();
		delete it;
	}
	
	head=NULL;	
}

void LinkedList::insert(int adata)
{
	LinkedList::Node* tmp = new LinkedList::Node();	
	tmp->data = adata;
	tmp->next=NULL;
	
	//first node????
	if(head==NULL)
	{
		head=tmp;			
	}
	else
	{
		tmp->next=head;
		head=tmp;	
	}
}

void LinkedList::deleteFirst()
{
	//check for empty LL...
	if(head != NULL)
	{
		LinkedList::Node *tmp = head;
		//Only one node?
		if(head->next == NULL)
			head = NULL;
		else
			head = tmp->next;
		
		delete tmp;		
	}
}

void LinkedList::deleteLast()
{
	//check for empty LL...
	if(head != NULL)
	{
		//Only one node?
		if(head->next == NULL)
		{
			LinkedList::Node *tmp = head;
			head = NULL;
			delete tmp;
		}			
		else
		{
			LinkedList::Node *it = head;
			while(it->next->next != NULL)
			{
				it=it->getNext();
			}
			
			//we reached last but one node of linkedlist..			
			LinkedList::Node *tmp = it->next;
			it->next = NULL;
			delete tmp;
		}
	}
}


void LinkedList::append(int adata)
{
	LinkedList::Node* tmp = new LinkedList::Node();
	tmp->data = adata;
	tmp->next = NULL;
	
	if(head==NULL)
	{
		head=tmp;
	}
	else
	{
		LinkedList::Node * it = head;
		while(it->next != NULL)
		{
			it=it->next;
		}
		it->next = tmp;
		tmp->next = NULL;
	}		
}

void LinkedList::RPrint() 
{
	_RPrint(head);
}

void LinkedList::_RPrint(LinkedList::Node *ptr) 
{
	if(ptr->next != NULL)
		_RPrint(ptr->next);
	
	cout<<*ptr<<"-->";
}

void LinkedList::reverse() 
{
	Node *it = head;
	LinkedList::Node *itn = head;
	LinkedList::Node *itp = NULL;
	while(it != NULL)
	{
		itn=it->next;
		it->next = itp;
		itp=it;
		it=itn;
	}
	head=itp;
}

ostream& operator<<(ostream& out, LinkedList::Node& x)
{
	out<<x.data;
}

LinkedList::Node::Node()
{
	
}

LinkedList::Node::~Node()
{
	
}















































































void LinkedList::insertByPos(int adata, int pos)
{}

void LinkedList::deleteByPos(int adata, int pos)
{}





