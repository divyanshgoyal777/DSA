#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dest, weight;
    Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}
};

void createEdges(vector<Edge> &edges)
{
    edges.push_back(Edge(0, 1, 2));
    edges.push_back(Edge(0, 2, 4));
    edges.push_back(Edge(1, 2, 1));
    edges.push_back(Edge(1, 3, 7));
    edges.push_back(Edge(2, 4, 3));
    edges.push_back(Edge(3, 4, 2));
    edges.push_back(Edge(3, 5, 1));
    edges.push_back(Edge(4, 5, 5));
}

int findParent(int node, vector<int> &parent)
{
    if (node != parent[node])
    {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

void unionSets(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    if (rootU != rootV)
    {
        if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskal(int vertices, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b)
         { return a.weight < b.weight; });

    vector<int> parent(vertices), rank(vertices, 0);
    iota(parent.begin(), parent.end(), 0); // Initialize parent array

    int mstWeight = 0;
    vector<Edge> mst;

    for (auto &edge : edges)
    {
        if (findParent(edge.src, parent) != findParent(edge.dest, parent))
        {
            mst.push_back(edge);
            mstWeight += edge.weight;
            unionSets(edge.src, edge.dest, parent, rank);
        }
    }

    cout << "Minimum Spanning Tree weight: " << mstWeight << "\n";
    for (auto &edge : mst)
    {
        cout << "Edge: " << edge.src << " - " << edge.dest << ", Weight: " << edge.weight << "\n";
    }
}

int main()
{
    int vertices = 6;
    vector<Edge> edges;
    createEdges(edges);
    kruskal(vertices, edges);
    return 0;
}
