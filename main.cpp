//
//  main.cpp
//  Chess
//
//  Created by Stefan Orn Hrafnsson on 14/11/2017.
//  Copyright © 2017 Stefan Orn Hrafnsson. All rights reserved.
//

#include <iostream>
#include "ChessBoard.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "------- Velkominn í skák hermir 3000 ----" << endl;
    cout << "Svartur er táknaður með hástöfum og hvítur er táknaður með " <<
         "lágstöfum sláðu inn staðsetningu á borði til að færa kallana" <<
         " gangi þér vel." << endl;
    
    ChessBoard board;
    
    string from;
    string to;
 
    while (true) {
        cout << endl << board;
        cout << board.WhosTurn() << "'s turn select piece ";
        cin >> from;
        if(from == "exit"){ return 0; }
        
        cout << "Select position to move to ";
        cin >> to;
        if(to == "exit"){ return 0; }
        
        if(BoardPosition(from) == BoardPosition() ||
           BoardPosition(to) == BoardPosition() ){
            cout << "incorrect input try for example a2" << endl;
        }
        else if(board.WhatIsThere(from).GetColor() == board.GetColor()){
            if( board.WhatIsThere(to).GetColor() != board.GetColor() ){
                if( board.makeMove( to , BoardPosition() ) )
                    cout << "sf";
                board.makeMove(from, to);
                board.UpdateBoard();
            }
            else if( board.WhatIsThere(to).GetColor() == board.GetColor() ){
                cout << " illigal move you allreddy have a piece there" << endl;
            }
            else{
                board.makeMove(from, to);
                board.UpdateBoard();
            }
        }
        else{
            cout << "illegal move select valid pice" << endl;
        }
    }
    return 0;
}
