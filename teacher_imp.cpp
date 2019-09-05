#include <iostream>
#include <string>
#include <fstream>
#include "teacher.h"
#include "clockType.h"

using namespace std;

teacher::teacher()
{
	no_of_lectures = 0;
	name = "***";
	start_time.set_time(00, 00, "AM");
	end_time.set_time(00, 00, "AM");
	no_of_subjects = 0;
	subjects = NULL;
	return;
}

teacher::teacher(int nol, string Name, int Start_hr, int Start_mn, string Start_tm, int End_hr, int End_mn, string End_tm, int No_of_subjects, string Subjects[])
{
	no_of_lectures = nol;
	name = Name;
	start_time.set_time(Start_hr, Start_mn, Start_tm);
	end_time.set_time(End_hr, End_mn, End_tm);
	no_of_subjects = No_of_subjects;
	subjects = new string[no_of_subjects];
	for(int i = 0; i < no_of_subjects; i++)
	{
		subjects[i] = Subjects[i];
	}
	return;
}

void teacher::set_teacher_name(string teacher_name)
{
	name = teacher_name;
	return;
}

void teacher::set_start_time(int Start_hr, int Start_mn, string Start_tm)
{
	start_time.set_time(Start_hr, Start_mn, Start_tm);
	return;
}

void teacher::set_end_time(int End_hr, int End_mn, string End_tm)
{
	end_time.set_time(End_hr, End_mn, End_tm);
	return;
}

void teacher::set_no_lectures(int lectures)
{
	no_of_lectures = lectures;
	return;
}

void teacher::set_no_subjects(int Subjects)
{
	no_of_subjects = Subjects;
	subjects = new string[no_of_subjects];
	return;
}

void teacher::set_subjects(string Subject[])
{
	//cout << "set_subjects function called" << endl;
	//cout << no_of_subjects << endl;
	for(int i = 0; i < no_of_subjects; i++)
	{
		subjects[i] = Subject[i]; 
	}
	//cout << "subjects successfully copied" << endl;
	return;
}

void teacher::set_qualification(char Q)
{
	qualification = Q;
	return;
}

int teacher::get_no_lectures()
{
	return no_of_lectures;
}

string teacher::get_name()
{
	return name;
}

clockType teacher::get_start_time()
{
	return start_time;
}

clockType teacher::get_end_time()
{
	return end_time;
}

int teacher::get_no_subjects()
{
	return no_of_subjects;
}

string *teacher::get_subjects()
{
	string *Subjects = new string[no_of_subjects];
	for(int i = 0; i < no_of_subjects; i++)
	{
		Subjects[i] = subjects[i];
	}
	return Subjects;
}

char teacher::get_qualification()
{
	return qualification;
}

void teacher::print(ofstream& file)
{
	file << "Name: " << name << endl;
	file << "No of lectures: " << no_of_lectures << endl;
	file << "Start of the shift: ";
	start_time.print(file);
	file << endl;
	file << "End of the shift: ";
	end_time.print(file);
	file << endl;
	if (qualification == 'P')
		file << "Primary School Teacher" << endl;
	if (qualification == 'H')
		file << "High School Teacher" << endl;
	if (qualification == 'S')
		file << "Higher Secondary School Teacher" << endl;
	file << "Specialised in subjects:\n";
	for(int i = 0; i < no_of_subjects; i++)
	{
		file << "\t" << subjects[i] << endl;
	}
	file << endl << endl;
}

/*#include <iostream>
#include <string>
#include "clockType.h"

using namespace std;

int main()
{
	clockType Time;
	Time.set_time(12, 12, "AM");
	Time.print();
	return 0;
}*/
