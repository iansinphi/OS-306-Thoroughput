#pragma once

#include <iostream>
#include <cassert>

#include "node.h"

using namespace std;

class queue
{
public:

/*
constructor
*/

	queue()
	{
		headQueue = nullptr;
		tailQueue = nullptr;
	}

/*
returns the element located at head
*/

	int head() const
	{
		assert(headQueue != nullptr);
		return headQueue->data;
	}

/*
returns the element located at tail
*/

	int tail() const
	{
		assert(tailQueue != nullptr);
		return tailQueue->data;
	}

/*
function: inserts newData at the head of the queue
*/

	void insertHead(int newData)
	{
		Node *newNode;
		newNode = new Node;

		newNode->data = newData;
		newNode->link = nullptr;

		if (headQueue == nullptr)
		{
			headQueue = newNode;
			tailQueue = newNode;
		}
		else
		{
			tailQueue->link = newNode;
			tailQueue = tailQueue->link;
		}
	}

/*
function: inserts newData, sorted, into the queue.
*/

	void insertSort(int newData)
	{
		Node *current;
		Node *trailCurrent = new Node;
		Node *newNode;

		bool found;

		newNode = new Node;
		newNode->data = newData;
		newNode->link = nullptr;

		if (headQueue == nullptr)
		{
			headQueue = newNode;
			tailQueue = newNode;
		}
		else
		{
			current = headQueue;
			found = false;

			while (current != nullptr && !found)
				if (current->data >= newData)
					found = true;
				else
				{
					trailCurrent = current;
					current = current->link;
				}
			if (current == headQueue)
			{
				newNode->link = headQueue;
				headQueue = newNode;
			}
			else
			{
				trailCurrent->link = newNode;
				newNode->link = current;

				if (current == nullptr)
					tailQueue = newNode;
			}
		}
	}

/*
function: deletes objects in the queue
*/

	void deleteQueue()
	{
		Node *temp;

		if (!emptyQueue())
		{
			temp = headQueue;
			headQueue = headQueue->link;
			delete temp;

			if (headQueue == nullptr)
				tailQueue = nullptr;
		}
	}

/*
boolean used to determine if the queue is empty
*/

	bool emptyQueue() const
	{
		return(headQueue == nullptr);
	}

/*
boolean used to determine if the queue is full
*/

	bool fullQueue() const
	{
		return false;
	}

private:
	Node *headQueue;
	Node *tailQueue;

	int counter;
};