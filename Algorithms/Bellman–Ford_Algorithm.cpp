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

void bellmanFord(int vertices, int edgesCount, vector<Edge> &edges, int src)
{
    vector<int> dist(vertices, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < vertices - 1; i++)
    {
        for (auto &edge : edges)
        {
            if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest])
            {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (auto &edge : edges)
    {
        if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest])
        {
            cout << "Negative weight cycle detected!\n";
            return;
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << "Vertex " << i << ": " << (dist[i] == INT_MAX ? "Infinity" : to_string(dist[i])) << endl;
    }
}

int main()
{
    int vertices = 6;
    vector<Edge> edges;
    createEdges(edges);
    bellmanFord(vertices, edges.size(), edges, 0);
    return 0;
}