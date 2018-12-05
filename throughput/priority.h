#pragma once
#include <iostream>
#include <cassert>
#include <iomanip>

#include "node.h"
#include "queue.h"

using namespace std;

class priority : public queue
{

public:

/*
function: inserts newData into the array in the order designated by the priority array
*/

	void insertPriority(int newData, int priority)
	{

		Node *temp = new Node;
		Node * newNode = new Node;
		temp->data = newData;
		temp->priority = priority;

		if (head == nullptr || priority < head->priority)
		{
			temp->link = head;
			head = temp;
		}
		else
		{
			newNode = head;
			while (newNode->link != nullptr && newNode->link->priority <= priority)
			{
				newNode = newNode->link;
			}

			temp->link = newNode->link;
			newNode->link = temp;
		}
	}


	int priorityHead() const
	{

		assert(head != nullptr);
		return head->data;

	}
	
/*
function: prints the priority array
*/

	void printPriority(ofstream &outFile)
	{
		int column = 0;
		Node *temp = new Node;
		temp = head;

		outFile << "**********Priority********** " << endl;

		if (head == nullptr)
		{
			outFile << "The queue is empty!" << endl;
		}
		else
		{

			while (temp != nullptr)
			{

				column++;
				outFile << setw(3) << temp->data << " " << setw(3);
				if ((column % 10) == 0)
				{
					outFile << endl;
				}
				temp = temp->link;
			}
		}
	}

private:

	Node * head;

};
