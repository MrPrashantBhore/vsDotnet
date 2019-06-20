
#include "Node.h"

ostream& operator<<(ostream& out, Node& x)
{
	out<<x.data;
}

Node::Node()
{
	
}

Node::~Node()
{
	
}
	
Node* Node::getNext()
{
	return next;
}

Node* Node::getPrev()
{
	return prev;
}

void Node::setNext(Node* tmp)
{
	next = tmp;
}

void Node::setPrev(Node* tmp)
{
	prev = tmp;
}

int Node::getData()
{
	return data;
}

void Node::setData(int adata)
{
	data=adata;
}



