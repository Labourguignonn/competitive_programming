#include <bits/stdc++.h>
using namespace std;

int board[9][9];
int rowUsed[9], colUsed[9], boxUsed[9];
bool found;

inline int boxIdx(int r, int c) { return (r / 3) * 3 + (c / 3); }

void solve(int i) {
    if (i == 81) {
        found = true;
        return;
    }

    int r = i / 9, c = i % 9;

    if (board[r][c] != 0) {
        solve(i + 1);
        return;
    }

    int used = rowUsed[r] | colUsed[c] | boxUsed[boxIdx(r, c)];
    int available = (~used) & 0x1FF;

    while (available && !found) {          
        int bit = available & (-available);
        available &= available - 1;
        int digit = __builtin_ctz(bit) + 1;

        board[r][c] = digit;
        rowUsed[r] |= bit;
        colUsed[c] |= bit;
        boxUsed[boxIdx(r, c)] |= bit;

        solve(i + 1);

        if (!found) {                      
            board[r][c] = 0;
            rowUsed[r] &= ~bit;
            colUsed[c] &= ~bit;
            boxUsed[boxIdx(r, c)] &= ~bit;
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        found = false;
        for (int i = 0; i < 9; i++) rowUsed[i] = colUsed[i] = boxUsed[i] = 0;

        for (int r = 0; r < 9; r++)
            for (int c = 0; c < 9; c++) {
                cin >> board[r][c];
                if (board[r][c] != 0) {
                    int bit = 1 << (board[r][c] - 1);
                    rowUsed[r] |= bit;
                    colUsed[c] |= bit;
                    boxUsed[boxIdx(r, c)] |= bit;
                }
            }

        solve(0);

        if (found) {
            for (int r = 0; r < 9; r++) {
                for (int c = 0; c < 9; c++) {
                    if (c) cout << ' ';
                    cout << board[r][c];
                }
                cout << '\n';
            }
        } else {
            cout << "No solution\n";
        }
    }

    return 0;
}