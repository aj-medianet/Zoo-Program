//
//  main.cpp
//  project2
//
//  Created by Andrew Joseph on 4/27/18.
//  Copyright © 2018 Andrew Joseph. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Zoo.hpp"
#include "Animal.hpp"



using namespace std;


int main(int argc, const char * argv[]) {
    Zoo* zoo = new Zoo();
    srand((unsigned)time(0)); //creates random once so can use multiple times
    
    zoo->begin();
    
    return 0;
}
