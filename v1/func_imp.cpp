#include <iostream>
#include <string>
#include "clockType.h"
#include "teacher.h"
#include "class_time_table.h"
#include <fstream>
#include <iomanip>
#include <vector>
#include "functions.h"

using namespace std;

void take_input()
{
	ifstream infile;
	infile.open("school_data.txt");

	infile >> no_of_classes;

	classes = new class_time_table[no_of_classes];
	for(int i = 0; i < no_of_classes; i++)
	{
		string Class_name;
		int No_of_periods;
		int Lunch_start_hr, Lunch_start_mn, Lunch_end_hr, Lunch_end_mn;
		int Class_start_hr, Class_start_mn, Class_end_hr, Class_end_mn;
		string Lunch_start_tm, Lunch_end_tm;
		string Class_start_tm, Class_end_tm;
		string *Subjects;

		infile >> Class_name;
		infile >> No_of_periods;
		infile >> Lunch_start_hr; infile.ignore(1); infile >> Lunch_start_mn >> Lunch_start_tm;
		infile >> Lunch_end_hr; infile.ignore(1); infile >> Lunch_end_mn >> Lunch_end_tm;
		infile >> Class_start_hr; infile.ignore(1); infile >> Class_start_mn >> Class_start_tm;
		infile >> Class_end_hr; infile.ignore(1); infile >> Class_end_mn >> Class_end_tm;

		Subjects = new string[No_of_periods];
		for(int j = 0; j < No_of_periods; j++)
		{
			infile >> Subjects[j];
		}

		classes[i].set_class_name(Class_name);
		classes[i].set_no_of_periods(No_of_periods);
		classes[i].set_lunch_time_start(Lunch_start_hr, Lunch_start_mn, Lunch_start_tm);
		classes[i].set_lunch_time_end(Lunch_end_hr, Lunch_end_mn, Lunch_end_tm);
		classes[i].set_class_start(Class_start_hr, Class_start_mn, Class_start_tm);
		classes[i].set_class_end(Class_end_hr, Class_end_mn, Class_end_tm);
		classes[i].set_subjects(Subjects);

		delete[] Subjects;

	}

	infile >> no_of_teachers;

	teachers = new teacher[no_of_teachers];
	for(int i = 0; i < no_of_teachers; i++)
	{
		string FirstName, LastName;
		int No_of_lectures;
		int Start_time_hr, Start_time_mn, End_time_hr, End_time_mn;
		string Start_time_tm, End_time_tm;
		int No_of_subjects;
		string *Subjects;
		char Qualification;

		infile >> FirstName >> LastName;
		infile >> No_of_lectures;
		infile >> Start_time_hr; infile.ignore(1); infile >> Start_time_mn >> Start_time_tm;
		infile >> End_time_hr; infile.ignore(1); infile >> End_time_mn >> End_time_tm;
		infile >> No_of_subjects;
		Subjects = new string[No_of_subjects];
		for(int j = 0; j < No_of_subjects; j++)
		{
			infile >> Subjects[j];
		}
		infile >> Qualification;

		teachers[i].set_teacher_name(FirstName + " " + LastName);
		teachers[i].set_no_lectures(No_of_lectures);
		teachers[i].set_start_time(Start_time_hr, Start_time_mn, Start_time_tm);
		cout << teachers[i].get_start_time().hour << " " << teachers[i].get_start_time().min << " " << teachers[i].get_start_time().AP << endl;
		teachers[i].set_end_time(End_time_hr, End_time_mn, End_time_tm);
		teachers[i].set_no_subjects(No_of_subjects);
		teachers[i].set_subjects(Subjects);
		teachers[i].set_qualification(Qualification);

		delete[] Subjects;
	}
	infile.close();
	return;
}

void give_output()
{
	ofstream outfile;
	outfile.open("time_table.txt", ios::app);

	for(int i = 0; i < no_of_classes; i++)
		classes[i].print(outfile);

	outfile.close();

	return;
}

void sort_teachers()
{
	for(int i = 0; i < no_of_teachers; i++)
	{
		if(teachers[i].get_qualification() == 'P')
			primary_school_teacher.push_back(&teachers[i]);
		else if(teachers[i].get_qualification() == 'H')
			high_school_teacher.push_back(&teachers[i]);
		else if(teachers[i].get_qualification() == 'S')
			higher_secondary_teacher.push_back(&teachers[i]);
	}
	return;
}

void sort_classes()
{
	for(int i = 0; i < no_of_classes; i++)
	{
		if((classes[i].get_class_name()[0] >= '1' and classes[i].get_class_name()[0] <= '5') and (classes[i].get_class_name()[1] >= 'A' and classes[i].get_class_name()[1] <= 'Z'))
			primary_classes.push_back(&classes[i]);
		else if((classes[i].get_class_name()[0] >= '6' and classes[i].get_class_name()[0] <= '9') and (classes[i].get_class_name()[1] >= 'A' and classes[i].get_class_name()[1] <= 'Z'))
			secondary_classes.push_back(&classes[i]);
		else if(classes[i].get_class_name()[0] == '1' and classes[i].get_class_name()[0] == '0')
			secondary_classes.push_back(&classes[i]);
		else if(classes[i].get_class_name()[0] == '1' and (classes[i].get_class_name()[1] == '1' or classes[i].get_class_name()[1] == '2'))
			higher_secondary_classes.push_back(&classes[i]);
		else if(classes[i].get_class_name()[0] >= 'A' and classes[i].get_class_name()[0] <= 'Z')
			primary_classes.push_back(&classes[i]);
	}
	return;
}

void make_time_table()
{
	for(int i = 0; i < no_of_classes; i++)
		classes[i].set_period_timings();

	sort_teachers();
	for(int i = 0; i < primary_school_teacher.size(); i++)
	{
		sort_classes();

		int No_of_lectures = primary_school_teacher[i]->get_no_lectures();
		clockType time1;
		clockType time2 = primary_school_teacher[i]->get_end_time();
		string *Subjects;
		Subjects = primary_school_teacher[i]->get_subjects();
		int No_of_subjects = primary_school_teacher[i]->get_no_subjects();
		time1 = primary_school_teacher[i]->get_start_time();

		for(int j = 0; j < No_of_subjects; j++)
		{
			for(int k = 0; k < primary_classes.size(); k++)
			{
				string *Class_Subjects;
				int Class_no_of_subjects = primary_classes[k]->get_no_of_periods();
				Class_Subjects = primary_classes[k]->get_subjects();
				int Class_no_of_periods = primary_classes[k]->get_no_of_periods();

				for(int l = 0; l < Class_no_of_subjects; l++)
				{
					if(Subjects[j] == Class_Subjects[l])
					{
						if(No_of_lectures != 0 and time1 < time2)
						{
							for(int m = 0; m < Class_no_of_periods; m++)
							{
								bool Assigned = primary_classes[k]->get_period_assigned(m);
								clockType Period_start = primary_classes[k]->get_period_start_time(m);
								clockType Period_end = primary_classes[k]->get_period_end_time(m);

								if((not Assigned) and (time1 < Period_start or time1 == Period_start) and (time2 > Period_end or time2 == Period_end))
								{
									primary_classes[k]->set_period_teacher(m, *primary_school_teacher[i]);
									primary_classes[k]->set_period_assigned(m);
									primary_classes[k]->set_period_subject(m, Subjects[j]);
									primary_classes[k]->delete_subject(Subjects[j]);
									No_of_lectures--;
									time1 = time1 + Period_end;
								}
							}
						}
					}
				}

			}
		} 
	}

	for(int i = 0; i < high_school_teacher.size(); i++)
	{
		sort_classes();

		int No_of_lectures = high_school_teacher[i]->get_no_lectures();
		clockType time1 = high_school_teacher[i]->get_start_time();
		clockType time2 = high_school_teacher[i]->get_end_time();
		string *Subjects;
		Subjects = high_school_teacher[i]->get_subjects();
		int No_of_subjects = high_school_teacher[i]->get_no_subjects();

		for(int j = 0; j < No_of_subjects; j++)
		{
			for(int k = 0; k < secondary_classes.size(); k++)
			{
				string *Class_Subjects;
				int Class_no_of_subjects = secondary_classes[k]->get_no_of_periods();
				Class_Subjects = secondary_classes[k]->get_subjects();
				int Class_no_of_periods = secondary_classes[k]->get_no_of_periods();

				for(int l = 0; l < Class_no_of_subjects; l++)
				{
					if(Subjects[j] == Class_Subjects[l])
					{
						if(No_of_lectures != 0 and time1 < time2)
						{
							for(int m = 0; m < Class_no_of_periods; m++)
							{
								bool Assigned = secondary_classes[k]->get_period_assigned(m);
								clockType Period_start = secondary_classes[k]->get_period_start_time(m);
								clockType Period_end = secondary_classes[k]->get_period_end_time(m);

								if((not Assigned) and (time1 < Period_start or time1 == Period_start) and (time2 > Period_end or time2 == Period_end ))
								{
									secondary_classes[k]->set_period_teacher(m, *primary_school_teacher[i]);
									secondary_classes[k]->set_period_assigned(m);
									secondary_classes[k]->set_period_subject(m, Subjects[j]);
									secondary_classes[k]->delete_subject(Subjects[j]);
									No_of_lectures--;
									time1 = time1 + Period_end;
								}
							}
						}
					}
				}

			}
		} 
	}

	for(int i = 0; i < higher_secondary_teacher.size(); i++)
	{
		sort_classes();

		int No_of_lectures = higher_secondary_teacher[i]->get_no_lectures();
		clockType time1 = higher_secondary_teacher[i]->get_start_time();
		clockType time2 = higher_secondary_teacher[i]->get_end_time();
		string *Subjects;
		Subjects = higher_secondary_teacher[i]->get_subjects();
		int No_of_subjects = higher_secondary_teacher[i]->get_no_subjects();

		for(int j = 0; j < No_of_subjects; j++)
		{
			for(int k = 0; k < higher_secondary_classes.size(); k++)
			{
				string *Class_Subjects;
				int Class_no_of_subjects = higher_secondary_classes[k]->get_no_of_periods();
				Class_Subjects = higher_secondary_classes[k]->get_subjects();
				int Class_no_of_periods = higher_secondary_classes[k]->get_no_of_periods();

				for(int l = 0; l < Class_no_of_subjects; l++)
				{
					if(Subjects[j] == Class_Subjects[l])
					{
						if(No_of_lectures != 0 and time1 < time2)
						{
							for(int m = 0; m < Class_no_of_periods; m++)
							{
								bool Assigned = higher_secondary_classes[k]->get_period_assigned(m);
								clockType Period_start = higher_secondary_classes[k]->get_period_start_time(m);
								clockType Period_end = higher_secondary_classes[k]->get_period_end_time(m);

								if((not Assigned) and (time1 < Period_start or time1 == Period_start) and (time2 > Period_end or time2 == Period_end))
								{
									higher_secondary_classes[k]->set_period_teacher(m, *primary_school_teacher[i]);
									higher_secondary_classes[k]->set_period_assigned(m);
									higher_secondary_classes[k]->set_period_subject(m, Subjects[j]);
									higher_secondary_classes[k]->delete_subject(Subjects[j]);
									No_of_lectures--;
									time1 = time1 + Period_end;
								}
							}
						}
					}
				}

			}
		} 
	}

	return;
}

