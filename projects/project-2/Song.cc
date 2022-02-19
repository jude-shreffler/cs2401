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
    return name;
}

Date Song::get_release()const{
    return release;
}

string Song::get_artist()const{
    return artist;
}

bool Song::operator == (const Song& other)const{
    if (name == other.name && artist == other.artist && release == other.release) {
        return true;
    }

    return false;
}

bool Song::operator != (const Song& other)const{
    if (name != other.name || artist != other.artist || release != other.release) {
        return true;
    }

    return false;
}

void Song::input(std::istream& ins){
    if (&ins == &cin) {
        cout << "Input name: ";
        while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
        getline(ins, name);
        
        cout << "Input artist: ";
        while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
        getline(ins, artist);
        
        cout << "Input release date: ";
        ins >> release;
    } else {
        while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
        getline(ins, name);

        while(ins.peek() == '\n' || ins.peek() == '\r') ins.ignore();
        getline(ins, artist);

        ins >> release;
    }
}

void Song::output(std::ostream& outs)const{
    if (&outs == &cout) {
        outs << "Name: " << name << endl;
        outs << "Artist: " << artist << endl;
        outs << "Release date: " << release << endl;
    } else {
        outs << name << endl;
        outs << artist << endl;
        outs << release << endl;
    }
}

istream& operator >> (std::istream& ins, Song& s){
    s.input(ins);
    return ins;
}

ostream& operator << (std::ostream& outs, const Song& s){
    s.output(outs);
    return outs;
}