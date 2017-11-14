//
//  ChessBoard.cpp
//  Chess
//
//  Created by Stefan Orn Hrafnsson on 14/11/2017.
//  Copyright © 2017 Stefan Orn Hrafnsson. All rights reserved.
//

#include "ChessBoard.hpp"



////////////////////////////////////////////////////////////////////////////////////
////////////////////////PUBLIC FÖLL/////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

ChessBoard::ChessBoard(){
    FillTheBoard();
}


////////////////////////////////////////////////////////////////////////////////////
////////////////////////OPERATOR OVERWRITE//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

ostream& operator << (ostream& out, const ChessBoard& board){
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10 ; j++){
            out << board._board[i][j] << " ";
        }
        out << endl;
    }
    
    return out;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////PRIVATE FÖLL////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void ChessBoard::FillTheBoard(){
    
    bool isBlack = true; // ætti ferakr að vera colorChanger
    char blackPice = '#';
    char whitePice = ' ';
    char sideBoarders[8] = {'8', '7', '6', '5','4','3','2','1'}; 
    char topBoarder[9] = {' ','A', 'B','C','D','E','F','G','H'};
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9 ; j++){
            if(i == 0 ){ //i == 9
                _board[i][j] = topBoarder[j];
            }
            else if(j == 0){ //|| j == 9
                _board[i][j] = sideBoarders[i-1];
            }
            else if(isBlack){
                _board[i][j] = blackPice;
                isBlack = false;
            }
            else{
                _board[i][j] = whitePice;
                isBlack = true;
            }
        }
        if(isBlack){
            isBlack = false;
        }
        else{
            isBlack = true;
        }
    }
    
}
