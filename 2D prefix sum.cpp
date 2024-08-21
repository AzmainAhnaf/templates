#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int row, col;
    cin >> row >> col;

    // making initial 2d array
    vector<vector<int>> a(row, vector<int>(col));
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> a[i][j];
        }
    }

    // creating 2d prefix sum array
    vector<vector<int>> prefix(row + 1, vector<int>(col + 1));
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++){
            prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }
}

int main(void)
{
    solve();
}
