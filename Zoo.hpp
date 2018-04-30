//
//  Zoo.hpp
//  project2
//
//  Created by Andrew Joseph on 4/28/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Zoo_hpp
#define Zoo_hpp

#include <stdio.h>

#include "Animal.hpp"

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


class Zoo {
private:
    double bank;
    Animal* tigers;
    Animal* penguins;
    Animal* turtles;
    int numTigers, numPenguins, numTurtles;
    int tigerArraySize, penguinArraySize, turtleArraySize;
    bool parent;
public:
    Zoo();
    void begin();
    void babyPenguins();
    void babyTurtles();
    bool checkDigits(string input);
    void randomEvent();
    void increaseAge(Animal a);
    ~Zoo();
};

#endif /* Zoo_hpp */
