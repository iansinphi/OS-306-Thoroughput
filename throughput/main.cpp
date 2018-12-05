#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

#include "stack.h"
#include "queue.h"
#include "priority.h"
#include "node.h"

using namespace std;

const int h = 100;

void fill(int[], int[], int[], int[], int[]);
void print(int[], int, ofstream&);
void oneRegister(int[], int[], int[], int[], int[], ofstream&, ofstream&, ofstream&, ofstream&);
void fourRegister(int[], int[], int[], int[], int[], ofstream&, ofstream&, ofstream&, ofstream&);


int main()
{

//seeds time to random

	srand(time(NULL));

//declaration for the arrays

	int *a = new int[h];
	int *b = new int[h];
	int *c = new int[h];
	int *d = new int[h];
	int *p = new int[h];

// creates opens the text files for the output

	ofstream lifoFile;
	ofstream fifoFile;
	ofstream sortFile;
	ofstream prioFile;
	lifoFile.open("lifoFile.txt");
	fifoFile.open("fifoFile.txt");
	sortFile.open("sortFile.txt");
	prioFile.open("prioFile.txt");

/*
One Register Simulation------------------------------------------------------------------------------
*/

//constructors

	stack();
	queue();

	fill(a, b, c, d, p);

	lifoFile << "**********FIRST RUN**********" << endl << endl;
	fifoFile << "**********FIRST RUN**********" << endl << endl;
	sortFile << "**********FIRST RUN**********" << endl << endl;
	prioFile << "**********FIRST RUN**********" << endl << endl;

	print(a, 1, lifoFile);
	print(b, 2, fifoFile);
	print(c, 3, sortFile);
	print(d, 4, prioFile);

	print(p, 5, prioFile);


	oneRegister(a, b, c, d, p, lifoFile, fifoFile, sortFile, prioFile);

/*
----------------------------------------------------------------------------------------------------
*/

/*
Four Register Simulation----------------------------------------------------------------------------
*/

//constructors

	stack();
	queue();

	fill(a, b, c, d, p);

	lifoFile << endl << "**********RUN 2**********" << endl << endl;
	fifoFile << "**********RUN 2**********" << endl << endl;
	sortFile << "**********RUN 2**********" << endl << endl;
	prioFile << "**********RUN 2**********" << endl << endl;

	print(a, 1, lifoFile);
	print(b, 2, fifoFile);
	print(c, 3, sortFile);
	print(d, 4, prioFile);
	
	print(p, 5, prioFile);

	fourRegister(a, b, c, d, p, lifoFile, fifoFile, sortFile, prioFile);

/*
----------------------------------------------------------------------------------------------------
*/

	lifoFile.close();
	fifoFile.close();
	sortFile.close();
	prioFile.close();

	return 0;
}

/*
function: fills the array with random numbers
*/

void fill(int a[], int b[], int c[], int d[], int p[])
{

	for (int i = 0; i < h; i++)
	{
		a[i] = rand() % (100 - 0) + 0;
		b[i] = rand() % (100 - 0) + 0;
		c[i] = rand() % (100 - 0) + 0;
		d[i] = rand() % (100 - 0) + 0;

		p[i] = rand() % (3 - 0) + 1;
	}
}

/*
function: prints the arrays
*/

void print(int a[], int i, ofstream &outFile)
{
	int column = 10;

	if (i != 5)
	{
		outFile << "**********Array********** " << i << endl;
	}
	else
	{
		outFile << "**********Priority Array********** " << endl;
	}

	for (int i = 0; i < h; i++)
	{
		outFile << setw(4) << a[i] << setw(4);

		if ((i + 1) % column == 0)
		{
			outFile << endl;
		}
	}
	outFile << endl << endl;
}

/*
function: One Register with a clock cycle
*/

void oneRegister(int a[], int b[], int c[], int d[], int p[], ofstream &lifoFile, ofstream &fifoFile, ofstream &sortFile, ofstream &prioFile)
{
	int column = 10;
	int inRegister = 0;
	int outRegister = 0;
	int inClock = 0;
	int outClock = 0;

	stack newStack;
	queue newQueue;
	queue newSorted;
	priority newPriority;

	lifoFile << "**********LIFO**********" << endl;
	fifoFile << "**********FIFO**********" << endl;
	sortFile << "**********Sorted**********" << endl;


//adds the first ten elements

	for (int i = 0; i < column; i++)
	{
		newStack.push(a[i]);
		inClock++;

		newQueue.insertHead(b[i]);
		inClock++;

		newSorted.insertSort(c[i]);
		inClock++;

		newPriority.insertPriority(d[i], p[i]);
		inClock++;
	}


//adds the remaining elements

	for (int j = column; j < h; j++)
	{

//adds elements for the lifo-------------------------------------------

		inRegister = a[j];
		outRegister = newStack.returnHead();
		outClock++;

		newStack.pop();
		newStack.push(inRegister);
		inClock++;

		lifoFile << setw(2) << outRegister << setw(2) << " ";

		if ((j + 1) % column == 0)
		{
			lifoFile << endl;
		}

//------------------------------------------------------------------------

//adds elements for fifo--------------------------------------------------

		inRegister = b[j];
		outRegister = newQueue.head();
		outClock++;

		newQueue.deleteQueue();
		newQueue.insertHead(inRegister);
		inClock++;

		fifoFile << setw(2) << outRegister << setw(2) << " ";

		if ((j + 1) % column == 0)
		{
			fifoFile << endl;
		}

//------------------------------------------------------------------------

//adds elements for sorted------------------------------------------------

		inRegister = c[j];
		outRegister = newSorted.head();
		outClock++;

		newSorted.deleteQueue();
		newSorted.insertSort(inRegister);
		inClock++;

		sortFile << setw(2) << outRegister << setw(2) << " ";

		if ((j + 1) % column == 0)
		{
			sortFile << endl;
		}

//--------------------------------------------------------------------------

//adds elements for priority------------------------------------------------

		inRegister = d[j];
		outRegister = newPriority.priorityHead();
		outClock++;

		newPriority.deleteQueue();
		newPriority.insertPriority(inRegister, p[j]);
		inClock++;
	}

//--------------------------------------------------------------------------

//adds the last ten elements------------------------------------------------

	for (int i = 0; i < column; i++)
	{
		outRegister = newStack.returnHead();
		outClock++;

		newStack.pop();

		lifoFile << setw(2) << outRegister << setw(2) << " ";

		outRegister = newQueue.head();
		outClock++;

		newQueue.deleteQueue();

		fifoFile << setw(2) << outRegister << setw(2) << " ";

		outRegister = newSorted.head();
		outClock++;

		newSorted.deleteQueue();

		sortFile << setw(2) << outRegister << setw(2) << " ";

		outRegister = newPriority.priorityHead();
		outClock++;

		newPriority.deleteQueue();
	}

//prints the clock cycle

	newPriority.printPriority(prioFile);

	lifoFile << endl << endl;
	lifoFile << endl << "Clock In: " << inClock << endl;
	lifoFile << "Clock Out: " << outClock << endl << endl;

	fifoFile << endl << endl;
	fifoFile << endl << "Clock In: " << inClock << endl;
	fifoFile << "Clock Out: " << outClock << endl << endl;

	sortFile << endl << endl;
	sortFile << endl << "Clock In: " << inClock << endl;
	sortFile << "Clock Out: " << outClock << endl << endl;

	prioFile << endl << endl;
	prioFile << endl << "Clock In: " << inClock << endl;
	prioFile << "Clock Out: " << outClock << endl << endl;
}


//function: four registers with a clock cycle

void fourRegister(int a[], int b[], int c[], int d[], int p[], ofstream &lifoFile, ofstream &fifoFile, ofstream &sortFile, ofstream &prioFile)
{

	int column = 10;

	int inOne = 0;
	int inTwo = 0;
	int inThree = 0;
	int inFour = 0;

	int outOne = 0;
	int outTwo = 0;
	int outThree = 0;
	int outFour = 0;

	int inClock = 0;
	int outClock = 0;

	stack newStack;
	queue newQueue;
	queue newSorted;
	priority newPriority;

	lifoFile << "**********LIFO**********" << endl;
	fifoFile << "**********FIFO**********" << endl;
	sortFile << "**********Sorted**********" << endl;

//adds the first ten elements

	for (int i = 0; i < column; i++)
	{
		newStack.push(a[i]);
		newQueue.insertHead(b[i]);
		newSorted.insertSort(c[i]);
		newPriority.insertPriority(d[i], p[i]);
		inClock++;
	}


//adds the remaining elements

	for (int j = column; j < h; j++)
	{
		inOne = a[j];
		inTwo = b[j];
		inThree = c[j];
		inFour = d[j];

		outOne = newStack.returnHead();
		outTwo = newQueue.head();
		outThree = newSorted.head();
		outFour = newPriority.priorityHead();
		outClock++;

		newStack.pop();
		newQueue.deleteQueue();
		newSorted.deleteQueue();
		newPriority.deleteQueue();

		newStack.push(inOne);
		newQueue.insertHead(inTwo);
		newSorted.insertSort(inThree);
		newPriority.insertPriority(inFour, p[j]);
		inClock++;

		lifoFile << setw(2) << outOne << setw(2) << " ";
		fifoFile << setw(2) << outTwo << setw(2) << " ";
		sortFile << setw(2) << outThree << setw(2) << " ";

		if ((j + 1) % column == 0)
		{
			lifoFile << endl;
			fifoFile << endl;
			sortFile << endl;
			prioFile << endl;
		}
	}



//adds the last ten elements

	for (int i = 0; i < column; i++)
	{
		outOne = newStack.returnHead();
		outTwo = newQueue.head();
		outThree = newSorted.head();
		outFour = newPriority.priorityHead();
		outClock++;

		newStack.pop();
		newQueue.deleteQueue();
		newSorted.deleteQueue();
		newPriority.deleteQueue();

		lifoFile << setw(2) << outOne << setw(2) << " ";
		fifoFile << setw(2) << outTwo << setw(2) << " ";
		sortFile << setw(2) << outThree << setw(2) << " ";
	}


//prints the clock cycles

	newPriority.printPriority(prioFile);

	lifoFile << endl << endl;
	lifoFile << endl << "Clock In: " << inClock << endl;
	lifoFile << "Clock Out: " << outClock << endl << endl;

	fifoFile << endl << endl;
	fifoFile << endl << "Clock In: " << inClock << endl;
	fifoFile << "Clock Out: " << outClock << endl << endl;

	sortFile << endl << endl;
	sortFile << endl << "Clock In: " << inClock << endl;
	sortFile << "Clock Out: " << outClock << endl << endl;

	prioFile << endl << endl;
	prioFile << endl << "Clock In: " << inClock << endl;
	prioFile << "Clock Out: " << outClock << endl << endl;
}