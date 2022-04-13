#include "shape.h"

#include <iostream>
#include <cmath>

using namespace std;

/// Shape

Shape::Shape(double t, double c_p) {
    thickness = t;
    cost_per = c_p;
}

void Shape::input() {
    cout << "Enter the thickness: ";
    cin >> thickness;
    cout << "Enter the cost per cubic unit: ";
    cin >> cost_per;
}

double Shape::cost() {
    return thickness * cost_per * area();
}


/// Circle

Circle::Circle(double r) {
    radius = r;
}

void Circle::input() {
    cout << "Enter the radius: ";
    cin >> radius;
    Shape::input();
}

double Circle::area() {
    return M_PI * radius * radius; // (pi) * r^2
}


/// Rectangle

Rectangle::Rectangle(double l, double w) {
    length = l;
    width = w;
}

void Rectangle::input() {
    cout << "Enter the length: ";
    cin >> length;
    cout << "Enter the width: ";
    cin >> width;
    Shape::input();
}

double Rectangle::area() {
    return length * width;
}


/// Trapezoid

Trapezoid::Trapezoid(double h, double b1, double b2) {
    height = h;
    base1 = b1;
    base2 = b2;
}

void Trapezoid::input() {
    cout << "Enter the height: ";
    cin >> height;
    cout << "Enter the first base: ";
    cin >> base1;
    cout << "Enter the second base: ";
    cin >> base2;
    Shape::input();
}

double Trapezoid::area() {
    return height * ((base1 + base2) / 2.0);
}