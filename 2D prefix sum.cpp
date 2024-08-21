#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> make_2d_prefix_sum(vector<vector<int>> a, int row, int col){
    // creating 2d prefix sum array
    vector<vector<int>> prefix(row + 1, vector<int>(col + 1));
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= col; j++){
            prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }
    return prefix;
}

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
    vector<vector<int>> pref = make_2d_prefix_sum(a, row, col);
    for (int i = 0; i <= row; i++){
        for (int j = 0; j <= col; j++){
            cout << pref[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void)
{
    solve();
}
