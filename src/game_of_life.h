#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <vector>

class GameOfLife
{
private:
    int m_row, m_col, m_iter;
    std::vector<std::vector<std::vector<int>>> m_gol_array; 
public:
    GameOfLife();
    GameOfLife(int m_row, int m_col, int m_iter);
    void print();
    int rule(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9);
    void shuffle();
    void applyRule();
    void display();
    ~GameOfLife();
};

#endif
