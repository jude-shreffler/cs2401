#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <string>
#include <iostream>

class Bike {
    public:
        /// constructor
        /**
         * @brief Construct a new Bike object
         * 
         * @param fC the new color of the bikes frame
         */
        Bike(std::string fC = "default") {frameColor = fC;}

        /// io
        /**
         * @brief sets Bike's attributes via an input stream
         * 
         * @param ins the input stream that contains Bike's data
         * @return std::istream& the input stream that was passed in
         */
        virtual std::istream& input(std::istream& ins);

        /**
         * @brief prints Bike's attributes via an output stream
         * 
         * @param outs the output stream to print to
         * @return std::ostream& the output stream that was passed in
         */
        virtual std::ostream& output(std::ostream& outs);

    protected:
        /// helper
        /**
         * @brief takes an int and returns a boolean corresponding to whether or not it's a valid
         *        derailleur code. valid codes are in the form xy, where x is between 1 and 3 inclusive
         *        and corresponds to the number of chainrings, and y is between 6 and 9 and corresponds
         *        to the number of sprockets
         * 
         * @param derail the derailleur code that get's checked for validity
         * @return true if the code follows the above criteria
         * @return false otherwise
         */
        bool validDerailleur(int derail) {return (derail / 10 >=1 && derail / 10 <= 3) && (derail % 10 >= 6 && derail % 10 <= 9);}

        std::string frameColor; /// allows any string that doesnt have whitespaces
};

class MountainBike : public Bike {
    public:
        /// constructor
        /**
         * @brief Construct a new Mountain Bike object
         * 
         * @param fC the color of the frame, must be a string with no whitespace
         * @param sus the suspension type, must be "full" or "hardtail" (default "hardtail")
         * @param shift the shifter type, must be "trigger" or "twist" (default "trigger")
         * @param wheel the wheel size, must be 26, 27.5, or 29 (default 26)
         * @param derail the derailleur code, must follow the rules stated in Bike::validDerailleur (default 17)
         * @param brakes the brake type, must be "disc" or "rim" (default "disc")
         */
        MountainBike(std::string fC = "default", std::string sus = "hardtail", std::string shift = "trigger", 
            double wheel = 26, int derail = 17, std::string brakes = "disc");

        /// io
        /**
         * @brief sets MountainBike's attributes via an input stream
         * 
         * @param ins the input stream that contains MountainBike's data
         * @return std::istream& the input stream that was passed in
         */
        std::istream& input(std::istream& ins);

        /**
         * @brief prints MountainBike's attributes via an output stream
         * 
         * @param outs the output stream to print to
         * @return std::ostream& the output stream that was passed in
         */
        std::ostream& output(std::ostream& outs);

    private:
        std::string suspension; /// must be "hardtail" or "full"
        std::string shifter; /// must be "twist" or "trigger"
        double wheelSize; /// must be 26.0, 27.5, or 29.0
        int derailleur; /// must follow rules in Bike::validDerailleur
        std::string brakes; /// must be "rim" or "disc"
};

class RoadBike : public Bike {
    public:
        /// constructor
        /**
         * @brief Construct a new Road Bike object
         * 
         * @param fC the color of the frame, must be a string with no whitespace
         * @param shift the shifter type, must be "friction", "twist", or "trigger" (default "friction")
         * @param wheel the wheel size, must be 26 or 700 (default 26)
         * @param derail the derailleur code, must follow the rules stated in Bike::validDerailleur (default 36)
         * @param b the brake type, must be "disc" or "rim" (default "disc")
         */
        RoadBike(std::string fC = "default", std::string shift = "friction", int wheel = 26, int derail = 36, 
            std::string b = "disc");

        // io
        /**
         * @brief sets RoadBike's attributes via an input stream
         * 
         * @param ins the input stream that contains RoadBike's data
         * @return std::istream& the input stream that was passed in
         */
        std::istream& input(std::istream& ins);

        /**
         * @brief prints RoadBike's attributes via an output stream
         * 
         * @param outs the output stream to print to
         * @return std::ostream& the output stream that was passed in
         */
        std::ostream& output(std::ostream& outs);

    private:
        std::string shifter; /// must be "friction", "trigger", or "twist"
        int wheelSize; /// must be 26 or 700
        int derailleur; /// must follow rules in Bike::validDerailleur
        std::string brakes; /// must be "rim" or "disc"
};

class Cruiser : public Bike {
    public:
        /// constructor
        /**
         * @brief Construct a new Cruiser object
         * 
         * @param fC the color of the frame, can be any string that doesnt contain whitespace
         * @param wheel the wheel size, must be 24, 26, or 700 (default 26)
         * @param b the brake type, must be "coaster" or "rim" (default "rim")
         * @param step whether or not the frame is a stepthrough. (default "false")
         */
        Cruiser(std::string fC = "default", int wheel = 26, std::string b = "coaster", bool step = false);

        // io
        /**
         * @brief sets Cruiser's attributes via an input stream
         * 
         * @param ins the input stream that contains Cruiser's data
         * @return std::istream& the input stream that was passed in
         */
        std::istream& input(std::istream& ins);

        /**
         * @brief prints Cruiser's attributes via an output stream
         * 
         * @param outs the output stream to print to
         * @return std::ostream& the output stream that was passed in
         */
        std::ostream& output(std::ostream& outs);

    private:
        int wheelSize; /// must be 24, 26, or 700
        std::string brakes; /// must be "coaster" or "rim"
        bool stepthrough; /// frame is stepthrough if true, standard if false
};

class BMX : public Bike {
    public:
        /// constructor
        /**
         * @brief Construct a new BMX object
         * 
         * @param fC the color of the frame, can be any string that doesnt contain whitespace
         * @param wheel the size of the wheel, must be 20, 24, or 26 (default 24)
         * @param b the brake type, must be "coaster" or "rim" (default coaster)
         */
        BMX(std::string fC = "default", int wheel = 24, std::string b = "coaster");
        
        // io
        /**
         * @brief sets BMX's attributes via an input stream
         * 
         * @param ins the input stream that contains BMX's data
         * @return std::istream& the input stream that was passed in
         */
        std::istream& input(std::istream& ins);

        /**
         * @brief prints BMX's attributes via an output stream
         * 
         * @param outs the output stream to print to
         * @return std::ostream& the output stream that was passed in
         */
        std::ostream& output(std::ostream& outs);

    private:
        int wheelSize; /// must be 20, 24, or 26
        std::string brakes; /// must be "coaster" or "rim"
};

class Fixie : public Bike {
    public:
        /// constructor
        /**
         * @brief Construct a new Fixie object
         * 
         * @param fC the color of the frame, can be any string that doesnt contain whitespace
         * @param wheel the size of the wheel, must be 24, 26, or 700 (default 26)
         * @param b boolean corresponding to whether or not it has brakes
         * @param swap boolean corresponding to whether or not it has a swappable rear wheel
         *             NOTE: a swappable rear wheel is a wheel that has a fixed sprocket on one side,
         *                   and a coaster sprocket on the other side, allowing the end user to swap
         *                   between fixed gear and coaster hub whenever they'd like
         */
        Fixie(std::string fC = "default", int wheel = 26, bool b = false, bool swap = false);

        // io
        /**
         * @brief sets Fixie's attributes via an input stream
         * 
         * @param ins the input stream that contains Fixie's data
         * @return std::istream& the input stream that was passed in
         */
        std::istream& input(std::istream& ins);

        /**
         * @brief prints Fixie's attributes via an output stream
         * 
         * @param outs the output stream to print to
         * @return std::ostream& the output stream that was passed in
         */
        std::ostream& output(std::ostream& outs);

    private:
        int wheelSize; /// must be 24, 26, or 700
        bool brakes; /// no brakes if false, rim brakes if true
        bool swappableRear; /// if true, bike has a rear wheel with a fixed sprocket on one side 
                            /// and a coaster sprocket on the other, allowing the user to switch 
                            /// between the two by reversing their rear wheel. if false, the rear 
                            /// wheel just comes with a fixed gear
};


#endif