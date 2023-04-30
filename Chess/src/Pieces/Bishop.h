#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

    class Bishop : public SlidePiece {
    public:
      Bishop(Coordinate pos, bool isColorWhite);
      Piece *clone() override;

    };

#endif // BISHOP_H
