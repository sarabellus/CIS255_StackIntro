//
//  student.h
//  Assignment9and10

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class student
{
public:

	void fName(string fn);
	string fName();
	void lName(string ln);
	string lName();
	void GPA(float gpa);
	float GPA();
	void credits(float credits);
	float credits();
	void standing(float credits);
	string standing();

	student *nxt_ptr;

private:
	string p_fn, p_ln, p_st;
	float p_cr, p_gpa;
};

void student::fName(string fn)
{
	p_fn = fn;
}
string student::fName()
{
	return p_fn;
}
void student::lName(string ln)
{
	p_ln = ln;
}
string student::lName()
{
	return p_ln;
}
void student::GPA(float gpa)
{
	p_gpa = gpa;
}
float student::GPA()
{
	return p_gpa;
}
void student::credits(float credits)
{
	p_cr = credits;
}
float student::credits()
{
	return p_cr;
}
void student::standing(float credits)
{
	if (credits > 120)
		p_st = "Senior";
	else if (credits > 80)
		p_st = "Junior";
	else if (credits > 50)
		p_st = "Sophomore";
	else
		p_st = "Freshman";
}
string student::standing()
{
	return p_st;
}