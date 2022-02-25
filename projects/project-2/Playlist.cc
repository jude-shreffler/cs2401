/**
 * @file Playlist.cc
 * @author Jude Shreffler (js467820@ohio.edu)
 * @brief Implementation file for Playlist class
 * @date 2022-02-18
 */

#include "Playlist.h"
#include <iostream>

using namespace std;

Playlist::Playlist() {
        data = new Song[5];
        used = 0;
        capacity = 5;
        current_index = 0;
}

// The Big 3
Playlist::~Playlist() {
        delete[] data;
}

Playlist::Playlist(const Playlist &other) {
        used = other.used;
        capacity = other.capacity;
        current_index = other.current_index; /// TODO: maybe delete this

        data = new Song[capacity];
        for (int i = 0; i < used; i++) {
                data[i] = other.data[i];
        }       
}

void Playlist::operator=(const Playlist &other) {
        if (this == &other) {
                return;
        }

        /// Deconstructor code
        delete data;

        /// Copy Constructor code
        used = other.used;
        capacity = other.capacity;
        current_index = other.current_index; /// TODO: maybe delete this?

        data = new Song[capacity];
        for (int i = 0; i < capacity; i++) {
                data[i] = other.data[i];
        }
}

// Functions for the internal iterator
void Playlist::start() {
        current_index = 0;
}

void Playlist::advance() {
        current_index++;
}

bool Playlist::is_item() const {
        return (used > current_index);
}

Song Playlist::current() const {
        return data[current_index];
}

// Other useful things the user may want to do
void Playlist::remove_current() {
        if(is_item()) {
                for (int i = current_index; i < used - 1; i++) {
                        data[i] = data[i + 1];
                }

                used--;        
        }
}

void Playlist::insert(const Song &s) {
        if (used == capacity) {
                resize();
        }

        if (is_item()) {
                for (int i = used; i > current_index; i--) {
                        data[i] = data[i - 1];
                }

                data[current_index] = s;
                used++;
        } else {
                for (int i = used; i > 0; i--) {
                        data[i] = data[i - 1];
                }

                data[0] = s;
                used++;
        }

}

void Playlist::attach(const Song &s) {
        if (used == capacity) {
                resize();
        }
        
        if (is_item()) {
                for (int i = used; i > current_index + 1; i--) {
                        data[i] = data[i - 1];
                }

                data[current_index + 1] = s;
                used++;
        } else {
                data[used] = s;
                used++;
        }

}

void Playlist::show_all(std::ostream &outs) const{
        for (int i = 0; i < used; i++) {
                cout << data[i] << endl;
        }
}

void Playlist::releaseDate_sort() {
        bool cont = true;
        while (cont == true) {
                cont = false;
                for (int i = 0; i < used - 1; i++) {
                        if (data[i].get_release() > data[i + 1].get_release()) {
                                Song tmp = data[i];
                                data[i] = data[i + 1];
                                data[i + 1] = tmp;
                                cont = true;
                        }
                }
        }
}

void Playlist::artist_sort() {
        bool cont = true;
        while (cont == true) {
                cont = false;
                for (int i = 0; i < used - 1; i++) {
                        if (data[i].get_artist() > data[i + 1].get_artist()) {
                                Song tmp = data[i];
                                data[i] = data[i + 1];
                                data[i + 1] = tmp;
                                cont = true;
                        }
                }
        }
}

Song Playlist::find_song(const std::string &name) const{
        Song tmp;
        for (int i = 0; i < used; i++) {
                if (data[i].get_name() == name) {
                        return data[i];
                }
        }

        return tmp;
}

bool Playlist::is_song(const Song &s) const {
        for (int i = 0; i < used; i++) {
                if(data[i].get_artist() == s.get_artist() && data[i].get_name() == s.get_name() && data[i].get_release() == s.get_release()) {
                        return true;
                }
        }

        return false;
}

void Playlist::load(std::istream &ins) {
        while (ins >> data[used]) {
                used++;
                if (used >= capacity) {
                        resize();
                }
        }
}

void Playlist::save(std::ostream &outs) const {
        for (int i = 0; i < used; i++) {
                outs << data[i];
        }
}

void Playlist::resize() {
        /// make new temp array
        Song* tmp;
        tmp = new Song[capacity + 5];

        /// copy everything over
        for (int i = 0; i < used; i++) {
                tmp[i] = data[i];
        }

        /// delete old array
        delete[] data;
        data = tmp;
        capacity += 5;
}