#include <iostream>
using namespace std;

class Game
{
private:
    int siz;
    char **board;
    bool player = false;

    void draw_board()
    {
        for (int i = 0; i < siz; i++)
        {
            for (int j = 0; j < siz; j++)
            {
                board[i][j] = '.';
            }
        }
    }

    void print_board()
    {
        for (int i = 0; i < siz; i++)
        {
            for (int j = 0; j < siz; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void turn()
    {
        player = !player;
    }

    void draw_position(int r, int c)
    {
        if (player)
        {
            board[r][c] = 'x';
        }
        else
        {
            board[r][c] = 'o';
        }
    }

    bool valid_position(int r, int c)
    {
        if (r >= 0 && r < siz && c >= 0 && c < siz && board[r][c] == '.')
        {
            return true;
        }
        return false;
    }

    bool check_rows()
    {
        for (int i = 0; i < siz; i++)
        {
            int p1 = 0;
            int p2 = 0;
            for (int j = 0; j < siz; j++)
            {
                if (board[i][j] == 'x')
                {
                    p1++;
                }
                else if (board[i][j] == 'o')
                {
                    p2++;
                }
            }
            if (p1 == siz || p2 == siz)
            {
                return true;
            }
        }
        return false;
    }

    bool check_columns()
    {
        for (int i = 0; i < siz; i++)
        {
            int p1 = 0;
            int p2 = 0;
            for (int j = 0; j < siz; j++)
            {
                if (board[j][i] == 'x')
                {
                    p1++;
                }
                else if (board[j][i] == 'o')
                {
                    p2++;
                }
            }
            if (p1 == siz || p2 == siz)
            {
                return true;
            }
        }
        return false;
    }

    bool check_left_diagonal()
    {
        int p1 = 0;
        int p2 = 0;
        for (int i = 0; i < siz; i++)
        {
            if (board[i][i] == 'x')
            {
                p1++;
            }
            else if (board[i][i] == 'o')
            {
                p2++;
            }
        }
        if (p1 == siz || p2 == siz)
        {
            return true;
        }
        return false;
    }

    bool check_right_diagonal()
    {
        int p1 = 0;
        int p2 = 0;
        for (int i = 0, j = siz - 1; i < siz; i++, j--)
        {
            if (board[i][j] == 'x')
            {
                p1++;
            }
            else if (board[i][j] == 'o')
            {
                p2++;
            }
        }
        if (p1 == siz || p2 == siz)
        {
            return true;
        }
        return false;
    }

    bool check_winner()
    {
        if (check_columns() || check_rows() || check_left_diagonal() || check_right_diagonal())
        {
            cout << "Player " << get_player() << " wins!" << endl;
            return true;
        }
        return false;
    }

    string get_player()
    {
        return player ? "X" : "O";
    }

    bool is_full()
    {
        for (int i = 0; i < siz; i++)
        {
            for (int j = 0; j < siz; j++)
            {
                if (board[i][j] == '.')
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    Game(int size) : siz(size)
    {
        board = new char*[siz];
        for (int i = 0; i < siz; i++)
        {
            board[i] = new char[siz];
        }
        draw_board();
        print_board();
    }

    ~Game()
    {
        for (int i = 0; i < siz; i++)
        {
            delete[] board[i];
        }
        delete[] board;
    }

    void start()
    {
        while (!check_winner() && !is_full())
        {
            turn();
            int r, c;
            cout << "Player " << get_player() << " turn. Enter empty location (r, c): ";
            cin >> r >> c;
            while (!valid_position(r, c))
            {
                cout << "Invalid location. Player " << get_player() << ", enter location again (r, c): ";
                cin >> r >> c;
            }
            draw_position(r, c);
            print_board();
        }

        if (is_full() && !check_winner())
        {
            cout << "It's a draw!" << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter board size: ";
    cin >> n;
    Game xo(n);
    xo.start();
}
