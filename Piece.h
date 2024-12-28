#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>

class Piece
{
protected:
    std::string position; // "d2d4"
    int color;            //0 for white, 1 for black

public:
    Piece(const std::string& pos, int clr) : position(pos), color(clr) {}

    virtual ~Piece() {}

    virtual bool canMove(const std::string& newPosition, const std::vector<std::vector<Piece*>>& board) = 0;

    const std::string& getPosition() const { return position; }
    void setPosition(const std::string& pos) { position = pos; }

    int getColor() const { return color; }


    static bool isWithinBounds(const std::string& pos)
    {
        if (pos.size() != 2)
            return false;

        char col = pos[0]; // 'a' to 'h'
        char row = pos[1]; // '1' to '8'

        //check colum and row
        return (col >= 'a' && col <= 'h') && (row >= '1' && row <= '8');
    }
};

#endif // PIECE_H
