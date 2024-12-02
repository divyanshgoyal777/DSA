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
    graph[0].push_back(Edge(1, 10));
    graph[0].push_back(Edge(2, 4));
    graph[1].push_back(Edge(3, 3));
    graph[1].push_back(Edge(2, 2));
    graph[2].push_back(Edge(4, 1));
    graph[4].push_back(Edge(1, 6));
}

void primsAlgorithm(vector<Edge> graph[], int vertices)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(vertices, false);
    int mstCost = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty())
    {
        pair<int, int> current = pq.top();
        pq.pop();
        int weight = current.first;
        int curr = current.second;
        if (visited[curr])
            continue;
        visited[curr] = true;
        mstCost += weight;
        for (Edge edge : graph[curr])
        {
            if (!visited[edge.dest])
            {
                pq.push(make_pair(edge.weight, edge.dest));
            }
        }
    }
    cout << "Cost of the Minimum Spanning Tree (MST): " << mstCost << endl;
}

int main()
{
    int vertices = 5;
    vector<Edge> graph[vertices];

    createGraph(graph);
    primsAlgorithm(graph, vertices);

    return 0;
}
