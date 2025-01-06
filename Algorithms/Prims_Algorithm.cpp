#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int dest, weight;
    Edge(int dest, int weight) : dest(dest), weight(weight) {}
};

void createGraph(vector<Edge> graph[])
{
    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));
    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));
    graph[2].push_back(Edge(4, 3));
    graph[3].push_back(Edge(4, 2));
    graph[3].push_back(Edge(5, 1));
    graph[4].push_back(Edge(5, 5));
}

void primMST(vector<Edge> graph[], int vertices)
{
    vector<int> key(vertices, INT_MAX), parent(vertices, -1);
    vector<bool> inMST(vertices, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;
        for (auto &edge : graph[u])
        {
            int v = edge.dest, weight = edge.weight;
            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Minimum Spanning Tree:\n";
    for (int i = 1; i < vertices; i++)
    {
        cout << parent[i] << " - " << i << "\n";
    }
}

int main()
{
    int vertices = 6;
    vector<Edge> graph[vertices];
    createGraph(graph);
    primMST(graph, vertices);
    return 0;
}
