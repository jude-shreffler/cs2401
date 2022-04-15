#include <iostream>
#include <string>

using namespace std;

void reversing(string& s, int start, int end) {
    if (s.length() <= 1) {
        return;
    } else if (start > end) {
        int temp = start;
        start = end;
        end = temp;
        reversing(s, start, end);
    } else if (start == 0 && end == (s.length() - 1)) { // this is how it knows if it's being passed a string that needs reversed
        string revSection = s.substr(1);
        reversing(revSection, start, end - 1);
        s = revSection + s[0];
    } else {
        string revSection = s.substr(start, (end - start + 1));
        reversing(revSection, 0, (revSection.length() - 1));
        s = s.substr(0, start) + revSection + s.substr(end + 1);
    }
}