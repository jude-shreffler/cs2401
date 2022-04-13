#include "products.h"
#include <iostream>
#include <string>

std::istream& Bike::input(std::istream& ins) {
    if(&ins == &std::cin) {
        std::cout << "Enter a color: ";
        std::cin >> frameColor;
        std::cout << std::endl;
    } else {
        ins >> frameColor;
    }

    return ins;
}

std::ostream& Bike::output(std::ostream& outs) {
    if(&outs == &std::cout) {
        std::cout << "Frame Color: " << frameColor << std::endl << std::endl;
    } else {
        outs << frameColor << " " << std::endl;
    }

    return outs;
}

MountainBike::MountainBike(std::string fC, std::string sus, std::string shift, 
    double wheel, int derail, std::string b) {
    
    frameColor = fC;
    if (sus == "hardtail" || sus == "full") {
        suspension = sus;
    } else {
        suspension = "hardtail";
    }
    if (shift == "trigger" || shift == "twist") {
        shifter = shift;
    } else {
        shifter = "trigger";
    }
    if (wheel == 26 || wheel == 27.5 || wheel == 29) {
        wheelSize = wheel;
    } else {
        wheelSize = 26;
    }
    if (validDerailleur(derail)) {
        derailleur = derail;
    } else {
        derailleur = 17;
    }
    if (b == "disc" || b == "rim") {
        brakes = b;
    } else {
        brakes = "disc";
    }
}

std::istream& MountainBike::input(std::istream& ins) {
    if(&ins == &std::cin) {
        std::string sus;
        std::cout << "Enter a suspension option (\"hardtail\" or \"full\"): ";
        std::cin >> sus;

        std::string shift;
        std::cout << "Enter a shifter option (\"trigger\" or \"twist\"): ";
        std::cin >> shift;

        double wheel;
        std::cout << "Enter a wheel option (\"26\", \"27.5\", \"29\"): ";
        std::cin >> wheel;

        int derail;
        std::cout << "Enter your derailleur option in the format \"xy\", where x is 1-3 inclusive and y is 6-9 inclusive, with xy representing the number of sprockets on the front and rear derailleur respectively: ";
        std::cin >> derail;

        std::string b;
        std::cout << "Enter your brakes option (\"disc\" or \"rim\"): ";
        std::cin >> b;

        if (sus == "hardtail" || sus == "full") {
            suspension = sus;
        } else {
            suspension = "hardtail";
        }

        if (shift == "trigger" || shift == "twist") {
            shifter = shift;
        } else {
            shifter = "trigger";
        }

        if (wheel == 26 || wheel == 27.5 || wheel == 29) {
            wheelSize = wheel;
        } else {
            wheelSize = 26;
        }

        if (validDerailleur(derail)) {
            derailleur = derail;
        } else {
            derailleur = 17;
        }

        if (b == "disc" || b == "rim") {
            brakes = b;
        } else {
            brakes = "disc";
        }

    } else {
        ins >> suspension >> shifter >> wheelSize >> derailleur >> brakes;
    }

    Bike::input(ins);

    return ins;
}

std::ostream& MountainBike::output(std::ostream& outs) {
    if (&outs == &std::cout) {
        std::cout << "Info about your mountain bike:" << std::endl;
        std::cout << "Suspension: " << suspension << std::endl;
        std::cout << "Shifter: " << shifter << std::endl;
        std::cout << "Wheel size: " << wheelSize << std::endl;
        std::cout << "Derailleur: " << derailleur << std::endl;
        std::cout << "Brakes: " << brakes << std::endl;
    } else {
        outs << "MountainBike " << suspension << " " << shifter << " " << wheelSize << " " 
             << derailleur << " " << brakes << " ";
    }

    Bike::output(outs);

    return outs;
}

RoadBike::RoadBike(std::string fC, std::string shift, int wheel, int derail, std::string b) {
    frameColor = fC;
    if (shift == "trigger" || shift == "twist") {
        shifter = shift;
    } else {
        shifter = "trigger";
    }
    if (wheel == 26 || wheel == 27.5 || wheel == 29) {
        wheelSize = wheel;
    } else {
        wheelSize = 26;
    }
    if (validDerailleur(derail)) {
        derailleur = derail;
    } else {
        derailleur = 17;
    }
    if (b == "disc" || b == "rim") {
        brakes = b;
    } else {
        brakes = "disc";
    }
}

std::istream& RoadBike::input(std::istream& ins) {
    if(&ins == &std::cin) {
        std::string shift;
        std::cout << "Enter a shifter option (\"friction\", \"trigger\", or \"twist\"): ";
        std::cin >> shift;

        int wheel;
        std::cout << "Enter a wheel option (\"26\" or \"700\"): ";
        std::cin >> wheel;

        int derail;
        std::cout << "Enter your derailleur option in the format \"xy\", where x is 1-3 inclusive and y is 6-9 inclusive, with xy representing the number of sprockets on the front and rear derailleur respectively: ";
        std::cin >> derail;

        std::string b;
        std::cout << "Enter your brakes option (\"disc\" or \"rim\"): ";
        std::cin >> b;

        if (shift == "trigger" || shift == "twist" || shift == "friction") {
            shifter = shift;
        } else {
            shifter = "trigger";
        }

        if (wheel == 26 || wheel == 700) {
            wheelSize = wheel;
        } else {
            wheelSize = 26;
        }

        if (validDerailleur(derail)) {
            derailleur = derail;
        } else {
            derailleur = 17;
        }

        if (b == "disc" || b == "rim") {
            brakes = b;
        } else {
            brakes = "disc";
        }

    } else {
        ins >> shifter >> wheelSize >> derailleur >> brakes;
    }

    Bike::input(ins);

    return ins;
}

std::ostream& RoadBike::output(std::ostream& outs) {
    if (&outs == &std::cout) {
        std::cout << "Info about your road bike:" << std::endl;
        std::cout << "Shifter: " << shifter << std::endl;
        std::cout << "Wheel size: " << wheelSize << std::endl;
        std::cout << "Derailleur: " << derailleur << std::endl;
        std::cout << "Brakes: " << brakes << std::endl;
    } else {
        outs << "RoadBike " << shifter << " " << wheelSize << " " << derailleur << " " << brakes
             << " ";
    }

    Bike::output(outs);

    return outs;
}

Cruiser::Cruiser(std::string fC, int wheel, std::string b, bool step) {
    frameColor = fC;
    if (wheel == 26 || wheel == 24 || wheel == 700) {
        wheelSize = wheel;
    } else {
        wheelSize = 26;
    }
    if (b == "coaster" || b == "rim") {
        brakes = b;
    } else {
        brakes = "coaster";
    }
    stepthrough = step;
}

std::istream& Cruiser::input(std::istream& ins) {
    if(&ins == &std::cin) {
        int wheel;
        std::cout << "Enter a wheel option (\"24\", \"26\", \"700\"): ";
        std::cin >> wheel;

        std::string b;
        std::cout << "Enter your brakes option (\"coaster\" or \"rim\"): ";
        std::cin >> b;

        std::string step;
        std::cout << "Enter your stepthrough option (\"yes\" or \"no\"): ";
        std::cin >> step;

        if (wheel == 26 || wheel == 24 || wheel == 700) {
            wheelSize = wheel;
        } else {
            wheelSize = 26;
        }

        if (b == "coaster" || b == "rim") {
            brakes = b;
        } else {
            brakes = "coaster";
        }

        if (step == "yes") {
            stepthrough = true;
        } else {
            stepthrough = false;
        }

    } else {
        ins >> wheelSize >> brakes >> stepthrough;
    }

    Bike::input(ins);

    return ins;
}

std::ostream& Cruiser::output(std::ostream& outs) {
    if (&outs == &std::cout) {
        std::cout << "Info about your cruiser:" << std::endl;
        std::cout << "Wheel size: " << wheelSize << std::endl;
        std::cout << "Brakes: " << brakes << std::endl;
        std::cout << "Stepthrough: " << ((stepthrough) ? "yes" : "no") << std::endl;
    } else {
        outs << "Cruiser " << wheelSize << " " << brakes << " " << stepthrough << " ";
    }

    Bike::output(outs);

    return outs;
}

BMX::BMX(std::string fC, int wheel, std::string b) {
    frameColor = fC;
    if (wheel == 26 || wheel == 24 || wheel == 20) {
        wheelSize = wheel;
    } else {
        wheelSize = 24;
    }
    if (b == "coaster" || b == "rim") {
        brakes = b;
    } else {
        brakes = "coaster";
    }
}

std::istream& BMX::input(std::istream& ins) {
    if(&ins == &std::cin) {
        int wheel;
        std::cout << "Enter a wheel option (\"20\", \"24\", \"26\"): ";
        std::cin >> wheel;

        std::string b;
        std::cout << "Enter your brakes option (\"coaster\" or \"rim\"): ";
        std::cin >> b;

        if (wheel == 26 || wheel == 24 || wheel == 20) {
            wheelSize = wheel;
        } else {
            wheelSize = 24;
        }

        if (b == "coaster" || b == "rim") {
            brakes = b;
        } else {
            brakes = "coaster";
        }

    } else {
        ins >> wheelSize >> brakes;
    }

    Bike::input(ins);

    return ins;
}

std::ostream& BMX::output(std::ostream& outs) {
    if (&outs == &std::cout) {
        std::cout << "Info about your BMX:" << std::endl;
        std::cout << "Wheel size: " << wheelSize << std::endl;
        std::cout << "Brakes: " << brakes << std::endl;
    } else {
        outs << "BMX " << wheelSize << " " << brakes << " ";
    }

    Bike::output(outs);

    return outs;
}

Fixie::Fixie(std::string fC, int wheel, bool b, bool swap) {
    frameColor = fC;
    if (wheel == 26 || wheel == 24 || wheel == 700) {
        wheelSize = wheel;
    } else {
        wheelSize = 26;
    }
    brakes = b;
    swappableRear = swap;
}

std::istream& Fixie::input(std::istream& ins) {
    if(&ins == &std::cin) {
        int wheel;
        std::cout << "Enter a wheel option (\"24\", \"26\", \"700\"): ";
        std::cin >> wheel;

        std::string b;
        std::cout << "Do you want brakes? (\"yes\" or \"no\"): ";
        std::cin >> b;

        std::string swap;
        std::cout << "Do you want a swappable rear wheel? (\"yes\" or \"no\"): ";
        std::cin >> swap;

        if (wheel == 26 || wheel == 24 || wheel == 700) {
            wheelSize = wheel;
        } else {
            wheelSize = 26;
        }

        if (b == "yes") {
            brakes = true;
        } else {
            brakes = false;
        }

        if (swap == "yes") {
            swappableRear = true;
        } else {
            swappableRear = false;
        }

    } else {
        ins >> wheelSize >> brakes >> swappableRear;
    }

    Bike::input(ins);

    return ins;
}

std::ostream& Fixie::output(std::ostream& outs) {
    if (&outs == &std::cout) {
        std::cout << "Info about your Fixie:" << std::endl;
        std::cout << "Wheel size: " << wheelSize << std::endl;
        std::cout << "Brakes: " << ((brakes) ? "yes" : "no") << std::endl;
        std::cout << "Swappable rear wheel: " << ((swappableRear) ? "yes" : "no") << std::endl;
    } else {
        outs << "Fixie " << wheelSize << " " << brakes << " " << swappableRear << " ";
    }

    Bike::output(outs);

    return outs;
}