#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter the adjacency matrix:\n";
    cout << "Enter 0 for no edge (except diagonal):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];

            if (i != j && graph[i][j] == 0)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][k] != INT_MAX &&
                    graph[k][j] != INT_MAX &&
                    graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Display shortest distance matrix
    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INT_MAX)
                cout << "INF\t";
            else
                cout << graph[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
