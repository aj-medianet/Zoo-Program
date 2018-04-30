//
//  Animal.cpp
//  project2
//
//  Created by Andrew Joseph on 4/28/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "Animal.hpp"
using namespace std;

Animal::Animal(int cost, int babies, double baseFoodCost, double payoff) {
    this->age = 1;
    setCost(cost);
    setNumBabies(babies);
    setBaseFoodCost(baseFoodCost);
    setPayoff(payoff);
}



void Animal::addDayToAge() {
    this->age++;
}

void Animal::setCost(int cost) {
    this->cost = cost;
}

void Animal::setNumBabies(int babies) {
    this->numBabies = babies;
}

void Animal::setBaseFoodCost(double multiplier) {
    this->baseFoodCost = multiplier * 10;
}

void Animal::setPayoff(double percentage) {
    this->payoff = percentage * this->cost;
}

int Animal::getAge() {
    return this->age;
}

int Animal::getCost() {
    return this->cost;
}

int Animal::getNumBabies() {
    return numBabies;
}

double Animal::getBaseFoodCost() {
    return this->baseFoodCost;
}

double Animal::getPayoff() {
    return this->payoff;
}


Animal::~Animal() {
    
}
