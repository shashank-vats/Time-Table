#include <iostream>
#include <string>
#include "class_time_table.h"
#include <iomanip>
#include <fstream>

using namespace std;

class_time_table::class_time_table()
{
	no_of_periods = 0;
	lunch_start.set_time(0, 0 , "AM");
	lunch_end.set_time(00, 00, "AM");
	time_table = NULL;
	class_name = "***";
	subjects = NULL;
	class_start.set_time(0, 0, "AM");
	class_end.set_time(0, 0, "AM");
	return;
}
/*Edit by nitesh jindal*/
class_time_table::class_time_table(string Class_name, int NOP, int lunch_start_hr, int lunch_start_mn, string lunch_start_tm, int lunch_end_hr, int lunch_end_mn, string lunch_end_tm, string& Subjects, int Class_start_hr, int Class_start_mn, string Class_start_tm, int Class_end_hr, int Class_end_mn, string Class_end_tm)
{
	no_of_periods = NOP;
	time_table = new period[no_of_periods];
	lunch_start.set_time(lunch_start_hr, lunch_start_mn, lunch_start_tm);
	lunch_end.set_time(lunch_end_hr, lunch_end_mn, lunch_end_tm);
	// time_table = new period[no_of_periods];
	class_name = Class_name;
	subjects = new string[no_of_periods];
	for(int i = 0; i < no_of_periods; i++)
	{
		subjects[i] = Subjects[i];
	}
	class_start.set_time(Class_start_hr, Class_start_mn, Class_start_tm);
	class_end.set_time(Class_end_hr, Class_end_mn, Class_end_tm);
	return;
}

void class_time_table::set_no_of_periods(int NOP)
{
	no_of_periods = NOP;
	time_table = new period[no_of_periods];
	return;
}

void class_time_table::set_lunch_time_start(int lunch_start_hr, int lunch_start_mn, string lunch_start_tm)
{
	lunch_start.set_time(lunch_start_hr, lunch_start_mn, lunch_start_tm);
	return;
}

void class_time_table::set_lunch_time_end(int lunch_end_hr, int lunch_end_mn, string lunch_end_tm)
{
	lunch_end.set_time(lunch_end_hr, lunch_end_mn, lunch_end_tm);
	return;
}

void class_time_table::set_period_time(int Period_no, clockType Period_start, clockType Period_end)
{
   for(int i = 0; i < no_of_periods; i++)
   {
	   if (time_table[i].period_no == Period_no)
	   {
		   time_table[i].period_start = Period_start;
		   time_table[i].period_end = Period_end;
		   return;
	   }
   } 
}

void class_time_table::set_period_teacher(int Period_no, teacher TEacher)
{
   for(int i = 0; i < no_of_periods; i++)
   {
	   if(time_table[i].period_no == Period_no)
	   {
		   time_table[i].Teacher = TEacher;
		   return;
	   }
   } 
}

void class_time_table::set_period_subject(int Period_no, string Subject)
{
	for(int i = 0; i < no_of_periods; i++)
	{
		if (time_table[i].period_no == Period_no)
		{
			time_table[i].subject = Subject;
			return;
		}
	}
}
/*Till here*/
void class_time_table::set_class_name(string Class_name)
{
	class_name = Class_name;
	return;
}

void class_time_table::set_subjects(string* Subjects)
{
	subjects = new string[no_of_periods];
	for(int i = 0; i < no_of_periods; i++)
	{
		subjects[i] = Subjects[i];
	}
	return;
}

void class_time_table::set_class_start(int Class_start_hr, int Class_start_mn, string Class_start_tm)
{
	class_start.set_time(Class_start_hr, Class_start_mn, Class_start_tm);
	return;
}

void class_time_table::set_class_end(int Class_end_hr, int Class_end_mn, string Class_end_tm)
{
	class_end.set_time(Class_end_hr, Class_end_mn, Class_end_tm);
	return;
}

void class_time_table::print(ofstream& file)
{
	file << class_name << "\t";

	for(int i = 0; i < no_of_periods; i++)
	{
		file << setw(17) << left << time_table[i].period_no << "\t";
	}
	file << endl;
	for(int i = 0; i < no_of_periods; i++)
	{
		time_table[i].period_start.print(file);
		file << "-";
		time_table[i].period_end.print(file);
		file << "\t";
	}
	file << endl;
	for(int i = 0; i < no_of_periods; i++)
	{
		file << setw(17) << left << time_table[i].subject << "\t";
	}
	file << endl;
	for(int i = 0; i < no_of_periods; i++)
	{
		file << setw(17) << left << time_table[i].Teacher.get_name() << "\t";
	}
	file << endl;
	file << "Lunch-time: "; 
	lunch_start.print(file);
	file << "-";
	lunch_end.print(file);
	file << endl;
	file.close();
}

void class_time_table::set_period_timings()
{
	int no_of_periods_before_lunch, no_of_periods_after_lunch;
	int period_duration_before_lunch, period_duration_after_lunch;
	if(no_of_periods % 2 == 0)
	{
		no_of_periods_before_lunch = no_of_periods / 2;
	}
	else
	{
		no_of_periods_before_lunch = (no_of_periods / 2) + 1;
	}
	no_of_periods_after_lunch = no_of_periods - no_of_periods_before_lunch;

	period_duration_before_lunch = (lunch_start - class_start) / no_of_periods_before_lunch;
	period_duration_after_lunch = (class_end - lunch_end) / no_of_periods_after_lunch;

	for(int i = 1; i <= no_of_periods_before_lunch; i++)
	{
		time_table[i].period_no = i;
		time_table[i].assigned = false;
		clockType time1, time2, duration;
		duration.set_time(0, period_duration_before_lunch, "AM");
		time1 = class_start + duration*(i - 1);
		if(i != no_of_periods_before_lunch)
			time2 = time1 + duration;
		else
			time2 = lunch_start;

		set_period_time(i, time1, time2);
	}

	for(int i = no_of_periods_before_lunch + 1; i <= no_of_periods; i++)
	{
		time_table[i].period_no = i;
		clockType time1, time2, duration;
		duration.set_time(0, period_duration_after_lunch, "AM");
		time1 = lunch_start + duration*(i - no_of_periods_before_lunch - 1);
		if(i != no_of_periods)
			time2 = time1 + duration;
		else
			time2 = class_end;

		set_period_time(i, time1, time2);
	}
	return;
}

int class_time_table::get_no_of_periods()
{
	return no_of_periods;
}

string class_time_table::get_class_name()
{
	return class_name;
}

clockType class_time_table::get_lunch_start()
{
	return lunch_start;
}

clockType class_time_table::get_lunch_end()
{
	return lunch_end;
}

clockType class_time_table::get_class_start()
{
	return class_start;
}

clockType class_time_table::get_class_end()
{
	return class_end;
}

period *class_time_table::get_time_table()
{
	period *ans;
	ans = new period[no_of_periods];
	for(int i = 0; i < no_of_periods; i++)
	{
		ans[i] = time_table[i];
	}
	return ans;
}

string *class_time_table::get_subjects()
{
	string *ans;
	ans = new string[no_of_periods];
	for(int i = 0; i < no_of_periods; i++)
	{
		ans[i] = subjects[i];
	}
	return ans;
}

void class_time_table::set_period_assigned(int Period_no)
{
	for(int i = 0; i < no_of_periods; i++)
	{
		if(time_table[i].period_no == Period_no)
			time_table[i].assigned = true;
	}
	return;
}

bool class_time_table::get_period_assigned(int Period_no)
{
	for(int i = 0; i < no_of_periods; i++)
	{
		if(time_table[i].period_no == Period_no)
			return time_table[i].assigned;
	}
	return false;
}

clockType class_time_table::get_period_start_time(int Period_no)
{
	clockType ans;
	for(int i = 0; i < no_of_periods; i++)
	{
		if(time_table[i].period_no == Period_no)
			return time_table[i].period_start;
	}
	return ans;
}

clockType class_time_table::get_period_end_time(int Period_no)
{
	clockType ans;
	for(int i = 0; i < no_of_periods; i++)
	{
		if(time_table[i].period_no == Period_no)
			return time_table[i].period_end;
	}
	return ans;
}

void class_time_table::delete_subject(string Subject)
{
	for(int i = 0; i < no_of_periods; i++)
	{
		if(subjects[i] == Subject)
			subjects[i] == "XXX";
	}
	return;
}


