//
//  ChessPieces.hpp
//  Chess
//
//  Created by Stefan Orn Hrafnsson on 14/11/2017.
//  Copyright © 2017 Stefan Orn Hrafnsson. All rights reserved.
//

#ifndef ChessPieces_hpp
#define ChessPieces_hpp

#include <stdio.h>
#include <string>
#include "LeagalMoveSet.hpp"

using namespace std;

class BoardPosition{
public:
    BoardPosition();
    BoardPosition(char xAxis, char yAxis);
    BoardPosition(string axis);
    BoardPosition(int xAxis, int yAxis );
    
    friend bool operator == (const BoardPosition& leftSide, const BoardPosition& rightSide);
    friend bool operator != (const BoardPosition& leftSide, const BoardPosition& rightSide);
    
    void SetBordPosition(char xAxis, char yAxis);
    
    BoardPosition Graveyard();
    int GetXPos();
    int GetYPos();
private:
    void TranslateCharToPos(char xAxis, char yAxis);
    int _xAxis; //A-H
    int _yAxis; //1-8
};

enum SuitColor{Black, White, null};

class ChessPieces {
public:
    ChessPieces();
    ChessPieces(char icon, string place , SuitColor color);
    void initPiece( char icon, int xPlace, int yPlace, SuitColor color);
    
    SuitColor GetColor();
    char GetIcon();
    BoardPosition _position; 
private:
    char _icon;
    LeagalMoveSet _moves;
    SuitColor _color;
};

#endif /* ChessPieces_hpp */
