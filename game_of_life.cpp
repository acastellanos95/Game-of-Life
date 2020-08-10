#include <iostream>
#include <vector>
#include <random>
#include <time.h>

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
    ~GameOfLife();
};

void GameOfLife::print()
{
    for(auto &iter: m_gol_array){
        std::cout << "[";
        for (auto &row : iter)
        {
            std::cout << "[";
            for (auto &&num : row)
            {
                std::cout << num << " , ";
            }
            
            std::cout << "]\n";

        }

        std::cout << "]\n";
        
    }
}

int GameOfLife::rule(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9)
{
    int total = c2 + c3 + c4 + c5 + c6 + c7 + c8 + c9;
    if(c1 == 1){
        if(total < 2 || total > 3){
            return 0;
        }
        if(total == 2 || total == 3){
            return 1;
        }
    }else if(c1 == 0){
        if(total == 3){
            return 1;
        }else{
            return 0;
        }
    }
}

void GameOfLife::applyRule()
{
    for (size_t iterations = 0; iterations < m_gol_array.size() - 1; iterations++)
    {
        for (size_t row = 0; row < m_gol_array[0].size(); row++)
        {
            for (size_t col = 0; col < m_gol_array[0][0].size(); col++)
            {
                m_gol_array[iterations+1][row][col] = rule(m_gol_array[iterations][(row)%m_row][col%m_col],     m_gol_array[iterations][(row-1)%m_row][(col-1)%m_col], m_gol_array[iterations][(row-1)%m_row][(col)%m_col],   m_gol_array[iterations][(row-1)%m_row][(col+1)%m_col],
                                                           m_gol_array[iterations][(row)%m_row][(col-1)%m_col], m_gol_array[iterations][(row)%m_row][(col+1)%m_col],   m_gol_array[iterations][(row+1)%m_row][(col-1)%m_col], m_gol_array[iterations][(row+1)%m_row][(col)%m_col],
                                                           m_gol_array[iterations][(row+1)%m_row][(col+1)%m_col]);
            }
        }
    }

    
}

void GameOfLife::shuffle()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1);
    for (size_t row = 0; row < m_gol_array[0].size(); row++)
    {
        for (size_t col = 0; col < m_gol_array[0][0].size(); col++)
        {
            m_gol_array[0][row][col] = distribution(generator);
        }
        
    }
    
}

GameOfLife::GameOfLife(int row, int col, int iter) : 
    m_row(row), m_col(col), m_iter(iter)
{
    m_gol_array = std::vector<std::vector<std::vector<int>>>(m_iter, std::vector<std::vector<int>>(row, std::vector<int>(col, 0)));
}

GameOfLife::~GameOfLife()
{
}

void check_int(int a){
}


int main(){
    GameOfLife game(10,15,100);
    game.print();
    game.shuffle();
    game.print();
    game.applyRule();
    game.print();

    return 0;
}