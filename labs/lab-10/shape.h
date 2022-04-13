#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>

class Shape {
    public:
        Shape(double t = 0, double c_p = 0);

        virtual void input();
        double cost();

        virtual double area() = 0;

    protected:
        double thickness;
        double cost_per; // cost per cubic unit
};

class Circle:public Shape {
    public:
        Circle(double r = 0);

        void input();
        double area();
    
    private:
        double radius;
};

class Rectangle:public Shape {
    public:
        Rectangle(double l = 0, double w = 0);

        void input();
        double area();

    private:
        double length;
        double width;
};

class Trapezoid:public Shape {
    public:
        Trapezoid(double h = 0, double b1 = 0, double b2 = 0);

        void input();
        double area();
    
    private:
        double height;
        double base1, base2;
};

#endif