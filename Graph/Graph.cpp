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

int main()
{
    vector<vector<Edge>> graph;
    graph[0].push_back(Edge(1, 5));
    graph[0].push_back(Edge(2, 2));
    graph[1].push_back(Edge(0, 2));

    return 0;
}