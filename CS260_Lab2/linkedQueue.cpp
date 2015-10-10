#include "linkedqueue.h"
#include <fstream>
#include <cassert>
#include <iomanip>

/*
Default constructor.
*/
queue::queue()
{
	front = NULL;
	rear = NULL;
}

/*
Constructor with filename char array passed in. 
Precondition: fileName is the name of a file in the program subdirectory. It contains data in this format: "address[a string];no. of bedrooms[an int]; no. of bathrooms [an int]; square feet [an int];special features [a string] \n"
Postcondition: A queue object is created and its member "front" points to the first node in a linear linked list of nodes. That node's data object "item" is filled with the data on the first line of the file. 
The front node's member "next" points to the next node and so on until the last line, which is pointed to by "rear."
*/
queue::queue(char *fileName)
{
	front = NULL;
	rear = NULL;
	ifstream in;
	data currData;
	char address[100];
	int bedrooms;
	int bathrooms;
	int squareFeet;
	char specialFeatures[100];

	in.open(fileName);
	if (in.good() != true)
	{
		cerr << "Could not open " << fileName << "." << endl;
		exit(1); //indicate that the program terminated with errors
	}

	in.get(address, 100, ';');
	while (in.eof() != true)
	{
		in.ignore(100, ';');
		in >> bedrooms;
		in.ignore(100, ';');
		in >> bathrooms;
		in.ignore(100, ';');
		in >> squareFeet;
		in.ignore(100, ';');
		in.get(specialFeatures, 100, '\n');
		in.ignore(100, '\n');

		currData.setAddress(address);
		currData.setBedrooms(bedrooms);
		currData.setBathrooms(bathrooms);
		currData.setSquareFeet(squareFeet);
		currData.setSpecialFeatures(specialFeatures);

		enqueue(currData); //New node added, pointed to by rear.
		in.get(address, 100, ';'); //retrieve address on next line before continuing the while loop
	}
	in.close();
}

/*
Makes a deep copy of the queue object, including the linked list of nodes. 
*/
queue::queue(const queue& aQueue)
{
	node *destNode;
	node *srcNode;

	this->front = NULL; //instance queue object
	this->rear = NULL;
	if (aQueue.front == NULL)
	{
		front = rear = NULL;
	}
	else
	{
		front = new node;
		assert(front != NULL); //check allocation. stops program during debug if the assertion is false. 
		front->item = aQueue.front->item; //possible because we overloaded = in data
		destNode = front; //points to the last node in new queue
		srcNode = aQueue.front->next;  //points to node in aQueue
		while (srcNode != NULL) //while srcNode points to something other than Null (end of queue not reached)
		{
			destNode->next = new node;
			assert(destNode->next != NULL); //check allocation. stops program during debug if the assertion is false. 
			destNode = destNode->next;
			destNode->item = srcNode->item; //overloading assignment operator for data objects
			srcNode = srcNode->next;
		}
		destNode->next = NULL;
		rear = destNode;
	}
}

/*
Destructor. Deletes queue object and its linked list of nodes. 
*/
queue::~queue()
{
	node *curr = front;
	while (front != NULL) //as long as end of list is not reached...
	{
		curr = front->next; //traverse list to delete full queue
		delete front;
		front = curr;
	}
	front = rear = NULL; 
}

/*
Checks if queue is empty. Returns true if empty, false if not.
*/
bool queue::isEmpty() const
{
	return front == NULL; //returns true if true, false if false
}

/*
Displays data item of each node in the queue.
*/
void queue::display() const
{
	node* curr;

	cout << "Data in the queue: " << endl << endl;
	cout << setw(23) << "|Address|" << setw(12) << "|Bed|" << setw(5) << "|Bth|" << setw(0) << "|Size|" << setw(18) << "|Notes|" << endl;
	for (curr = front; curr; curr = curr->next)
	{
		cout << '\t' << curr->item << endl; //operator overloader from data
	}
}

/*
Adds new node to end of queue.
Precondition: aData is a filled data object.
Postcondition: Rear points to a new queue object which has member "item" assigned to the data object passed into the function.
*/
bool queue::enqueue(const data& aData)
{
	node *newNode;
	newNode = new node;
	assert(newNode != NULL);
	newNode->item = aData;
	newNode->next = NULL;
	if (rear == NULL)
		front = rear = newNode;
	else
	{
		rear->next = newNode;
		rear = newNode;			//update rear
	}

	return true;
}

/*
Assigns data object to the item in the front node, deletes the front node.
*/
bool queue::dequeue(data& aData)
{
	node *temp;
	if (isEmpty() == true)
		return false;
	else
	{
		temp = front; //temp points to front of queue
		if (front == rear) //the only node
			front = rear = NULL;
		else
			front = front->next; //front points to the next item in the queue

		temp->next = NULL; //the old "front" now points to NULL
		aData = temp->item; //the data object is filled with the old front's member "item"
		delete temp; //the old front is deleted
		return true;
	}
}

