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
    int GetXPos();
    int GetYPos();
private:
    void TranslateCharToPos(char xAxis, char yAxis);
    int _xAxis; //A-H
    int _yAxis; //1-8
};

class ChessPieces {
public:
    char GetIcon();
    int GetXPos(); //væri hægt að sameina þetta í vector2
    int GetYPos();
    ChessPieces();
    void initPiece( char icon, int xPlace, int yPlace);
    BoardPosition _position; //TODO ATH afhverju þetta má ekki vera privet
private:
    char _icon;
    LeagalMoveSet _moves;
  //  BoardPosition _position;
    
    int _xPlacement; //TODO eyða þessu
    int _yPlacement; //TODO eyða þessu
};

#endif /* ChessPieces_hpp */
