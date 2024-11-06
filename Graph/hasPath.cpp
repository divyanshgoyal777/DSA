#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int dist;
    int weight;

    Edge(int dist, int weight)
    {
        this->dist = dist;
        this->weight = weight;
    }
};

bool hasPath(vector<Edge> graph[], int src, int dest, bool isVisited[])
{
    if (src == dest)
    {
        return true;
    }
    isVisited[src] = true;
    for (int i = 0; i < graph[src].size(); i++)
    {
        Edge e = graph[src][i];
        if (!isVisited[e.dist] && hasPath(graph, e.dist, dest, isVisited))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int vertices = 7;
    vector<Edge> graph[vertices];
    bool isVisited[vertices] = {false};
    int src = 0;
    int dest = 4;

    // 0th Node
    graph[0].push_back(Edge(1, 5));
    graph[0].push_back(Edge(2, 2));

    // 1st Node
    graph[1].push_back(Edge(0, 5));
    graph[1].push_back(Edge(3, 11));

    // 2nd Node
    graph[2].push_back(Edge(0, 2));
    graph[2].push_back(Edge(4, 10));

    // 3th Node
    graph[3].push_back(Edge(1, 11));
    graph[3].push_back(Edge(5, 12));

    // 4th Node
    graph[4].push_back(Edge(2, 10));
    graph[4].push_back(Edge(5, 15));

    // 5th Node
    graph[5].push_back(Edge(3, 12));
    graph[5].push_back(Edge(4, 15));
    graph[5].push_back(Edge(6, 1));

    // 6th Node
    graph[6].push_back(Edge(5, 1));

    if (hasPath(graph, src, dest, isVisited))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}