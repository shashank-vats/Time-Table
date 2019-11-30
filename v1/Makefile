# Author: Shanshank Vats 
#         Nishant Shekhar

#FLAGS = -Wall -W - O3
CFLAGS = -Wall -W -g
CPP = g++
RM  = rm -f
EXEC =testTT 

OBJECTS = \
create_time_tableMain.o \
class_time_table_imp.o \
clockType_imp.o \
teacher_imp.o \
func_imp.o \

all: $(OBJECTS)  compile touch

create_time_tableMain.o : create_time_tableMain.cpp
			$(CPP) $(CFLAGS) -c create_time_tableMain.cpp
class_time_table_imp.o : class_time_table_imp.cpp
			$(CPP) $(CFLAGS) -c class_time_table_imp.cpp
clockType_imp.o : clockType_imp.cpp
			$(CPP) $(CFLAGS) -c clockType_imp.cpp
teacher_imp.o : teacher_imp.cpp
			$(CPP) $(CFLAGS) -c teacher_imp.cpp
func_imp.o : func_imp.cpp
			$(CPP) $(CFLAGS) -c func_imp.cpp

clean:
			$(RM) $(OBJECTS) 

compile: 
			$(CPP) $(CFLAGS) $(OBJECTS) -o $(EXEC) 

touch:
			@echo " "
			@echo "Compilation done successfully..................."
			@echo " "

