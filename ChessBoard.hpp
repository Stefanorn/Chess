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

//enum PlayerTurn { White, Black };

class ChessBoard {
public:
    ChessBoard();
    friend ostream& operator << (ostream& out, const ChessBoard& board);
    bool makeMove( BoardPosition from, BoardPosition to );
    string WhosTurn();
    ChessPieces WhatIsThere(BoardPosition pos);
private:
    
    void UpdateBoard();
    SuitColor playerTurn;
    void DrawTheBoard();
    void InitializePieces();
    void AddPiesesToBoard();
    char _board[10][10];
    ChessPieces _blackPieces[17];
    ChessPieces _whitePieces[17];
    
};


#endif /* ChessBoard_hpp */
