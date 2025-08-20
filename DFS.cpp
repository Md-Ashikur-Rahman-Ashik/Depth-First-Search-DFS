// Input
// 7 7
// 0 2
// 2 4
// 0 1
// 1 5
// 1 3
// 0 3
// 3 6

#include <bits/stdc++.h>
using namespace std;

vector<int> adjacencyList[1005];
bool visitedArray[1005];

void dfs(int sourceNode)
{
    cout << sourceNode << " ";
    visitedArray[sourceNode] = true;

    for (auto childNode : adjacencyList[sourceNode])
    {
        if (visitedArray[childNode] == false)
        {
            dfs(childNode);
        }
    }
}

int main()
{
    int numberOfNode, numberOfEdge;
    cin >> numberOfNode >> numberOfEdge;
    for (int i = 0; i < numberOfEdge; i++)
    {
        int firstValue, secondValue;
        cin >> firstValue >> secondValue;
        adjacencyList[firstValue].push_back(secondValue);
        adjacencyList[secondValue].push_back(firstValue);
    }

    memset(visitedArray, false, sizeof(visitedArray));

    dfs(0);

    return 0;
}