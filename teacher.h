#ifndef TEACHER_H
#define TEACHER_H
#include <string>
#include "clockType.h"

using namespace std;

class teacher
{
private:
	int no_of_lectures;  // as per priority of the teacher;
	string name;  // name of teacher
	clockType start_time; // start of the shift as per priority of teacher
	clockType end_time;  // end of the shift as per priority of teacher
	int no_of_subjects;  // no of subjects in which teacher is specialized
	string *subjects;  // subjects in which teacher is specialized
	char qualification;  // whether the teacher is qualified for senior classes or junior classes
							// stores 'P' for primary school teacher and 'H' for high school teacher
							// and 'S' for higher secondary school teacher
							// primary school teacher - class Nursery to 5th
							// high school teacher - class 6th to 10th
							// higher secondary school teacher - class 11th and 12th

public:
	teacher();
	// default constructor
	// post-condition:
	//		no_of_lectures = 0
	//		name = ***
	//		start_time = 00:00 AM
	//		end_time = 00:00 AM
	//		no_of_subjects = 0
	//		subjects = NULL


	teacher(int nol, string Name, int Start_hr, int Start_mn, string Start_tm, int End_hr, int End_mn, string End_tm,int No_of_subjects,string Subjects[]);
	// constructor
	// initializes each variable according to given data

	void set_teacher_name(string teacher_name);
	// set teacher's name

	void set_start_time(int Start_hr, int Start_mn, string Start_tm);
	// set start time

	void set_end_time(int Start_hr, int Start_mn, string Start_tm);
	// set end time

	void set_no_lectures(int lectures);
	// set no of lectures

	void set_no_subjects(int subjects);
	// set no of subjects

	void set_subjects(string Subject[]);
	// set names of subjects;

	void set_qualification(char Q);
	// sets qualification of teacher

	int get_no_lectures();
	// returns no of lectures

	string get_name();
	// returns teacher's name

	clockType get_start_time();
	// returns start_time

	clockType get_end_time();
	// returns end_time

	int get_no_subjects();
	// returns no_of_subjects

	string *get_subjects();
	// returns an array of subjects

	char get_qualification();
	// returns qualification of teacher

	void print(ofstream& file);
	// prints all information of teacher

};

#endif

	
