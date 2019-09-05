#ifndef FUNCTIONS_H
#define FUNCTIONS_H

teacher *teachers;
class_time_table *classes;
int no_of_classes, no_of_teachers;
vector <teacher *> primary_school_teacher, high_school_teacher, higher_secondary_teacher;
vector <class_time_table *> primary_classes, secondary_classes, higher_secondary_classes;


void take_input();
// reads input from file "school_data.txt"

void give_output();
// prints the time-table in file "time_table.txt"

void make_time_table();
// creates time table on the basis of the data of teachers and classes 

void sort_teachers();
// sorts teachers into primary_school_teacher, high_school_teacher and higher_secondary_teacher

void sort_classes();
// sorts classes into primary_classes, high_classes and higher_secondary_classes

#endif
