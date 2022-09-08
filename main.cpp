#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
private:
    bool isValid(std::vector<std::vector<char>> &board, int row, int col, int number)
    {
        for (int x = 0; x <= 8; x++)
        {
            if (board[row][x]-'0' == number )
            {
                return false;
            }
        }

        for (int x = 0; x <= 8; x++)
        {
            if (board[x][col]-'0' == number)
            {
                return false;
            }
        }

        int sRow = row - row % 3, sCol = col - col % 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i + sRow][j + sCol]-'0' == number)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool solution(std::vector<std::vector<char>> &board, int row, int col)
    {
        if (row == 8 && col == 9)
        {
            return true;
        }

        if (col == 9)
        {
            row++;
            col = 0;
        }

        if (board[row][col]!= '.')
        {
            return solution(board, row, col + 1);
        }

        for (size_t number = 1; number <= board.size(); number++)
        {
            if (isValid(board, row, col, number))
            {
                board[row][col] = number+'0';
                if (solution(board, row, col + 1))
                {
                    return true;
                }
            }
            board[row][col] = '.';
        }
        return false;
    }

public:
    void solveSudoku(std::vector<std::vector<char>> &board)
    {

        if (solution(board, 0, 0))
        {
            std::cout << "solution!" << std::endl;
        }
        else
        {
            std::cout << "No solution exists " << std::endl;
        }
    }
};

int main()
{
    std::vector<std::vector<char>> m = {
    {'.','.','9','7','4','8','.','.','.'},
    {'7','.','.','.','.','.','.','.','.'},
    {'.','2','.','1','.','9','.','.','.'},
    {'.','.','7','.','.','.','2','4','.'},
    {'.','6','4','.','1','.','5','9','.'},
    {'.','9','8','.','.','.','3','.','.'},
    {'.','.','.','8','.','3','.','2','.'},
    {'.','.','.','.','.','.','.','.','6'},
    {'.','.','.','2','7','5','9','.','.'}
    };

    Solution sol;
    sol.solveSudoku(m);

    return 0;
}
