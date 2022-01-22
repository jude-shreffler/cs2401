// The implementation file for the MyTime class
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Constructors
MyTime::MyTime(){
	hours = 0;
	minutes = 0;
}

MyTime::MyTime(int h, int m){
	hours = h;
	minutes = m;
}

// Member and friend functions
void MyTime::Reset(int h, int m){
	hours = h;
	minutes = m;
}

void MyTime::simplify(){
    hours += minutes/60;
	minutes = minutes%60;
}

MyTime MyTime::operator + (const MyTime& t2) const {
	MyTime tmp;
    tmp.hours = hours + t2.hours;
	tmp.minutes = minutes + t2.minutes;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator - (const MyTime& t2) const {
	MyTime tmp;
	tmp.minutes = abs((hours*60+minutes) - (t2.hours*60+t2.minutes));
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator / (int num) const {
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes /= num;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator * (int num) const {
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes *= num;
	tmp.simplify();
	return tmp;
}

bool operator == (const MyTime& t1, const MyTime& t2){
	return t1.hours == t2.hours && t1.minutes == t2.minutes;
}

bool operator < (const MyTime& t1, const MyTime& t2){
	return (t1.hours*60 + t1.minutes) < (t2.hours*60 + t2.minutes);
}

bool operator <=(const MyTime& t1, const MyTime& t2){
	return (t1.hours*60 + t1.minutes) <= (t2.hours*60 + t2.minutes);
}

void MyTime::input(istream&ins){
	/* Move the implementation code from the >> operator show below here.
	   Remember that since this function will be a member now, there will not be a t1.

	   The >> operator should now call this function.
	   Remove the friend keyword from the operator in the .h file and move the
	   function prototype to after the class declaration.
	*/
}

void MyTime::output(ostream& outs){
	/* Repeat what you did for input except using the code for the << operator */
}


ostream& operator <<(ostream& outs, const MyTime& t1){
    outs << t1.hours << ':' << setw(2) << setfill('0') << t1.minutes;
	return outs;
}

istream& operator >> (istream& ins, MyTime& t1){
	char junk;
	ins >> t1.hours;
  	ins.get(junk);
	ins >> t1.minutes;
	t1.simplify();
	return ins;
}