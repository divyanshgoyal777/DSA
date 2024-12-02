#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int dest;
    int weight;

    Edge(int dest, int weight)
    {
        this->dest = dest;
        this->weight = weight;
    }
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

void bellmanFord(vector<Edge> graph[], int vertices, int src)
{
    vector<int> distance(vertices, INT_MAX);
    distance[src] = 0;

    for (int i = 0; i < vertices - 1; i++)
    {
        for (int u = 0; u < vertices; u++)
        {
            for (Edge edge : graph[u])
            {
                int v = edge.dest;
                int weight = edge.weight;
                if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << i << "\t" << distance[i] << endl;
    }
}

    int main()
    {
        int vertices = 7;
        vector<Edge> graph[vertices];
        bool isVisited[vertices] = {false};
        int src = 0;

        createGraph(graph);
        bellmanFord(graph, vertices, src);

        return 0;
    }
