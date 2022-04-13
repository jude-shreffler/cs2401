#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    public:
        static constexpr double PI = 3.1415926535;

        Shape(double c_p = 0) {cost_per = c_p;}

        virtual double cost() {return area() * cost_per;}
        // virtual double area() {return 0;} // virtual keyword tells compiler that instead of looking in
                                             // the parent first to look for a function with the same
                                             // footprint in the child. if one doesnt exist this one will
                                             // still be used if the child doesnt have one, but the child
                                             // will be used first

        virtual double area() = 0; // this makes the function PURELY VIRTUAL (you do this for all data
                                   // types, not just double). this makes the function useless and will
                                   // no longer call the class. also, now this class is ABSTRACT meaning
                                   // you cannot instantiate it. also, EVERY child has to override this
                                   // function


    private:
        double cost_per;
        
};

class Circle:public Shape {
    public:
        Circle(double r = 0) {radius = r;}

        double area() {return PI * radius * radius;}

    private:
        double radius;
};

class Triangle:public Shape {
    public:
        Triangle(double b = 0, double h = 0) {base = b; height = h;}

        double area() {return 0.5 * base * height;}

    private:
        double base, height;
};

class Rectangle:public Shape {
    public:
        Rectangle(double l = 0, double w  = 0) {length = l; width = w;}

        double area() {return length * width;}

    private:
        double length, width;
};

#endif