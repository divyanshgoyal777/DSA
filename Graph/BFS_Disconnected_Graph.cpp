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

void bfsUtil(vector<Edge> graph[], int src, bool isVisited[])
{
    queue<int> q;
    q.push(src);
    isVisited[src] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (const Edge &e : graph[curr])
        {
            if (!isVisited[e.dest])
            {
                isVisited[e.dest] = true;
                q.push(e.dest);
            }
        }
    }
}

void bfs(vector<Edge> graph[], int vertices)
{
    bool isVisited[vertices] = {false};
    for (int i = 0; i < vertices; i++)
    {
        if (!isVisited[i])
        {
            bfsUtil(graph, i, isVisited);
            cout << endl;
        }
    }
}

int main()
{
    int vertices = 7;
    vector<Edge> graph[vertices];

    // Component 1
    graph[0].push_back(Edge(1, 5));
    graph[1].push_back(Edge(0, 5));
    graph[1].push_back(Edge(2, 3));
    graph[2].push_back(Edge(1, 3));

    // Component 2
    graph[3].push_back(Edge(4, 8));
    graph[4].push_back(Edge(3, 8));
    graph[4].push_back(Edge(5, 7));
    graph[5].push_back(Edge(4, 7));
    graph[5].push_back(Edge(6, 2));
    graph[6].push_back(Edge(5, 2));

    cout << "BFS traversal of the graph:" << endl;
    bfs(graph, vertices);

    return 0;
}