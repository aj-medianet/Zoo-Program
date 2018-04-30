//
//  Animal.hpp
//  project2
//
//  Created by Andrew Joseph on 4/28/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>
#include <iostream>

using namespace std;


class Animal {
private:
    int age;
    int cost;
    int numBabies;
    int baseFoodCost;
    double payoff;
public:

    Animal(int cost, int babies, double baseFoodCost, double payoff);
    
    virtual int getAge();
    virtual void addDayToAge();
    
    void setCost(int cost);
    virtual int getCost();
    
    void setNumBabies(int babies);
    virtual int getNumBabies();
    
    void setBaseFoodCost(double multiplier);
    virtual double getBaseFoodCost();
    
    void setPayoff(double percentage);
    virtual double getPayoff();
    
    ~Animal();
};

#endif /* Animal_hpp */
