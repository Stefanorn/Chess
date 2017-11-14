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
    DrawTheBoard();
    InitializePieces();
    AddPiesesToBoard();
}


////////////////////////////////////////////////////////////////////////////////////
////////////////////////OPERATOR OVERWRITE//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

ostream& operator << (ostream& out, const ChessBoard& board){
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9 ; j++){
            out << board._board[i][j] << "|";
        }
        out << endl;
    }
    
    return out;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////PRIVATE FÖLL////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void ChessBoard::AddPiesesToBoard(){
    for (int i = 0; i < 16; i++) {
        _board[ _blackPieces[i].GetYPos()]
        [ _blackPieces[i].GetXPos() ] = _blackPieces[i].GetIcon();
    }
    for (int i = 0; i < 16; i++) {
        _board[ _whitePieces[i].GetYPos()]
        [ _whitePieces[i].GetXPos()] = _whitePieces[i].GetIcon();
    }
}

void ChessBoard::InitializePieces(){
    
    _blackPieces[0].initPiece('R', 1, 1);
    _blackPieces[1].initPiece('N', 2, 1);
    _blackPieces[2].initPiece('B', 3, 1);
    _blackPieces[3].initPiece('K', 4, 1);
    _blackPieces[4].initPiece('Q', 5, 1);
    _blackPieces[5].initPiece('B', 6, 1);
    _blackPieces[6].initPiece('N', 7, 1);
    _blackPieces[7].initPiece('R', 8, 1);
    
    for(int i = 8; i < 16; i++){
       _blackPieces[i].initPiece('P', i-7, 2);
    }
    
    _whitePieces[0].initPiece('r', 1, 8);
    _whitePieces[1].initPiece('n', 2, 8);
    _whitePieces[2].initPiece('b', 3, 8);
    _whitePieces[3].initPiece('k', 4, 8);
    _whitePieces[4].initPiece('q', 5, 8);
    _whitePieces[5].initPiece('b', 6, 8);
    _whitePieces[6].initPiece('n', 7, 8);
    _whitePieces[7].initPiece('r', 8, 8);
    for(int i = 8; i < 16; i++){
        _whitePieces[i].initPiece('p', i-7, 7);
    }
    
}

void ChessBoard::DrawTheBoard(){
    
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
