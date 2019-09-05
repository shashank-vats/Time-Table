#include <iostream>
#include "clockType.h"
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

clockType::clockType()
{
	hour = 0;
	min = 0;
	AP = "AM";
	//cout << "time object created" << endl;
	return;
}

clockType::clockType(int hr, int mn, string tm)
{
	hour = hr;
	min = mn;
	AP = tm;
	//cout << "time object created" << endl;
	return;
}

void clockType::set_time(int hr, int mn, string tm)
{
	//cout << "set_time function called" << endl;
	hour = hr;
	min = mn;
	AP = tm;
	//cout << "time set" << endl;
	return;
}

string clockType::get_AP()
{
	return AP;
}

void clockType::print(ofstream& file)
{
	//cout << "print function called" << endl;
	file << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << " " << AP ;
	return; 
}

clockType clockType::operator+(clockType b)
{
	clockType sum;
	clockType a;
	a.hour = this->hour; a.min = this->min; a.AP = this->AP;
	sum.min = a.min + b.min;
	sum.hour = a.hour + b.hour;
	if(sum.min >= 60)
	{
		sum.min -= 60;
		sum.hour++;
	}
	if (a.AP == "AM" and sum.hour > 12)
	{
		sum.hour -= 12;
		sum.AP = "PM";
	}
	else if(a.AP == "PM" and sum.hour > 12)
	{
		sum.hour -= 12;
		sum.AP = "AM";
	}
	else
		sum.AP = a.AP;

	return sum;
}

int clockType::operator-(clockType b)
{
	int difference;
	clockType a;
	a.hour = this->hour; a.min = this->min; a.AP = this->AP;
	if(a.AP == "PM")
		a.hour += 12;
	if(b.AP == "PM")
		b.hour += 12;
	if(a.min < b.min)
	{
		a.min += 60;
		a.hour--;
	}
	if(a.hour > b.hour or (a.hour = b.hour and a.min >= b.min))
		difference = (a.hour - b.hour)*60 + a.min - b.min;
	else
		difference = -((b.hour - a.hour)*60 + b.min - a.min);
	return difference; 
}

clockType clockType::operator*(int i)
{
	clockType ans, a;
	a.hour = this->hour; a.min = this->min; a.AP = this->AP;
	for(int j = 0; j < i; j++)
	{
		ans = ans + a;
	}
	return ans;
}

bool clockType::operator>(clockType b)
{
	clockType a;
	a.hour = this->hour; a.min = this->min; a.AP = this->AP;
	if(a - b > 0)
		return true;
	else
		return false;
}

bool clockType::operator<(clockType b)
{
	clockType a;
	a.hour = this->hour; a.min = this->min; a.AP = this->AP;
	if(a - b < 0)
		return true;
	else
		return false;
}

bool clockType::operator==(clockType b)
{
	clockType a;
	a.hour = this->hour; a.min = this->min; a.AP = this->AP;
	if(a - b == 0)
		return true;
	else
		return false;
}

