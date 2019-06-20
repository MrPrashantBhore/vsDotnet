
#include "Node.h"

ostream& operator<<(ostream& out, Node& x)
{
	out<<x.data;
}

Node::Node(const char* a_name, const int a_id) : data(a_name,a_id)
{
	next=NULL;
}

Node::~Node()
{
	next=NULL;
}
	

