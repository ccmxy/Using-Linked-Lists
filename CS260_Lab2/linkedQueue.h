#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "data.h"
class queue
{
public:
	queue(); //default constructor 
	queue(char *fileName); //constructor with fileName passed in
	queue(const queue& aQueue); //copy constructor
	~queue(); //destructor

	//access functions
	bool isEmpty(void)const;
	void display() const;

	//mutator functions
	bool enqueue(const data&);
	bool dequeue(data&);

private:
	struct node
	{
		data item; //contains the house data
		node *next; //points to next node
	};
	node *front;
	node *rear; //most recently added node
};
#endif