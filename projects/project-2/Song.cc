#include "Song.h"
#include "date.h"
#include <iostream>

using namespace std;

Song::Song(){
    name = "Blank Song";
    Date tmp(1, 1, 2000);
    release = tmp;
    artist = "Blank Artist";
}

string Song::get_name()const{

    return "";
}

Date Song::get_release()const{

    Date tmp;
    return tmp;
}

string Song::get_artist()const{
    
    return "";
}

bool Song::operator == (const Song& other)const{

    return false;
}

bool Song::operator != (const Song& other)const{

    return false;
}

void Song::input(std::istream& ins){

}

void Song::output(std::ostream& outs)const{

}