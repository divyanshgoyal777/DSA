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

void bfs(vector<Edge> graph[], int src, bool isVisited[])
{
    priority_queue<int, vector<int>, greater<int>> pq;
    isVisited[src] = true;
    pq.push(src);
    while (!pq.empty())
    {
        int curr = pq.top();
        pq.pop();
        cout << curr << " ";
        for (int i = 0; i < graph[curr].size(); i++)
        {
            int neighbor = graph[curr][i].dest;
            if (!isVisited[neighbor])
            {
                isVisited[neighbor] = true;
                pq.push(neighbor);
            }
        }
    }
}

int main()
{
    int vertices = 7;
    vector<Edge> graph[vertices];
    bool isVisited[vertices] = {false};
    int src = 0;

    graph[0].push_back(Edge(1, 5));
    graph[0].push_back(Edge(2, 2));
    graph[1].push_back(Edge(0, 5));
    graph[1].push_back(Edge(3, 11));
    graph[2].push_back(Edge(0, 2));
    graph[2].push_back(Edge(4, 10));
    graph[3].push_back(Edge(1, 11));
    graph[3].push_back(Edge(5, 12));
    graph[4].push_back(Edge(2, 10));
    graph[4].push_back(Edge(5, 15));
    graph[5].push_back(Edge(3, 12));
    graph[5].push_back(Edge(4, 15));
    graph[5].push_back(Edge(6, 1));
    graph[6].push_back(Edge(5, 1));

    bfs(graph, src, isVisited);

    return 0;
}
