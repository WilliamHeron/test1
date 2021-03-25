//
//  user.hpp
//  Fun Factory 2.0
//
//  Created by Account on 2020-04-06.
//  Copyright © 2020 Account. All rights reserved.
//

#ifndef user_hpp
#define user_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class user{
public:
    //constructors
    user();
    user(string);
    
    //functions
    void print_name();
    
private:
    string user_name;
    int num_of_wins{0};
};


#endif /* user_hpp */
