#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int parent[10];

int find(int x)
{
    if (parent[x] == x)
        return x;

    return find(parent[x]);
}

void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);

    parent[rootV] = rootU;
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[20];

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Initialize parent
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    // Sort edges by weight
    sort(edges, edges + e, compare);

    int totalCost = 0;
    int count = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (int i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        // Check whether adding this edge creates a cycle
        if (find(u) != find(v))
        {
            cout << u << " - " << v
                 << "\t" << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSet(u, v);

            count++;
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}