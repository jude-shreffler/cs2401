/*************************************************************************
	A little class that holds a dynamic array of numbers.
	I have provided a start here, you need to write the function
		implementations. DO NOT remove the byte_count lines that are
		already in a few of the functions.


    John Dolan			Spring 2013		CS2401 Lab Assignment 4
	Patricia Lindner	Fall 2021
*************************************************************************/

#include <iostream>

size_t byte_count = 0;
class Numbers{
    public:
		Numbers();
		void add(unsigned long item);
		void resize();
		void remove_last();
		void display(std::ostream& outs);
		unsigned long* reveal_address()const;

    private: 

};

Numbers::Numbers(){

	byte_count += 5*sizeof(unsigned long);
}

void Numbers::add(unsigned long item){

}

void Numbers::resize(){

	byte_count += 5*sizeof(unsigned long);
}

void Numbers::remove_last(){

}

void Numbers::display(std::ostream& outs){

}

// You can leave this function alone
unsigned long *Numbers::reveal_address()const{
	return data;
}