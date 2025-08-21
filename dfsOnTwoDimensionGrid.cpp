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

bool valid(int rowOfChild, int columnOfChild, int row, int column)
{
    if (rowOfChild < 0 || rowOfChild >= row || columnOfChild < 0 || columnOfChild >= column)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void dfs(int rowOfSource, int columnOfSource, int row, int column)
{
    cout << rowOfSource << " " << columnOfSource << endl;
    visitedArray[rowOfSource][columnOfSource] = true;

    for (int i = 0; i < 4; i++)
    {
        int rowOfChild, columnOfChild;
        rowOfChild = rowOfSource + pairVector[i].first;
        columnOfChild = columnOfSource + pairVector[i].second;

        // cout << rowOfChild << " " << columnOfChild << endl;

        bool isValid = valid(rowOfChild, columnOfChild, row, column);

        if (isValid == true && visitedArray[rowOfChild][columnOfChild] == false)
        {
            dfs(rowOfChild, columnOfChild, row, column);
        }
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

    memset(visitedArray, false, sizeof(visitedArray));

    int rowOfSource, columnOfSource;
    cin >> rowOfSource >> columnOfSource;
    dfs(rowOfSource, columnOfSource, row, column);

    return 0;
}