//
//  Zoo.cpp
//  project2
//
//  Created by Andrew Joseph on 4/28/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include "Zoo.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Animal.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

Zoo::Zoo() {
    this->bank = 100000;
    this->numTigers = 1;
    this->numPenguins = 1;
    this->numTurtles = 1;
    this->tigerArraySize = 10;
    this->penguinArraySize = 10;
    this->turtleArraySize = 10;
    this->parent = false;
}

void Zoo::begin() {
    int day = 0; //keep track of what day game is on
    //create dynamic arrays on animal types
    tigers = new Tiger[10];
    penguins = new Penguin[10];
    turtles = new Turtle[10];
    
    //create one of each to start off game
    tigers[0] = *new Tiger();
    penguins[0] = *new Penguin();
    turtles[0] = *new Turtle();
    
    //subtract cost of each
    bank = bank - tigers->getCost();
    bank = bank - penguins->getCost();
    bank = bank - turtles->getCost();
    cout << "You have bought 1 Tiger, 1 Penguin, 1 Turtle to start the game." << endl << endl;
    
   
    string input;
    
    bool play = true;
    while (play) {
        int animalType = 0;
        
        while (!(animalType == 1 || animalType == 2 || animalType == 3 || animalType == 4)) {
            day++; //add dayrefle
            
            if (day >= 3) {
                parent = true;
            }
            
            //increase age
            for (int i = 0; i < numTigers; i++) {
                increaseAge(tigers[i]);
            }
            for (int i = 0; i < numPenguins; i++) {
                increaseAge(penguins[i]);
            }
            for (int i = 0; i < numTurtles; i++) {
                increaseAge(turtles[i]);
            }
            
            //gives current day and current bank account
            cout << endl << "Day: " << day <<  " Current bank: " << this->bank << endl;
            cout << "Tigers: " << numTigers << " Penguins: " << numPenguins << " Turtles: " << numTurtles << endl;
            //random event
            randomEvent();
            
            //prompt user to buy animals
            cout << "Buy animals or press 4 to quit" << endl;
            cout << "1. Buy a Tiger" << endl << "2. Buy a Penguin" << endl << "3. Buy a Turtle" << endl << "4. Quit" << endl;
            
            //checks input is an integer
            getline(cin, input);
            if (checkDigits(input) ) {
                stringstream(input) >> animalType;
            }
            if (!(animalType == 1 || animalType == 2 || animalType == 3 || animalType == 4)) {
                cout << "Invalid input. Please choose 1, 2, 3 or 4" << endl;
            }
        }
        
        switch (animalType) {
            case 1: { //tiger
                //check to see if array is big enough for new animal - if not, double array size
                if (numTigers == tigerArraySize - 1) {
                    Animal* newTigers = new Tiger[tigerArraySize * 2];
                    for(int i = 0; i < tigerArraySize; i++) {
                        newTigers[i] = tigers[i];
                    }
                    delete [] tigers;
                    tigers = newTigers;
                    tigerArraySize = tigerArraySize * 2;
                }
                //create new tiger
                tigers[numTigers] = *new Tiger(); //place new tiger in correct index of array
                numTigers++;
                bank = bank - tigers->getCost();  //subtract cost of new tiger from bank
                break;
            }
            case 2: { //penguin
                //check to see if array is big enough for new animal - if not, double array size
                if (numPenguins == penguinArraySize - 1) {
                    Animal* newPenguins = new Penguin[penguinArraySize * 2];
                    for(int i = 0; i < penguinArraySize; i++) {
                        newPenguins[i] = penguins[i];
                    }
                    delete [] penguins;
                    penguins = newPenguins;
                    penguinArraySize = penguinArraySize * 2;
                }
                 //create new penguin
                penguins[numPenguins] = *new Penguin(); //place new penguin in correct index of array
                numPenguins++;
                bank = bank - penguins->getCost();  //subtract cost of new tiger from bank
                break;
            }
            case 3: { //turtle
                //check to see if array is big enough for new animal - if not, double array size
                if (numTurtles == turtleArraySize - 1) {
                    Animal* newTurtles = new Turtle[turtleArraySize * 2];
                    for(int i = 0; i < turtleArraySize; i++) {
                        newTurtles[i] = turtles[i];
                    }
                    delete [] turtles;
                    turtles = newTurtles;
                    turtleArraySize = turtleArraySize * 2;
                }
                //create new turtle
                turtles[numTurtles] = *new Turtle();  //place new turtle in correct index of array
                numTurtles++;
                bank = bank - turtles->getCost();  //subtract cost of new tiger from bank
                break;
            }
            case 4:
                play = false;
                break;
            default:
                break;
        }
       
        //subtract feeding animals
        bank = bank - (tigers->getBaseFoodCost() * numTigers);
        bank = bank - (penguins->getBaseFoodCost() * numPenguins);
        bank = bank - (turtles->getBaseFoodCost() * numTurtles);
        
        //add payoff
        bank = bank + (tigers->getPayoff() * numTigers);
        bank = bank + (penguins->getPayoff() * numPenguins);
        bank = bank + (turtles->getPayoff() * numTurtles);
        
        
        
    }
    
    
    //delete dynamic memory
    delete [] tigers;
    delete [] penguins;
    delete [] turtles;
 }


//checks input for anything but an integer
bool Zoo::checkDigits(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (! ::isdigit(input[i]))
            return false;
    }
    return true;
}

void Zoo::randomEvent() {
    int event = (rand() % 4) + 1; //random number between 1 and 4
    
    
    cout << "Random Event: ";
    
    switch (event) {
        case 1: {
            cout << "Sickness" << endl << endl;
            //get random animal to die
            int randomDeadAnimal = (rand() % 3) + 1;
            if (randomDeadAnimal == 1 && numTigers != 0) {
                //delete 1 tiger
                Animal* newTigers = new Tiger[tigerArraySize - 1];
                for (int i = 0; i < tigerArraySize - 1; i++) {
                    newTigers[i] = tigers[i];
                }
                delete [] tigers;
                tigers = newTigers;
                tigerArraySize = tigerArraySize - 1;
                numTigers--;
            }
            if (randomDeadAnimal == 2 && numPenguins != 0) {
                //delete 1 penguin
                Animal* newPenguins = new Penguin[penguinArraySize - 1];
                for (int i = 0; i < penguinArraySize - 1; i++) {
                    newPenguins[i] = penguins[i];
                }
                delete [] penguins;
                penguins = newPenguins;
                penguinArraySize = penguinArraySize - 1;
                numPenguins--;
            }
            if (randomDeadAnimal == 3 && numTurtles != 0) {
                //delete one turtle
                Animal* newTurtles = new Turtle[turtleArraySize - 1];
                for (int i = 0; i < turtleArraySize - 1; i++) {
                    newTurtles[i] = turtles[i];
                }
                delete [] turtles;
                turtles = newTurtles;
                turtleArraySize = turtleArraySize - 1;
                numTurtles--;
            }
            break;
        }
        case 2: {
            cout << "Boom in zoo attendance" << endl << endl;
            int randomBonus = (rand() & 500) + 250;
            this->bank += (randomBonus * this->numTigers);
            break;
        }
        case 3: {
            
            int randomBaby = (rand() % 3) + 1; //pick random baby 1 = tiger 2 = penguin 3 = turtle
            if (randomBaby == 1 && parent == true) {
                cout << "A baby Tiger is born" << endl << endl;
                //check to see if array is big enough for new animal - if not, double array size
                if (numTigers == tigerArraySize - 1) {
                    Animal* newTigers = new Tiger[tigerArraySize * 2];
                    for(int i = 0; i < tigerArraySize; i++) {
                        newTigers[i] = tigers[i];
                    }
                    delete [] tigers;
                    tigers = newTigers;
                    tigerArraySize = tigerArraySize * 2;
                }
                //create new tiger
                tigers[numTigers] = *new Tiger(); //place new tiger in correct index of array
                numTigers++;
            } else if (randomBaby == 2 && parent == true) {
                cout << "5 baby penguins are born" << endl << endl;
                //create 5 new penguins
                babyPenguins();
                babyPenguins();
                babyPenguins();
                babyPenguins();
                babyPenguins();
            } else if (randomBaby == 3 && parent == true) {
                cout << "10 baby turtleas are born" << endl << endl;
                babyTurtles(); babyTurtles(); babyTurtles(); babyTurtles(); babyTurtles();
                babyTurtles(); babyTurtles(); babyTurtles(); babyTurtles(); babyTurtles();
            } else {
                cout << "No animals old enough to be parents." << endl << endl;
            }
            
            break;
        }
          
        case 4:
            //nothing happens
            cout << "nothing happened" << endl << endl;
            break;
            
        default:
            break;
    }
}

void Zoo::babyPenguins() {
    //check to see if array is big enough for new animal - if not, double array size
    if (numPenguins >= penguinArraySize - 1) {
        Animal* newPenguins = new Penguin[penguinArraySize * 2];
        for(int i = 0; i < penguinArraySize; i++) {
            newPenguins[i] = penguins[i];
        }
        delete [] penguins;
        penguins = newPenguins;
        penguinArraySize = penguinArraySize * 2;
    }
    //create new penguin
    penguins[numPenguins] = *new Penguin(); //place new penguin in correct index of array
    numPenguins++;
}

void Zoo::babyTurtles() {
    //check to see if array is big enough for new animal - if not, double array size
    if (numTurtles == turtleArraySize - 1) {
        Animal* newTurtles = new Turtle[turtleArraySize * 2];
        for(int i = 0; i < turtleArraySize; i++) {
            newTurtles[i] = turtles[i];
        }
        delete [] turtles;
        turtles = newTurtles;
        turtleArraySize = turtleArraySize * 2;
    }
    //create new turtle
    turtles[numTurtles] = *new Turtle();  //place new turtle in correct index of array
    numTurtles++;
}
    
void Zoo::increaseAge(Animal a) {
    a.addDayToAge();
}

Zoo::~Zoo() {
    
}
