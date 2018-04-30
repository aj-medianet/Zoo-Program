//
//  Penguin.hpp
//  project2
//
//  Created by Andrew Joseph on 4/28/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Penguin_hpp
#define Penguin_hpp

#include <stdio.h>
#include "Animal.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;


class Penguin: public Animal {
private:
    
public:
    Penguin();
    virtual void addDayToAge();
    virtual int getAge();
    virtual int getCost();
    virtual int getNumBabies();
    virtual double getBaseFoodCost();
    virtual double getPayoff();

    
    ~Penguin();
};


#endif /* Penguin_hpp */
