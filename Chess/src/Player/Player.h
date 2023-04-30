#ifndef PLAYER_H
#define PLAYER_H

#include "Piece.h"
#include "Structure.h"
#include <string>

    class Gameboard;
    class Engine;
    struct BoardState;
    class Player {
        public:
          Player(std::string playerName, bool isPlayerColorWhite);
          ~Player();

          bool isWhite();
          std::string getName();
          // void addPiece(Piece *p);
          friend class Gameboard;
          friend class Engine;
          friend struct BoardState;

        private:
          std::string Name;
          std::vector<Piece *> pieces;
          bool _isWhite;

          int time;
        };


#endif // PLAYER_H
