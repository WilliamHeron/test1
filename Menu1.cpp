//
//  Menu.cpp
//  Fun Factory 2.0
//
//  Created by Account on 2020-04-06.
//  Copyright © 2020 Account. All rights reserved.
//

#include "Menu1.hpp"

menu1::menu1(){
    
}

void menu1::main(){
    cout << "welcome to Chess\n";
    
    add_user();
    add_user();
    
    cout << "\nflippig a coin to see who starts\n";
    coin_flip();
    cout << "\nthe first player is the capital leters\nthe first player is: ";
    
    USER[first_player]->print_name();
    print_board();
    
    
    /*          MAIN TURN LOOP               */
    bool kings_alive = true;
    while(kings_alive == true){
        
    cout << "-------------------------------\n";
    USER[first_player]->print_name();
    cout << "TURN\n";
    player1_turn();
    kings_alive = check_for_winner();
    print_board();
        if(kings_alive == false){
            cout <<"CONGRADULATIONS ";
            USER[first_player]->print_name();
            cout << "has won!\nand ";
            USER[second_player]->print_name();
            cout << "has lost\n";
        }
   
        
        
        
    cout << "-------------------------------\n";
    USER[second_player]->print_name();
    cout << "TURN\n";
    player2_turn();
    kings_alive = check_for_winner();
    print_board();
    if(kings_alive == false){
            cout <<"CONGRADULATIONS ";
            USER[second_player]->print_name();
            cout << "has won!\nand ";
            USER[first_player]->print_name();
            cout << "has lost\n";
              }
        
        
        
    }
    
    
    
}

void menu1::add_user(){
    string temp_name;
    cout << "enter the name of user"<<num_of_users+1<<endl;
    cin >> temp_name;
    
    user * tempUser = new user(temp_name);
    
    USER[num_of_users] = tempUser;
    
    
    num_of_users++;
    
    // USER[num_of_users]->print_name();
}//adds user

void menu1::coin_flip(){
    first_player = rand()%1+1;
    if(first_player == 1){
        second_player = 0;
    }
    else{
        second_player = 1;
    }
    
}//chooses random player


void menu1::print_board(){
    cout << "\nBOARD\n-----------------------\n";
    cout << endl;
    int eight_down = 8;
    for(int i = 0;i<8;i++){
        cout <<eight_down<<"\t";
        for(int j = 0;j<8;j++){
            cout << chess_board[i*8+j] <<" ";
            
        }
        cout << endl;
        eight_down--;
    }
    cout << "\n\t a b c d e f g h\n-----------------------\n";
}//prints board

void menu1::player1_turn(){
    
    int new_source{100};
    int new_dest{100};
    while((new_source>63||new_source<0)||(new_dest>63||new_dest<0)){
        
    string source;
    string dest;
    cout << "select piece press enter, \nselect destination press enter\n";
    cin >> source;
    cin >> dest;
        
    new_source = convert_to_int(source);
    new_dest= convert_to_int(dest);
    }
    
    
    
    
    if(rule_book1(new_source,new_dest)==true){
    swap_pieces(new_source,new_dest);
    }
    else{
        cout << "move invalid, you suck, you just wasted this turn\n";
    }
    
}



int menu1::convert_to_int(string a){
    char letter_1 = a[0];
    char number_1 = a[1];
    int letter_2;
    if(letter_1 == 'a'){
        letter_2 = 0;
    }
    else if(letter_1 == 'b'){
        letter_2 = 1;
    }
    else if(letter_1 == 'c'){
        letter_2 = 2;
    }
    else if(letter_1 == 'd'){
          letter_2 = 3;
      }
    else if(letter_1 == 'e'){
          letter_2 = 4;
      }
    else if(letter_1 == 'f'){
          letter_2 = 5;
      }
    else if(letter_1 == 'g'){
          letter_2 = 6;
      }
    else if(letter_1 == 'h'){
          letter_2 = 7;
      }
    else{
        cout << "**POSITION INVALID**\n";
        letter_2 = 100;
    }
    
    int number_2 = number_1 - '0';
    
    if(number_2>8){
        cout << "**POSITION INVALID**\n";
        number_2 = 100;
    }
    
    int b = (8-number_2)*8+letter_2;
    
    return b;
}//converts string entered by user to position on array


void menu1::swap_pieces(int Source, int Dest){
    
    if(chess_board[Dest] != '*'){
        chess_board[Dest] = '*';
    }
    
    char tempChar = chess_board[Source];
    chess_board[Source] =chess_board[Dest];
    chess_board[Dest] = tempChar;
    
}//swaps pieces on board



bool menu1::rule_book1(int Source,int Dest){
    bool answer = true;
    unsigned int unsigned_change = Source-Dest;
    
    
    if(chess_board[Source]=='*'){
        answer = false;
    }
    
    //for selecting opponent player
    else if(chess_board[Source]=='r'){
        answer = false;
    }
    else if(chess_board[Source]=='h'){
        answer = false;
    }
    else if(chess_board[Source]=='b'){
        answer = false;
    }
    else if(chess_board[Source]=='k'){
        answer = false;
    }
    else if(chess_board[Source]=='q'){
        answer = false;
    }
    else if(chess_board[Source]=='p'){
        answer = false;
    }
    
    //if your destination is your own player
    else if(chess_board[Dest]=='R'){
           answer = false;
       }
       else if(chess_board[Dest]=='H'){
           answer = false;
       }
       else if(chess_board[Dest]=='B'){
           answer = false;
       }
       else if(chess_board[Dest]=='K'){
           answer = false;
       }
       else if(chess_board[Dest]=='Q'){
           answer = false;
       }
       else if(chess_board[Dest]=='P'){
           answer = false;
       }
    
    //moves for pawn
    else if(chess_board[Source]=='P'){
        
        if(Source-Dest != 8&&Source-Dest != 7&&Source-Dest != 9&&Source-Dest != 16){
            answer = false;
        }
        
        else if(Source-Dest == 8 && (chess_board[Dest]=='r'||chess_board[Dest]=='h'||chess_board[Dest]=='b'||chess_board[Dest]=='k'||chess_board[Dest]=='q'||chess_board[Dest]=='p')){
            answer = false;
        }
        
        else if(Source-Dest == 16 && turn_number > 1){
            answer = false; 
        }
        
        else if((Source-Dest == 7||Source-Dest == 9) && chess_board[Dest] =='*'){
            answer = false;
        }
    }
    //moves for horse
    else if(chess_board[Source]=='H'){
        
        if(unsigned_change != 6 && unsigned_change != 10 && unsigned_change != 15 && unsigned_change != 17 ){
            answer = false;
        }
           
        if(Source > 55 && Source-Dest > 63){
            
            answer = false;
        }
        
        if(Source < 8 && Source-Dest < 0){
            answer = false;
        }
        
        //checking of horse is by the wall
        for(int i= 0; i<8; i++){
            
            if(Source = i*8+8 && (Source - Dest == -10 ||Source - Dest == -17||Source - Dest == 6||Source - Dest == 15)){
                answer = false;
            }
            if(Source = i*8+7 && (Source - Dest == -10 ||Source - Dest == 6)){
                answer = false;
            }
            
            if(Source = i*8 && (Source - Dest == 10 ||Source - Dest == 17||Source - Dest == -6||Source - Dest == -15)){
                answer = false;
            }
            
            if(Source = i*8+1 && ((Source - Dest == 10)||(Source - Dest == -6))){
                answer = false;
            }
        }
        
            //6,10,17,19
        }
    
    
    return answer;
}





void menu1::player2_turn(){
    int new_source{100};
    int new_dest{100};
    while((new_source>63||new_source<0)||(new_dest>63||new_dest<0)){
        
    string source;
    string dest;
    cout << "select piece press enter, \nselect destination press enter\n";
    cin >> source;
    cin >> dest;
        
    new_source = convert_to_int(source);
    new_dest= convert_to_int(dest);
    }
    
    
    
    
    if(rule_book2(new_source,new_dest)==true){
    swap_pieces(new_source,new_dest);
    }
    else{
        cout << "move invalid, you suck, you just wasted this turn\n";
    }
}

bool menu1::rule_book2(int Source, int Dest){
    bool answer = true;
    
    
    return answer;
}

//checks for winner
bool menu1::check_for_winner(){
    bool king_alive = true;
    bool kingA = false;
    bool kingB = false;
    
    for(int i=0; i<64; i++){
        if(chess_board[i] == 'K')
            kingA = true;
        
        if(chess_board[i] == 'k')
            kingB = true;
    }
    
    if(kingA == false || kingB == false){
        king_alive = false;
    }
    
    
    return king_alive;
}


/*
8 r h b k q b h r
7 p p p p p p p p
6 * * * * * * * *
5 * * * * * * * *
4 * * * * * * * *
3 * * * * * * * *
2 P P P P P P P P
1 R H B K Q B H R
  a b c d e f g h
 */

