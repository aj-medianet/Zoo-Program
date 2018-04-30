//
//  Turtle.hpp
//  project2
//
//  Created by Andrew Joseph on 4/28/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Turtle_hpp
#define Turtle_hpp

#include <stdio.h>
#include "Animal.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;


class Turtle: public Animal {
private:
    
public:
    Turtle();
    virtual void addDayToAge();
    virtual int getAge();
    virtual int getCost();
    virtual int getNumBabies();
    virtual double getBaseFoodCost();
    virtual double getPayoff();
    

    ~Turtle();
};


#endif /* Turtle_hpp */
