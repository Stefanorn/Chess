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
        cout << "Select position to move to ";
        cin >> to;
        board.makeMove(from, to);
    }
    return 0;
}
