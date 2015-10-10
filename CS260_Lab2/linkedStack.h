#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "data.h"
class stack
{
public:
	stack(); //default constructor
	stack(const stack& aStack); //copy constructor
	~stack(); //destructor

	//accessor functions
	bool isEmpty(void)const;

	//mutator functions
	bool push(const data);
	bool pop(data&);

private:
	struct node
	{
		data item;
		node *next; //points to next node down from top of stack
	};
	node *top; //most recently added node
};
#endif
