// CIS 255 Assignment 11 and 12
// Sara Bellus 7/6/22

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "student.h"

using namespace std;

void loadStack(student *&top)
{
	ifstream infile;
	student *n;
	string fn, ln, standing;
	float gpa, credits;

	top = NULL;
	

	infile.open("Data.txt");

	while (!infile.eof())
	{
		infile >> fn >> ln >> gpa >> credits;
		n = new student;
		n->fName(fn);
		n->lName(ln);
		n->GPA(gpa);
		n->credits(credits);
		n->standing(credits);

		if (top == NULL)
			top = n;
		else
		{
			n->nxt_ptr = top;  // new student attaches to current top
			top = n; //top is reassigned to n
		}
	}
	infile.close();
}
void displayStack(student *top)
{
	student *n;

	if (top == NULL)
		cout << "The stack is empty." << endl;
	else
	{
		n = top;
		while (n != NULL)
		{
			cout << n->fName() << " " << n->lName() << endl;
			cout << n->GPA() << endl;
			cout << n->credits() << endl;
			cout << n->standing() << endl << endl;

			n = n->nxt_ptr;
		}
	}
}
int displayMenu()
{
	int opt;

	cout << endl;
	cout << "Enter an option, 1 - 4 below." << endl;
	cout << "1. Display Stack" << endl;
	cout << "2. Push" << endl;
	cout << "3. Pop" << endl;
	cout << "4. Exit" << endl;

	cin >> opt;

	return opt;
}
void push(student *&top)
{
	string fn, ln;
	float gpa, credits;
	student *n;

	cout << "Enter first name: ";
	cin >> fn;
	cout << "Enter last name: ";
	cin >> ln;
	cout << "Enter GPA: ";
	cin >> gpa;
	cout << "Enter number of credits: ";
	cin >> credits;

	n = new student;
	n->fName(fn);
	n->lName(ln);
	n->GPA(gpa);
	n->credits(credits);
	n->standing(credits);

	n->nxt_ptr = top;  // new student, n, attaches a pointer to top
	top = n;   // new student becomes the top.
}
void pop(student *&top)
{
	student *c;

	if (top == NULL)
	{
		cout << "Stack is empty." << endl;
		c = NULL;
	}

	else
	{
		c = top;
		top = top->nxt_ptr;
		delete c;
	}
}

int main()
{
	student *top;
	string sName;
	int opt;
	top = NULL;

	loadStack(top);

	opt = displayMenu();

	while (opt != 4)
	{
		if (opt == 1)
			displayStack(top);
		else if (opt == 2)
			push(top);
		else if (opt == 3)
			pop(top);
		cout << endl;

		opt = displayMenu();
	}

	system("pause");
	return 0;
}

