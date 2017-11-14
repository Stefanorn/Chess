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

class ChessPieces {
public:
    char GetIcon();
    int GetXPos(); //væri hægt að sameina þetta í vector2
    int GetYPos();
    ChessPieces();
    void initPiece( char icon, int xPlace, int yPlace);
private:
    char _icon;
    LeagalMoveSet _moves;
    int _xPlacement;
    int _yPlacement;
};

#endif /* ChessPieces_hpp */
