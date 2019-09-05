#include <string>
#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H

using namespace std;

class clockType
{
public:
	int hour;
	int min;
	string AP; // stores AM or PM

public:
	clockType();
	// default constructor
	// sets hour = 0
	// sets minute = 0
	// sets AP = AM

	clockType(int hr, int mn, string tm);
	// constructor
	// sets hour = hr
	// sets min = mn
	// sets AP = tm

	void set_time(int hr, int mn, string tm);
	// sets hour = hr
	// sets min = mn
	// sets AP = tm

	string get_AP();

	void print(ofstream& file);
	// prints time in format hr:min AP

	clockType operator+(clockType b);
	// returns sum of two times
	// the AM or PM of returned time does depends only on AM or PM or first operand

	int operator-(clockType b);
	// returns the difference of two times in minutes

	clockType operator*(int i);
	// multiplies time by i

	bool operator>(clockType b);
	// returns true if first time is greater than second time otherwise false

	bool operator<(clockType b);
	// returns true if first time is smaller than second time otherwise false

	bool operator==(clockType b);
	// returns true if both times are equal

};

#endif
