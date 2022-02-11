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
		void operator = (const Numbers& other);
		~Numbers();

    private: 
		unsigned long* data;
		std::size_t used;
		std::size_t capacity;
};

Numbers::Numbers(){
	data = new unsigned long[5];
	capacity = 5;
	used = 0;
	byte_count += 5*sizeof(unsigned long);
}

void Numbers::add(unsigned long item){
	if (used == capacity) {
		resize();
	}
	data[used] = item;
	used++;
}

void Numbers::resize(){
	/// make a temp array
	unsigned long* tmp;
	tmp = new unsigned long[capacity + 5];

	/// copy from old array to tmp
	for(std::size_t i = 0; i < used; i++) {
		tmp[i] = data[i];
	}

	/// delete old array and point our main pointer at where tmp is pointing
	delete []data;
	data = tmp;
	capacity += 5;

	byte_count += 5*sizeof(unsigned long);
}

void Numbers::remove_last(){
	used--;
}

void Numbers::display(std::ostream& outs){
	for (std::size_t i = 0; i < used; i++) {
		outs << data[i] << " ";
	}
}

// You can leave this function alone
unsigned long *Numbers::reveal_address()const{
	return data;
}

void Numbers::operator = (const Numbers& other) {
	/// checking for self assignment
	if (this == &other) {
		return;
	}

	/// deconstructor
	delete data;

	/// copy constructor
	used = other.used;
	capacity = other.capacity;

	data = new unsigned long[capacity];
	for (std::size_t i = 0; i < used; i++) {
		data[i] = other.data[i];
	}
}

Numbers::~Numbers() {
	delete []data;
	std::cout << "Deallocated some memory." << std::endl;
	byte_count = byte_count - (capacity * sizeof(unsigned long));
}