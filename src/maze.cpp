// Labirinto que consiste em N*M
#include"maze.hpp"

int BFS_Search(int mazes[N][M]){
    queue<pair<int, int> > queues;
    // Definindo inicialmente i e j em (0, 0).
    queues.push(make_pair(0, 0));
    // Contando o número total possível de caminhos
    int count = 0;
    while (!queues.empty()) {
        pair<int, int> p = queues.front();
        queues.pop();

        // Incrementando. o destino consiste em vários caminhos
        if (p.first == N - 1 && p.second == M - 1)
            count++;
        if (p.first + 1 < N && mazes[p.first + 1][p.second] == 1){
            queues.push(make_pair(p.first + 1, p.second));
        }
        if (p.second + 1 < M && mazes[p.first][p.second + 1] == 1){
            queues.push(make_pair(p.first, p.second + 1));
        }
    }

    return count;
}

bool IsReaching(int maze[N][M],int a1,int a2,bool visited[N][M]){
    // Definindo inicialmente i e j em (0, 0).
    int i = 0, j = 0;
    stack<Node> stacks;
    Node temporary(i, j);
    stacks.push(temporary);

    while (!stacks.empty()){

        temporary = stacks.top();
        int d = temporary.dir;
        i = temporary.x, j = temporary.y;

        // empurrando o node na pilha novamente.
        temporary.dir++;
        stacks.pop();
        stacks.push(temporary);

        // Se chegarmos ao ponto final retorna true
        if (i == a1 and j == a2)
        {
            //imprimindo as coordenadas
            while (!stacks.empty()){
                Node temporary1 = stacks.top();
                cout << "(" << temporary1.x << "," << temporary1.y << ")<-";
                stacks.pop();
            }
            cout << endl << endl;
            return true;
        }

        if (d == 0){
            if (i - 1 >= 0 and maze[i - 1][j] and visited[i - 1][j]){
                Node temp1(i - 1, j);
                visited[i - 1][j] = false;
                stacks.push(temp1);
            }
        }

        else if (d == 1){
            if (j - 1 >= 0 and maze[i][j - 1] and visited[i][j - 1]){
                Node temp1(i, j - 1);
                visited[i][j - 1] = false;
                stacks.push(temp1);
            }
        }
        else if (d == 2){
            if (i + 1 < N and maze[i + 1][j] and visited[i + 1][j]){
                Node temp1(i + 1, j);
                visited[i + 1][j] = false;
                stacks.push(temp1);
            }
        }
        else if (d == 3){
            if (j + 1 < M and maze[i][j + 1] and visited[i][j + 1]){
                Node temp1(i, j + 1);
                visited[i][j + 1] = false;
                stacks.push(temp1);
            }
        }

        // se for visitado então retira o node
        else{
            visited[temporary.x][temporary.y] = true;
            stacks.pop();
        }
    }
    return false;
}

/* void fileInfo(char arquivo[]){
    
    FILE *f_Matriz;
    f_Matriz = fopen(arquivo, "rt");

    if (f_Matriz != NULL)
    {
        cout << "\n\n";
        cout << "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "      @                          @\n";
        cout << "      @      ARQUIVO ABERTO      @\n";
        cout << "      @                          @\n";
        cout << "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
    }
    else
    {
        cout << "\n\n";
        cout << "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "      @                          @\n";
        cout << "      @  ARQUIVO NAO ENCONTRADO  @\n";
        cout << "      @                          @\n";
        cout << "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";
        fflush(stdin);
        exit(0);
    }
}
 */