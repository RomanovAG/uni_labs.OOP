#include <iostream>

using namespace std;

int main()
{
    int board [10] [20];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            board[i][j] = 0;
        }
    }
    int I [2] [4] = {{1, 1, 1, 1},
        {0, 0, 0, 0}};
    int J [2] [4] = {{1, 1, 1, 0},
        {0, 0, 1, 0}};
    int T [2] [4] = {{1, 1, 1, 0},
        {0, 1, 0, 0}};
    int L [2] [4] = {{1, 1, 1, 0},
        {1, 0, 0, 0}};
    int O [2] [4] = {{1, 1, 0, 0},
        {1, 1, 0, 0}};
    int S [2] [4] = {{0, 1, 1, 0},
        {1, 1, 0, 0}};
    int Z [2] [4] = {{1, 1, 0, 0},
        {0, 1, 1, 0}};
    while(true){
        if(getch() == '\033'){
            cout << "l";
        }
    }
}
