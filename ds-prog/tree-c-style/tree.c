#include <stdio.h>
#include <stdlib.h>

struct _Node
{
	struct _Node *left;
	int data;
	struct _Node *right;
};
typedef struct _Node Node;
Node * root=NULL;

void insert(Node* rootPtr, int adata)
{
	Node *tmp = (Node*) malloc(sizeof(Node));
	tmp->data = adata;
	tmp->left=NULL;
	tmp->right=NULL;
	
	//First Node?
	if(root == NULL)
	{
		root=tmp;
		return;
	}
	
	if(adata < rootPtr->data)
	{
		//left sub-tree
		if(rootPtr->left != NULL)
		{
			free(tmp);
			insert(rootPtr->left, adata);
		}			
		else
			rootPtr->left = tmp;		
	}
	else if(adata > rootPtr->data)
	{
		//right sub-tree
		if(rootPtr->right != NULL)
		{
			free(tmp);
			insert(rootPtr->right, adata);
		}			
		else
			rootPtr->right = tmp;
	}
	else
	{
		free(tmp);		
	}	
		
}

void preorder(Node* rootPtr)
{
	if(rootPtr != NULL)
	{
		printf("%d,", rootPtr->data);
		preorder(rootPtr->left);
		preorder(rootPtr->right);	
	}
}


void inorder(Node* rootPtr)
{
	if(rootPtr != NULL)
	{
		inorder(rootPtr->left);
		printf("%d,", rootPtr->data);
		inorder(rootPtr->right);	
	}
}


void postorder(Node* rootPtr)
{
	if(rootPtr != NULL)
	{
		postorder(rootPtr->left);
		postorder(rootPtr->right);	
		printf("%d,", rootPtr->data);
	}
}

int getMinValue(Node* rootPtr)
{
	if(rootPtr != NULL)
	{
		if(rootPtr->left != NULL)
			return getMinValue(rootPtr->left);
		else
			return rootPtr->data;	
	}
	return 0;	
}


Node* getMinValueNode(Node* rootPtr)
{
	if(rootPtr != NULL)
	{
		if(rootPtr->left != NULL)
			return getMinValueNode(rootPtr->left);
		else
			return rootPtr;	
	}
	return 0;	
}

int getMaxValue(Node* rootPtr)
{
	if(rootPtr != NULL)
	{
		if(rootPtr->right != NULL)
			return getMaxValue(rootPtr->right);
		else
			return rootPtr->data;	
	}
	return 0;
}

void freenodes(Node *rootPtr)
{
	if(rootPtr != NULL)
	{
		freenodes(rootPtr->left);
		freenodes(rootPtr->right);	
		free(rootPtr);
	}
	root=NULL;		
}

Node* deleteNode(Node *rootPtr, int value)
{
	if(rootPtr != NULL)	
	{
		if(value < rootPtr->data)
		{
			rootPtr->left = deleteNode(rootPtr->left, value);
		}
		else if(value > rootPtr->data)
		{
			//TODO
			rootPtr->right = deleteNode(rootPtr->right, value);
		}
		else
		{
			//we found the node.... now delete..
			if(rootPtr->left == NULL && rootPtr->right == NULL)
			{
				free(rootPtr);
				return NULL;
			}
			
			if(rootPtr->left == NULL)
			{
				Node *tmp = rootPtr->right;
				free(rootPtr);
				return tmp;
			}
			else if(rootPtr->right == NULL)
			{
				Node *tmp = rootPtr->left;
				free(rootPtr);
				return tmp;
			}
			else
			{
				// this node has both left and right nodes...
				// Now find mim value node from right side...
				Node * minValueNode = getMinValueNode(rootPtr->right);
				
				int tmpValue = rootPtr->data;
				rootPtr->data = minValueNode->data;
				minValueNode->data = tmpValue;
				
				rootPtr->right = deleteNode(rootPtr->right, value);
				
			}
		}
	}
	return rootPtr;
}

int main()
{
	
	insert(root, 4);
	insert(root, 10);
	insert(root, 1);
	insert(root, 6);
	insert(root, 20);
	insert(root, 8);
	insert(root, 9);
	insert(root, 15);	
	insert(root, -8);
	insert(root, 7);
	
	
	inorder(root);
	printf("\n");
	
	printf("Min Value: %d\n", getMinValue(root));
	printf("Max Value: %d\n", getMaxValue(root));
	
	
	deleteNode(root, 4);
	printf("After Delete\n");
	inorder(root);
	printf("\n");
	
	printf("Min Value: %d\n", getMinValue(root));
	printf("Max Value: %d\n", getMaxValue(root));
	system("pause");
	
	return 0;
}




