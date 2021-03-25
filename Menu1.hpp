//
//  Menu.hpp
//  Fun Factory 2.0
//
//  Created by Account on 2020-04-06.
//  Copyright © 2020 Account. All rights reserved.
//

#ifndef Menu1_hpp
#define Menu1_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "user.hpp"

using namespace std;



class menu1{
public:
    //constructors
    menu1();
    
    //functoins
    void main();
    void add_user();
    void coin_flip();
    void print_board();
    void player1_turn();
    void player2_turn();
    int convert_to_int(string);
    void swap_pieces(int,int);
    bool rule_book1(int,int);
    bool rule_book2(int,int);
    bool check_for_winner();
    
private:
    int num_of_users{0};
    class user* USER[2];
    int first_player;
    int second_player;
    char chess_board[64] = {'r','h', 'b' ,'k','q' ,'b', 'h', 'r','p', 'p', 'p', 'p', 'p', 'p', 'p', 'p','*', '*', '*', '*', '*', '*', '*', '*','*','*' ,'*' ,'*' ,'*', '*', '*', '*','*', '*', '*', '*', '*', '*', '*', '*','*', '*', '*' ,'*', '*', '*', '*', '*','P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'R', 'H', 'B', 'K', 'Q', 'B', 'H', 'R'};
    int turn_number{1};
    
};



#endif /* Menu_hpp */
