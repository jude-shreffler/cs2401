#include <iostream>
#include "Playlist.h"
#include "Song.h"
#include "date.h"

using namespace std;

int main() {
    Playlist myPlaylist;
    Song song;
    
    cin >> song;
    myPlaylist.attach(song);

    cin >> song;
    myPlaylist.attach(song);

    myPlaylist.show_all(cout);

    return 0;
}