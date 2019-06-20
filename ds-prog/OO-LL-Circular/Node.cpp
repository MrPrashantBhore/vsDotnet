
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

Node* Node::operator++(int)
{
		return next;
}
	

