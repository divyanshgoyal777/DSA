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

void dijkstra(vector<Edge> graph[], int vertices, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(vertices, INT_MAX);
    vector<bool> visited(vertices, false);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : graph[u]) // Use graph[u] here
        {
            int v = edge.dest, weight = edge.weight;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
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
    vector<Edge> graph[vertices];
    createGraph(graph);
    dijkstra(graph, vertices, 0);
    return 0;
}
