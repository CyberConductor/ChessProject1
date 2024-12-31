#include "Piece.h"

bool Piece::isWithinBounds(const std::string& pos)
{
    if (pos.length() != 2)
        return false;

    char file = pos[0]; //column: a-h
    char rank = pos[1]; //row: 1-8

    return (file >= 'a' && file <= 'h') && (rank >= '1' && rank <= '8');
}
