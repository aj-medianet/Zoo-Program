//
//  Turtle.cpp
//  project2
//
//  Created by Andrew Joseph on 4/28/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "Turtle.hpp"
using namespace std;

Turtle::Turtle() : Animal(100, 10, .5, .05) {

}

int Turtle::getAge() {
    return Animal::getAge();
}

int Turtle::getCost() {
    return Animal::getCost();
}

int Turtle::getNumBabies() {
    return Animal::getNumBabies();
}

double Turtle::getBaseFoodCost() {
    return Animal::getBaseFoodCost();
}

double Turtle::getPayoff() {
    return Animal::getPayoff();
}

void Turtle::addDayToAge() {
    Animal::addDayToAge();
}


Turtle::~Turtle() {
    
}
