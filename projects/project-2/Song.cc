#include "Song.h"
#include "date.h"
#include <iostream>
#include <fstream>

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
    if (&ins == &cin) {
        cout << "Input name: ";
        ins >> name;
        cout << "Input artist: ";
        ins >> artist;
        cout << "Input release date: ";
        ins >> release;
    } else {
        ins >> name;
        ins >> artist;
        ins >> release;
    }
}

void Song::output(std::ostream& outs)const{

}

istream& operator >> (std::istream& ins, Song& s){
    s.input(ins);
    return ins;
}

ostream& operator << (std::ostream& outs, const Song& s){
    s.output(outs);
    return outs;
}