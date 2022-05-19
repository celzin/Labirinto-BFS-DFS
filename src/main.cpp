#include"maze.hpp"
int main(){

    bool visited[N][M];
    // Primeiro define o visitado
    memset(visited, true, sizeof(visited));
    // Matriz labirinto
    int maze_puzzle[N][M] = {
    // Os zeros são as paredes
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };

    int a1 = 3;
    int a2 = 4;

    cout << "O número total de caminhos usando BFS é " << BFS_Search(maze_puzzle) << endl << endl;
    if (IsReaching(maze_puzzle,a1,a2,visited)){
        cout << "Caminho encontrado!" << '\n';
    }else
        cout << "Caminho não encontrado!" << '\n';

    return 0;

    //char arquivo[] = "arquivo.txt";
    //fileInfo(arquivo);

    // // REMOVE O ESPAÇO E O QUEBRA LINHA
    //     char sep[] = ",  |\n";
    //     char line[50];
    //     char *token;

    //     // LÊ A PRIMEIRA LINHA DO ARQUIVO E ARMAZENA O TAMANHO DA MATRIZ
    //     fgets(line, 50, f_Matriz);
    //     token = strtok(line, sep);
    //     int linha = atoi(token);
    //     token = strtok(NULL, sep);
    //     int coluna = atoi(token);

    //     // APÓS LER O TAMANHO CRIA A MATRIZ
    //     int maze_puzzle[linha][coluna];

    //     // VARIÁVEIS AUXILIARES, Y->COLUNA X->LINHA
    //     int x = 0, y = 0;

    //     while (fgets(line, 50, f_Matriz) != NULL)
    //     {
    //         token = strtok(line, sep);
    //         y = 0;

    //         // ENQUANTO A LINHA NAO FOR NULL, LÊ OS VALORES E ARMAZENA
    //         while (token != NULL)
    //         {
    //             maze_puzzle[x][y] = atoi(token);
    //             y++;
    //             token = strtok(NULL, sep);
    //         }
    //         // CASO CHEGAR NO FINAL DA LINHA,O VALOR DA COLUNA RESERA E SOMA +1 NA LINHA;
    //         x++;
    //         printf("\n");
    //     }

    //     // PRINT MATRIZ E TAMANHO
    //     printf("Matriz tamanho [%d][%d]\n\n", linha, coluna);
    //     for (x = 0; x < linha; x++)
    //     {
    //         for (y = 0; y < coluna; y++)
    //         {
    //             printf("%d ", maze_puzzle[x][y]);
    //         }
    //         printf("\n");
    //     }
}
