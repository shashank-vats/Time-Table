#include <iostream>
#include <string>
#include "clockType.h"
#include "teacher.h"
#include "class_time_table.h"
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

extern void take_input();
// reads input from file "school_data.txt"

extern void give_output();
// prints time table in the output file "time_table.txt"

extern void make_time_table();
// creates time table on the basis of the data of teachers and classes 


int main()
{

	take_input();

	make_time_table();

	give_output();

	return 0;
}
