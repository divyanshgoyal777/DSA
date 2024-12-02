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

void kruskal(vector<Edge> graph[], int vertices, int src){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(vertices, false);
}

int main()
{
    int vertices = 6;
    vector<Edge> graph[vertices];
    createGraph(graph);
    kruskal(graph, vertices, 0);
    return 0;
}