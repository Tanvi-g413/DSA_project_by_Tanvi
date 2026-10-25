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

    if (V <= 0 || V > 100 || E < 0 || E > 100)
    {
        cout << "Invalid number of villages or roads.\n";
        return 0;
    }

    Edge edges[100];

    cout << "\nEnter roads (source destination weight):\n";

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].src
            >> edges[i].dest
            >> edges[i].cost;

        if (edges[i].src < 0 || edges[i].src >= V ||
            edges[i].dest < 0 || edges[i].dest >= V)
        {
            cout << "Invalid village number.\n";
            return 0;
        }
    }

    // Modification A: Update edge weight
    int u, v, newWeight;
    bool found = false;

    cout << "\nEnter edge to update (source destination): ";
    cin >> u >> v;

    for (int i = 0; i < E; i++)
    {
        if ((edges[i].src == u && edges[i].dest == v) ||
            (edges[i].src == v && edges[i].dest == u))
        {
            cout << "Enter new weight: ";
            cin >> newWeight;

            edges[i].cost = newWeight;
            found = true;
            break;
        }
    }

    if (found)
        cout << "Edge weight updated successfully.\n";
    else
        cout << "Edge not found. Original weights retained.\n";

    // Sort edges by increasing cost
    sort(edges, edges + E, compare);

    int parent[100];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int selected = 0;

    cout << "\nSelected roads:\n";

    // Apply Kruskal's algorithm
    for (int i = 0; i < E && selected < V - 1; i++)
    {
        int parentU = findParent(parent, edges[i].src);
        int parentV = findParent(parent, edges[i].dest);

        if (parentU != parentV)
        {
            parent[parentU] = parentV;

            totalCost += edges[i].cost;
            selected++;

            // Modification B: Running total cost
            cout << edges[i].src << " - "
                 << edges[i].dest << " : "
                 << edges[i].cost
                 << " | Running Cost: "
                 << totalCost << endl;
        }
    }

    cout << "\nMinimum total road-building cost: "
         << totalCost << endl;

    // Modification C: Check connectivity
    if (selected == V - 1)
    {
        cout << "A spanning tree can be formed.\n";
        cout << "All villages are connected.\n";
    }
    else
    {
        cout << "A spanning tree cannot be formed.\n";
        cout << "The graph is disconnected.\n";
    }

    return 0;
}
