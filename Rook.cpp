#include "Rook.h"

bool Rook::canMove(const std::string& newPosition, const std::vector<std::vector<Piece*>>& board)
{
    int currentRow = position[1] - '1';
    int currentCol = position[0] - 'a';
    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'a';

    //make sure the move is horizontal or vertical
    if (currentRow != newRow && currentCol != newCol)
        return false;

    //check if the path is clear
    if (currentRow == newRow) //h
    {
        int colDirection = (newCol > currentCol) ? 1 : -1;
        for (int col = currentCol + colDirection; col != newCol; col += colDirection)
        {
            if (board[currentRow][col] != nullptr)
                return false;
        }
    }
    else //v
    {
        int rowDirection = (newRow > currentRow) ? 1 : -1;
        for (int row = currentRow + rowDirection; row != newRow; row += rowDirection)
        {
            if (board[row][currentCol] != nullptr)
                return false;
        }
    }

    //check if the target square allready has a piece there
    if (board[newRow][newCol] != nullptr && board[newRow][newCol]->getColor() == color)
        return false;

    return true;
}
