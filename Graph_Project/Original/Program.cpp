#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int src, dest, cost;
};

bool compare(Edge a, Edge b)
{
    return a.cost < b.cost;
}

int findParent(int parent[], int v)
{
    if (parent[v] == v)
        return v;

    return findParent(parent, parent[v]);
}

int main()
{
    int V, E;

    cout << "Enter number of villages: ";
    cin >> V;

    cout << "Enter number of roads: ";
    cin >> E;

    Edge edges[100];

    cout << "\nEnter roads (village1 village2 cost):\n";

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].src
            >> edges[i].dest
            >> edges[i].cost;
    }

    sort(edges, edges + E, compare);

    int parent[100];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int selected = 0;

    cout << "\nSelected roads:\n";

    for (int i = 0; i < E && selected < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        if (parentU != parentV)
        {
            cout << u << " - " << v
                 << " : " << edges[i].cost << endl;

            parent[parentU] = parentV;

            totalCost += edges[i].cost;
            selected++;
        }
    }

    cout << "\nMinimum total road-building cost: "
         << totalCost << endl;

    if (selected == V - 1)
        cout << "All villages can be connected.\n";
    else
        cout << "All villages cannot be connected.\n";

    return 0;
}
