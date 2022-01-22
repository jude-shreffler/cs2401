# Created by: Nasseef Abukamail
# This Makefile will allow you to run tests for the appointment class
#
# Usage:
#    make run_tests
#    mingw32-make run_tests_win
#
#Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

# Linking all the files and run the tests. Use your own header and
# object files.

a.exe: MyTime.o MyTime.h MyTime_Main.o
	$(CC) $(CFLAGS) MyTime.o MyTime_Main.o -o a.exe

MyTime.o: MyTime.cc MyTime.h
	$(CC) -c $(CFLAGS) MyTime.cc -o MyTime.o

MyTime_Main.o: MyTime_Main.cc MyTime.h
	$(CC) -c $(CFLAGS) MyTime_Main.cc -o MyTime_Main.o

clean:
	rm *.o