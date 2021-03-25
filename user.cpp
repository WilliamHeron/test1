//
//  user.cpp
//  Fun Factory 2.0
//
//  Created by Account on 2020-04-06.
//  Copyright © 2020 Account. All rights reserved.
//

#include "user.hpp"
user::user(){
    user_name = "Richard";
    
}

user::user(string a){
    user_name = a;
}


void user::print_name(){
    cout << user_name << endl;
}
