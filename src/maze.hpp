#define N 4
#define M 5
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Coordenadas do labirinto
class Node {
    public:
        int x, y;
        int dir;
    
    Node(int a, int b){
        x = a;
        y = b;
        dir = 0;
    }
};
int BFS_Search(int mazes[N][M]);
bool IsReaching(int maze[N][M], int a1, int a2,bool visited[N][M]);
//void fileInfo(char arquivo[]);