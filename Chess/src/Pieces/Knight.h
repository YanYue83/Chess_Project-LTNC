#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

    class Knight : public Piece {
    public:
      Knight(Coordinate pos, bool isColorWhite);
      ~Knight() override;
      Piece *clone() override;

      int generateAllMoves(const BoardState &state,
                           std::vector<Move> &moves) override;

    };

#endif // KNIGHT_H
