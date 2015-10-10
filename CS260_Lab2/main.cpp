/*
Name: Colleen Minor
SSID: G02312462
Assignment: 2
Date: May 4, 2014
*/

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include "data.h"
#include "linkedstack.h"
#include "linkedqueue.h"
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char fileName[] = "data.dat";
	queue housesOnList(fileName);
	data house;
	stack houseInterested;
	char response;

	cout << "\nthe houses we will visit today:" << endl << endl;
	housesOnList.display();

	//the queue objects are dequed from the front and house is assigned the data item in each queue as we work down the list
	while (housesOnList.dequeue(house) == true)
	{
		cout << "\nnext house to be visited:" << endl << house << endl;
		cout << "\nWould you like to revisit this house on our way back? (y, n): ";
		cin >> response;
		cin.ignore(100, '\n');

		if (response == 'y' || response == 'Y')
		{
			cout << "\nthe house is saved for revisiting" << endl;
			houseInterested.push(house); //push item to top of stack
		}
	}

	cout << "\nWe have finished the first round of screening" << endl << endl;
	cout << "\nOn the way back to the office: " << endl << endl;

	while (houseInterested.pop(house) == true) //true as long as stack is not empty
	{
		cout << "\nnext house to be revisited: " << endl << house << endl;
	} 

	cout << "\nWe've finished the second round. ready to make an offer? (y, n):";
	cin >> response;
	cin.ignore(100, '\n');
	cout << "\nlet's talk about that in my office. " << endl << endl;
	return 0;

	_CrtDumpMemoryLeaks(); //dumps all the memory blocks in the debug heap when a memory leak has occurred
}

