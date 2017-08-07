/********
 Hack 2D array based solution to Game of Life to use for validity testing.
 Runs in 8 bit number space.
********/

#include <iostream>
#include <fstream>

using namespace std;

typedef int8_t life_t;

void printBoard(life_t board[256][256]) {
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            if (board[i][j])
                cout << i-128 << "," << j-128 << endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    int64_t t1 = LLONG_MIN;
    int64_t t2 = LLONG_MAX;
    
    
    ifstream inf("state_test.in");
    if (!inf) {
        cerr << "Could not open state.in for reading" << endl;
    }
    
    life_t board[256][256] = {0};
    
    // load initial live cells from file
    while (inf) {
        string s;
        if (!getline(inf, s)) break;
        
        life_t x = 0, y = 0;
        int ix = 0, iy = 0;
        sscanf(s.c_str(), "%d,%d", &ix, &iy);
        x = (life_t)ix;
        y = (life_t)iy;
        
        board[x + 128][y + 128] = 1;
    }
    
    cout << "Live cells at generation 0" << endl;
    printBoard(board);
    
    size_t generations = 100;
    for (size_t g = 0; g < generations; ++g) {
        life_t nextBoard[256][256] = {0};
        
        // for each cell in the space...
        for (int x = -128; x <= 127; ++x) { // need ints here so we can reach +128 without rolling over...
            for (int y = -128; y <= 127; ++y) {
                // count neighbors
                size_t nbs = 0;
                life_t dv[] = {-1, 0, 1};
                for (life_t dx = 0; dx < 3; ++dx) {
                    for (life_t dy = 0; dy < 3; ++dy) {
                        if (!dv[dx] && !dv[dy]) continue;
                        
                        life_t nx = x + dv[dx];
                        life_t ny = y + dv[dy];
                        
                        // neighbor here, increment
                        if (board[nx + 128][ny + 128]) nbs++;
                    }
                }
                
                int adj_x = x + 128;
                int adj_y = y + 128;
                // alive -> dead
                if (board[adj_x][adj_y]) {
                    nextBoard[adj_x][adj_y] = 1;
                    if (nbs < 2 || nbs > 3)
                        nextBoard[adj_x][adj_y] = 0;
                } else if(nbs == 3) {
                    // dead -> alive
                    nextBoard[adj_x][adj_y] = 1;
                }
            }
        }
        
        // copy results back to board
        for (int i = 0; i < 256; ++i) {
            for (int j = 0; j < 256; ++j) {
                board[i][j] = nextBoard[i][j];
            }
        }
        
        cout << "Live cells at generation " << g+1 << endl;
        printBoard(board);
    }

    return 0;
}
