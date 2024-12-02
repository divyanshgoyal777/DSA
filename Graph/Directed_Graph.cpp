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
    graph[0].push_back(Edge(4, 7));
    graph[1].push_back(Edge(3, 4));
    graph[2].push_back(Edge(3, 5));
    graph[3].push_back(Edge(0, 6));
    graph[4].push_back(Edge(1, 2));
    graph[5].push_back(Edge(1, 1));
    graph[5].push_back(Edge(2, 3));
}

void dfs(vector<Edge> graph[], int src, bool isVisited[])
{
    if (isVisited[src])
    {
        return;
    }
    cout << src << " ";
    isVisited[src] = true;
    for (int i = 0; i < graph[src].size(); i++)
    {
        Edge e = graph[src][i];
        if (!isVisited[e.dest])
        {
            dfs(graph, e.dest, isVisited);
        }
    }
}

int main()
{
    int vertices = 7;
    vector<Edge> graph[vertices];
    bool isVisited[vertices] = {false};
    int src = 0;

    createGraph(graph);
    dfs(graph, src, isVisited);

    return 0;
}
