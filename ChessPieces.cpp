//
//  ChessPieces.cpp
//  Chess
//
//  Created by Stefan Orn Hrafnsson on 14/11/2017.
//  Copyright © 2017 Stefan Orn Hrafnsson. All rights reserved.
//

#include "ChessPieces.hpp"

////////////////////////////////////////////////////////////////////////////////////
////////////////////////PUBLIC FÖLL/////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

BoardPosition::BoardPosition(){
    _xAxis = 0;
    _yAxis = 0;
}
BoardPosition::BoardPosition(char xAxis, char yAxis){
    TranslateCharToPos(xAxis, yAxis);
}
BoardPosition::BoardPosition(string axis){
    TranslateCharToPos(axis[0], axis[1]);
}
BoardPosition::BoardPosition(int xAxis, int yAxis ){
    _xAxis = xAxis;
    _yAxis = yAxis;
}

BoardPosition BoardPosition::Graveyard(){
    return BoardPosition();
}

void BoardPosition::SetBordPosition(char xAxis, char yAxis){
    TranslateCharToPos(xAxis, yAxis);
}
int BoardPosition::GetXPos() {return _xAxis; }
int BoardPosition::GetYPos() {return _yAxis; }

//

ChessPieces::ChessPieces(char icon, string pos , SuitColor color){
    _icon = icon;
    _color = color;
    _position = BoardPosition(pos);
}

ChessPieces::ChessPieces(){
    _icon = 'E';
    
}

void ChessPieces::initPiece( char icon, int xPlace, int yPlace, SuitColor color){
    _color = color;
    _icon = icon;
    _position = BoardPosition(xPlace, yPlace);
}

SuitColor ChessPieces::GetColor(){ return _color; }
char ChessPieces::GetIcon(){ return _icon; }



////////////////////////////////////////////////////////////////////////////////////
////////////////////////Friend Föll ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

bool operator == (const BoardPosition& leftSide, const BoardPosition& rightSide){
    if( leftSide._yAxis == rightSide._yAxis){
        if(leftSide._xAxis == rightSide._xAxis){
            return true;
        }
    }
    return false;
}
bool operator != (const BoardPosition& leftSide, const BoardPosition& rightSide){
    if( leftSide._yAxis == rightSide._yAxis){
        if(leftSide._xAxis == rightSide._xAxis){
            return false;
        }
    }
    return true;
}


////////////////////////////////////////////////////////////////////////////////////
////////////////////////PRIVATE FÖLL////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void BoardPosition::TranslateCharToPos(char xAxis, char yAxis){
    switch (xAxis) {
        case 'a': case 'A': _xAxis = 1;
            break;
        case 'b': case 'B': _xAxis = 2;
            break;
        case 'c': case 'C': _xAxis = 3;
            break;
        case 'd': case 'D': _xAxis = 4;
            break;
        case 'e': case 'E': _xAxis = 5;
            break;
        case 'f': case 'F': _xAxis = 6;
            break;
        case 'g': case 'G': _xAxis = 7;
            break;
        case 'h': case 'H': _xAxis = 8;
            break;
        default: _xAxis = 0;
            break;
    }
    switch (yAxis) {
        case '8': _yAxis = 1;
            break;
        case '7': _yAxis = 2;
            break;
        case '6': _yAxis = 3;
            break;
        case '5': _yAxis = 4;
            break;
        case '4': _yAxis = 5;
            break;
        case '3': _yAxis = 6;
            break;
        case '2': _yAxis = 7;
            break;
        case '1': _yAxis = 8;
            break;
        default: _xAxis = 0;
            break;
    }
    
}
