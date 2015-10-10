#include "linkedstack.h"
#include <fstream>
#include <cassert>

/*
Default constructor.
*/
stack::stack()
{
	top = NULL;
}

/*
Deep copy constructor.
*/
stack::stack(const stack& aStack)
{
	if (aStack.top == NULL)
		top = NULL;
	else
	{
		top = new node;
		assert(top != NULL); //check allocation
		top->item = aStack.top->item;

		//copy the rest of the list
		node *destNode = top; //points to the last node in new stack
		node *srcNode = aStack.top->next;  //points to node in aStack
		while (srcNode != NULL) //or while (srcNode)
		{
			destNode->next = new node;
			assert(destNode->next != NULL); //check allocation
			destNode = destNode->next;
			destNode->item = srcNode->item;

			srcNode = srcNode->next;
		}
		destNode->next = NULL;
	}
}

/*
Destructor.
*/
stack::~stack()
{
	node * curr = top;
	while (top)
	{
		curr = top->next;
		delete top;
		top = curr;
	}
	top = NULL;
}

/*
Adds item to top of stack.
*/
bool stack::push(const data aData)
{
	node *newNode = new node;
	newNode->item = aData; //the new node's "data" member now contains the address of the passed in data item
	newNode->next = NULL;
	newNode->next = top; //the new node's member next now points to whatever node is at the top (the last node that was added)
	top = newNode; //top now points to the new node
	return true;
}

/*
Assigns the passed in data object to the "item" member of the top of the stack, and removes the top node from the stack.
*/
bool stack::pop(data& aData)
{
	node *temp;
	if (isEmpty() == true)
		return false; //return false if nothing to pop off of stack
	else
	{
		aData = top->item; //aData is assigned to top's member, item
		temp = top;  //the temp node now points to the top node
		top = top->next; //top now points to the node that was being pointed to by top's member next.
		delete temp; //the previous top is deleted.
		return true;
	}
}

/*
Checks if stack is empty.
Returns true if stack is empty, false if not.
*/
bool stack::isEmpty() const
{
	return top == NULL; //if top == NULL, stack is empty
}
