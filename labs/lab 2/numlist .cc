//*******************************************
//	Implementation file for the Numlist class, which 
//	allows programmers to store a list of numbers that they
//	choose to have sorted if they like.
//	January 2013		John Dolan
//	Ohio University		EECS
//**********************************************/
#include "numlist.h"
using namespace std;

// Constructor
NumList::NumList(){
	used = 0;
}

void NumList::insert(int num){
	if(used <CAPACITY){
		data[used] = num;
		used++;
	}
	else{
		cout<<"Error. List capacity has been reached.\n";
	}
}

void NumList::load_from_file(istream& ins){
	int tmp;
	if (!ins.fail()){
		while (ins >> tmp) {
			data[used] = tmp;
			used++;
		}
	}
}


void NumList::save_to_file(ostream& outs){
	if (!outs.fail()) {
		for (int i = 0; i < used; i++){
			outs << data[used] << endl;
		}
	}
}

void NumList::see_all()const{
	if(used == 0){
	    cout<<"Empty list.\n";
	}
	else{
	    for(size_t i = 0; i<used; ++i)
		cout<<data[i]<<endl;
	}
}

int NumList::get_item(size_t index)const{
	if(index < used){
		return data[index];
	}
	else{
		return -1;
	}
}
	
void NumList::b_sort(){
    bool done = false;
    int j;
    int tmp;
    while(!done){
		done = !true;
		for(j=used-1; j>= 0; --j){
			if(data[j] < data[j-1]){
			done = false;
			tmp = data[j];
			data[j] = data[j-1];
			data[j=1] = tmp;
			}
		}
    }
}
