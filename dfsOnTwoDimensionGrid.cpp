#include <bits/stdc++.h>
using namespace std;

// Input
// 3 4
// ....
// ....
// ....
// 1 2

char grid[105][105];
bool visitedArray[105][105];
vector<pair<int, int>> pairVector = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int rowOfSource, int columnOfSource)
{
    cout << rowOfSource << " " << columnOfSource << endl;
    visitedArray[rowOfSource][columnOfSource] = true;

    for (int i = 0; i < 4; i++)
    {
        int rowOfChild, columnOfChild;
        rowOfChild = rowOfSource + pairVector[i].first;
        columnOfChild = columnOfSource + pairVector[i].second;

        cout << rowOfChild << " " << columnOfChild << endl;
    }
}

int main()
{
    int row, column;
    cin >> row >> column;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> grid[i][j];
        }
    }

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < column; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    int rowOfSource, columnOfSource;
    cin >> rowOfSource >> columnOfSource;
    dfs(rowOfSource, columnOfSource);

    return 0;
}