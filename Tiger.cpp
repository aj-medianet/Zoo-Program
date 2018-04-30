//
//  Tiger.cpp
//  project2
//
//  Created by Andrew Joseph on 4/28/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "Tiger.hpp"
#include "Animal.hpp"

using namespace std;

Tiger::Tiger() : Animal(10000, 1, 10, .2) {

}

int Tiger::getAge() {
    return Animal::getAge();
}

int Tiger::getCost() {
    return Animal::getCost();
}

int Tiger::getNumBabies() {
    return Animal::getNumBabies();
}

double Tiger::getBaseFoodCost() {
    return Animal::getBaseFoodCost();
}

double Tiger::getPayoff() {
    return Animal::getPayoff();
}

void Tiger::addDayToAge() {
    Animal::addDayToAge();
}

Tiger::~Tiger() {
    
}
