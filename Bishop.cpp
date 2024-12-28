#include "Bishop.h"
#include "Piece.h"

bool Bishop::canMove(const std::string& newPosition, const std::vector<std::vector<Piece*>>& board)
{
    int currentRow = position[1] - '1';
    int currentCol = position[0] - 'a';
    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'a';

    if (abs(newRow - currentRow) != abs(newCol - currentCol))
        return false;

    int rowDirection = (newRow > currentRow) ? 1 : -1;
    int colDirection = (newCol > currentCol) ? 1 : -1;

    int row = currentRow + rowDirection;
    int col = currentCol + colDirection;

    while (row != newRow && col != newCol)
    {
        if (board[row][col] != nullptr)
            return false;

        row += rowDirection;
        col += colDirection;
    }
    //check if square taken or not
    if (board[newRow][newCol] != nullptr)
    {
        if (board[newRow][newCol]->getColor() == color)
            return false;
    }

    return true;
}
