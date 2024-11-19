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

int main()
{
    int vertices = 7;
    vector<Edge> graph[vertices];

    createGraph(graph);

    return 0;
}
