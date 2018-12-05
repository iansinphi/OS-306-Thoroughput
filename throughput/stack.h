#pragma once
#include <iostream>
#include <cassert>

#include "node.h"

using namespace std;

class stack
{
public:
/*
constructor
*/
	stack()
	{
		headStack = nullptr;
	}

/*  
function: initializes stack by deleting the pointer node until there
are no elements remaining in the stack
*/
	void initStack()
	{
		Node *temp;

		while (headStack != nullptr)
		{
			temp = headStack;
			headStack = headStack->link;
			delete temp;

		}
	}
/*
function: adds to the stack, newData by creating a new Node and storing
newData in the Node.
*/
	void push(int newData)
	{
		Node *newNode;
		newNode = new Node;
		newNode->data = newData;
		newNode->link = headStack;
		headStack = newNode;
	}

/*
function: returns the first element of the stack.
*/
	int returnHead() const
	{
		assert(headStack != nullptr);
		return headStack->data;
	}

/*
function: pops the element of the top of the stack.
*/
	void pop()
	{
		Node *temp;

		if (headStack != nullptr)
		{
			temp = headStack;
			headStack = headStack->link;
			delete temp;
		}
	}

/*
function: boolean to determnine if a stack is empty.
*/

	bool emptyStack() const
	{
		return (headStack == nullptr);
	}

/*
function: boolean to determine if a stack is full.
*/

	bool fullStack() const
	{
		return false;
	}

// creation of the node headStack

private:
	Node * headStack;
};