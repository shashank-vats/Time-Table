#ifndef CLASSTIMETABLE_H
#define CLASSTIMETABLE_H
#include <string>
#include "clockType.h"
#include "teacher.h"

struct period
{
	string subject;  // subject taught in period
	teacher Teacher;       // teacher who is taking the period
	int period_no;
	clockType period_start;   // period start time
	clockType period_end;    // period end time
	bool assigned;		// true if the period is assigned to any teacher otherwise false
};


class class_time_table    
{
private:
	string class_name;   // name of class
	int no_of_periods;   // number of periods in a particular class
	clockType lunch_start;   // start of lunch time
	clockType lunch_end; // end of lunch time
	period *time_table;  // array containing time-table of class
	string *subjects; // subjects taught in particular class
	clockType class_start; //start time of class
	clockType class_end;  // end time of class

	// no of periods should be equal to number of subjects


public:
	class_time_table();   
	// default constructor
	// post-conditions:
	//      no_of_periods = 0
	//      lunch_start = 00:00 AM
	//      lunch_end = 00:00 AM
	//      class_name = ***
	//      subjects = NULL
	//      class_start = 00:00 AM
	//      class_end = 00:00 AM
	//      time_table = NULL

	class_time_table(string class_name, int NOP, int lunch_start_hr, int lunch_start_mn, string lunch_start_tm, int lunch_end_hr, int lunch_end_mn, string lunch_end_tm, string& Subjects, int Class_start_hr, int Class_start_mn, string Class_start_tm, int Class_end_hr, int Class_end_mn, string Class_end_tm);
	// initializes each data according to parameters given
	// NOP = number of periods

	void set_no_of_periods(int NOP);
	// sets no. of periods

	void set_lunch_time_start(int lunch_start_hr, int lunch_start_mn, string lunch_start_tm);
	// set lunch start time

	void set_lunch_time_end(int lunch_end_hr, int lunch_end_mn, string lunch_end_tm);
	// set lunch end time

	void set_period_time(int Period_no, clockType Period_start, clockType Period_end);
	// sets period start time and end time

	void set_period_teacher(int Period_no, teacher TEacher);
	// sets teacher for the period

	void set_period_subject(int Period_no, string Subject);
	// sets subject for period

	void set_class_name(string Class_name);
	// sets class_name

	void set_subjects(string *Subjects);
	// sets subjects
	// no of subjects should be equal to number of no of periods

	void set_class_start(int class_start_hr, int class_start_mn, string class_start_tm);
	// sets class starting time

	void set_class_end(int class_end_hr, int class_end_mn, string class_end_tm);
	// sets class ending time

	void print(ofstream& file);
	// prints the time table of class on the file "time_table.txt"

	void set_period_timings();
	// sets time of periods
	// callable only when no_of_periods, lunch_start and lunch_end are set

	int get_no_of_periods();
	// returns no_of_periods

	string get_class_name();
	// returns class name

	clockType get_lunch_start();
	// returns lunch start time

	clockType get_lunch_end();
	// returns lunch end time

	clockType get_class_start();
	// returns class start time

	clockType get_class_end();
	// returns class end time

	period *get_time_table();
	// returns an array of periods

	string *get_subjects();
	// returns an array of subjects

	void set_period_assigned(int Period_no);
	// sets the period assigned

	bool get_period_assigned(int Period_no);
	// returns true if period is assigned otherwise false

	clockType get_period_start_time(int Period_no);
	// returns the start time of period

	clockType get_period_end_time(int Period_no);
	// returns the end time of period

	void delete_subject(string Subject);
	// deletes subject from subjects array
};

#endif
