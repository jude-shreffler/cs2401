#include "products.h"
#include <iostream>
#include <fstream>
#include <list>
#include <limits>

using namespace std;

void displayMenu();

int main() {
    bool run = true;
    list<Bike*> bikeCart;
    list<Bike*>::iterator it;
    Bike* temp;
    char option = '0';
    ifstream orders;
    ofstream save;

    /// open "orders.txt"
    orders.open("orders.txt");
    if(!orders.fail()){
        string type;
        while(orders >> type) {
            if (type == "MountainBike") {
                temp = new MountainBike;
                temp->input(orders);

                bikeCart.push_back(temp);
            } else if (type == "RoadBike") {
                temp = new RoadBike;
                temp->input(orders);

                bikeCart.push_back(temp);
            } else if (type == "Cruiser") {
                temp = new Cruiser;
                temp->input(orders);

                bikeCart.push_back(temp);
            } else if (type == "BMX") {
                temp = new BMX;
                temp->input(orders);

                bikeCart.push_back(temp);
            } else if (type == "Fixie") {
                temp = new Fixie;
                temp->input(orders);

                bikeCart.push_back(temp);
            }
        }
        orders.close();
	}

    cout << "Welcome!" << endl;

    while (run) {
        displayMenu();
        //cin.ignore(); /// this makes it ignore as many characters as possible
        cin >> option;

        switch(option) {
            case '1':
                cout << endl;
                temp = new MountainBike;
                temp->input(cin);

                bikeCart.push_back(temp);
                break;
            case '2':
                cout << endl;
                temp = new RoadBike;
                temp->input(cin);

                bikeCart.push_back(temp);
                break;
            case '3':
                cout << endl;
                temp = new Cruiser;
                temp->input(cin);

                bikeCart.push_back(temp);
                break;
            case '4':
                cout << endl;
                temp = new BMX;
                temp->input(cin);

                bikeCart.push_back(temp);
                break;
            case '5':
                cout << endl;
                temp = new Fixie;
                temp -> input(cin);

                bikeCart.push_back(temp);
                break;
            case '6':
                cout << endl;
                for (it = bikeCart.begin(); it != bikeCart.end(); ++it) {
                    (*it)->output(cout);
                }
                break;
            case '7':
                cout << endl;
                run = false;
                cout << "Saving and exiting." << endl;

                /// save
                save.open("orders.txt");
                if(!save.fail()) {
                    ///do the saving
                    for (it = bikeCart.begin(); it != bikeCart.end(); ++it) {
                        (*it)->output(save);
                    }
                } else {
                    cout << "Problem saving" << endl;
                }
                break;
            case 'q':
                cout << "DEBUG: quitting without saving" << endl;
                run = false;
            default:
                break;
        }

    }
    return 0;
}

void displayMenu() {
    cout << "1.) Add a mountain bike to your cart" << endl;
    cout << "2.) Add a road bike to your cart" << endl;
    cout << "3.) Add a cruiser to your cart" << endl;
    cout << "4.) Add a BMX to your cart" << endl;
    cout << "5.) Add a fixie to your cart" << endl;
    cout << "6.) View your cart" << endl;
    cout << "7.) Exit the program" << endl;
}