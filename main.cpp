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
    // hérna bý ég til borðið og smiðurinn sér um að láta hvítan byrja teikna allt borðið, gefa öllum köllunum upphafsgyldi, og teikna allt borðið
    
    string from;
    string to;
 
    while (true) { //lykkja sem stoppar aldrei nema að þú skrifar exit hér væri flott að hafa einhvern victory flagga enn fottitið er ekki flottar enn þetta ;)
        cout << endl << board;
        cout << board.WhosTurn() << "'s turn select piece "; //whos turn skilar
                                                //annaðhvort black eða white eftir hvor er að gera
        cin >> from;
        if(from == "exit"){ return 0; }
        cout << "Select position to move to ";
        cin >> to;
        if(to == "exit"){ return 0; }
        
        if(BoardPosition(from) == BoardPosition() ||
           BoardPosition(to) == BoardPosition() ){
            //BoardPosition breytir öllum strengjum og karekterum í form sem skákborðið skilur dæmi a2, d4, h4, enn geimmir svo gögnun í formi inta sem ég nota á bakvið tjöldinn til að indexa gameboard arrayin.
            //ef from er með eitthvað ólöglegt gyldi þá fær það defult gyldið sem er 0,0 og hérna tékka ég hvort from eða to fái defullt gyldin
            cout << "incorrect input try for example a2" << endl;
        }
        else if(board.WhatIsThere(from).GetColor() == board.GetColor()){
            //Hver skák kall hefur lit (svart eða hvítan) svo hefur borðið lit svartan eða hvítan sem táknar hver er að gera hérna tékka ég hvort það sem er í intakinu from er í sama lit og sá sem er að gera.
            if( board.WhatIsThere(to).GetColor() != board.GetColor() ){
                // hérna tékka ég hvort það sem er á reit to sé ekki í sama lit og og sá sem er að gera og ef svo er þá færi ég það sem er í to í defullt position (0,0)
                // ef það er enginn kall þarna þá skilar þetta falli bara false og forritið heldur áfram
                board.makeMove( to , BoardPosition()); // færi það sem er á to reitum í defullt gyldi
                board.makeMove(from, to); // færi það sem er í from á to
                board.UpdateBoard(); // teikna allt borðið aftur og les svo inn hvar allarir karlarnir eru og sit þá á réttan stað og breyti líka hver á að gera
            }
            else if( board.WhatIsThere(to).GetColor() == board.GetColor() ){
                //ef það sem er í to er sami litiur og sá sem er að gera
                cout << " illigal move you all reddy have a piece there" << endl;
            }
            else{
                //þetta mun líklegast ekki keyra því ég er buin að tékka á öllum gyldum sem board colour getur verið
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
