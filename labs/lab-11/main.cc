#include <iostream>

using namespace std;

int counting(int n);
void print_stars(int n);
void see_stars(int count, int stop);

int main() {
    int x;

    for (int j = 0; j < 3; ++j) {                
        cout << "Enter a number: "; 
        cin >> x; 
        cout << "The even numbers counting up to there:\n"; 
        counting(x); 
    } 
    
    int n; 
    cout << "Enter a number between 1 and 30 to see the stars\n"; 
    cin >> n;
    see_stars(1, n);
 
    return 0;
}

int counting(int n) {
    if(n == 0) {
        return 0;
    }
    if(n > 0) {
        if (n % 2 == 0) {
            counting(n - 2);

            cout << n << endl;
        } else {
            --n;
            counting(n - 2);

            cout << n << endl;
        }
    }

    return n;
}

void print_stars(int n) {
    if(n == 1) {
        cout << '*' << endl;
    } else {
        cout << '*';

        print_stars(n - 1);
    }
}

void see_stars(int count, int stop) {
    if (count == stop) {
        print_stars(count);
        if (count == 1) {
            return;
        }
        see_stars(stop,1);
    } else {
        print_stars(count);
        if (count < stop) {
            see_stars(count + 1, stop);
        } else if (count > stop) {
            see_stars(count - 1, stop);
        }
    }
}