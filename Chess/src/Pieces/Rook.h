#ifndef ROOK_H
#define ROOK_H


#include "Piece.h"

    class Rook : public SlidePiece {
    public:
      Rook(Coordinate pos, bool isColorWhite);
      Piece *clone() override;
    };


#endif // ROOK_H
