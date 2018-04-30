//
//  Tiger.hpp
//  project2
//
//  Created by Andrew Joseph on 4/28/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Tiger_hpp
#define Tiger_hpp

#include <stdio.h>
#include "Animal.hpp"

#include <iostream>
#include <iomanip>


using namespace std;


class Tiger: public Animal {
private:
    
public:

    Tiger();
    
    virtual void addDayToAge();
    virtual int getAge();
    virtual int getCost();
    virtual int getNumBabies();
    virtual double getBaseFoodCost();
    virtual double getPayoff();
    
    ~Tiger();

};

#endif /* Tiger_hpp */
