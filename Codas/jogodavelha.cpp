#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

void clearScreen() {
    system("cls"); // Para Windows
}

void drawBoard(char board[3][3])
{
    cout << "\n   1   2   3\n";
    cout << "  -----------\n";
    for (int i = 0; i < 3; i++) {
        cout << (char)('A' + i) << " | ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n  -----------\n";
    }
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

bool getPlayerMove(int& row, int& col, char player, char board[3][3]) {
    char rowChar;
    int inputCol;
    
    while (true) {
        cout << "\nJogador " << player << ", digite a linha (A-C) e a coluna (1-3): ";
        
        if (!(cin >> rowChar >> inputCol)) {
            cout << "Entrada inválida! Por favor, digite uma letra seguida de um número.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        // Convert input to 0-based indices
        col = inputCol - 1;
        rowChar = toupper(rowChar);
        
        if (rowChar >= 'A' && rowChar <= 'C') {
            row = rowChar - 'A';
        } else {
            cout << "Linha inválida! Por favor, digite A, B ou C.\n";
            continue;
        }
        
        if (col < 0 || col > 2) {
            cout << "Coluna inválida! Por favor, digite um número entre 1-3.\n";
            continue;
        }
        
        if (board[row][col] != ' ') {
            cout << "Posição já ocupada! Tente novamente.\n";
            continue;
        }
        
        return true;
    }
}

bool checkWin(char board[3][3], char player)
{
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player
            && board[i][2] == player)
            return true;
    }
    
    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player
            && board[2][i] == player)
            return true;
    }
    
    // Verificar diagonal principal
    if (board[0][0] == player && board[1][1] == player
        && board[2][2] == player)
        return true;
        
    // Verificar diagonal secundária
    if (board[0][2] == player && board[1][1] == player
        && board[2][0] == player)
        return true;
        
    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool playAgain() {
    char choice;
    cout << "\nDeseja jogar novamente? (s/n): ";
    cin >> choice;
    return (tolower(choice) == 's');
}

void displayGameResult(char board[3][3], char player, bool gameWon) {
    drawBoard(board);
    if (gameWon) {
        cout << "\nJogador " << player << " venceu!\n";
    } else {
        cout << "\nEmpate!\n";
    }
}

int main()
{
    bool playingGame = true;
    
    cout << "Bem-vindo ao Jogo da Velha!\n";
    cout << "Instruções: Digite a linha (A-C) e a coluna (1-3)\n";
    cout << "Exemplo: B 2 (para linha B, coluna 2)\n";
    
    while (playingGame) {
        char board[3][3];
        initializeBoard(board);
        char player = 'X';
        int row, col;
        bool gameWon = false;
        
        cout << "\n=== Novo Jogo Iniciado ===\n";
        
        while (!gameWon && !isBoardFull(board)) {
            clearScreen();
            cout << "Jogo da Velha\n";
            drawBoard(board);
            
            if (getPlayerMove(row, col, player, board)) {
                board[row][col] = player;
                
                if (checkWin(board, player)) {
                    gameWon = true;
                    displayGameResult(board, player, true);
                    break;
                }
                
                // Alternar jogador
                player = (player == 'X') ? 'O' : 'X';
            }
        }
        
        if (!gameWon && isBoardFull(board)) {
            displayGameResult(board, player, false);
        }
        
        playingGame = playAgain();
    }
    
    cout << "\nObrigado por jogar!\n";
    return 0;
}