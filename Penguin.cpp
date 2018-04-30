//
//  Penguin.cpp
//  project2
//
//  Created by Andrew Joseph on 4/28/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "Penguin.hpp"
using namespace std;

Penguin::Penguin() : Animal(1000, 5, 1, .1) {

}


int Penguin::getAge() {
    return Animal::getAge();
}

int Penguin::getCost() {
    return Animal::getCost();
}

int Penguin::getNumBabies() {
    return Animal::getNumBabies();
}

double Penguin::getBaseFoodCost() {
    return Animal::getBaseFoodCost();
}

double Penguin::getPayoff() {
    return Animal::getPayoff();
}

void Penguin::addDayToAge() {
    Animal::addDayToAge();
}


Penguin::~Penguin() {
    
}
