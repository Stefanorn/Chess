//
//  ChessBoard.hpp
//  Chess
//
//  Created by Stefan Orn Hrafnsson on 14/11/2017.
//  Copyright © 2017 Stefan Orn Hrafnsson. All rights reserved.
//

#ifndef ChessBoard_hpp
#define ChessBoard_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "ChessPieces.hpp"

using namespace std;

class ChessBoard {
public:
    ChessBoard();
    friend ostream& operator << (ostream& out, const ChessBoard& board);
    void makeMove();
private:
    void FillTheBoard();
    char _board[10][10];
};

#endif /* ChessBoard_hpp */
