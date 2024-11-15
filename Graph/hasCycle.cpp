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

void dfsUtil(vector<Edge> graph[], int src, bool isVisited[])
{
    isVisited[src] = true;
    cout << src << " ";
    for (const Edge &e : graph[src])
    {
        if (!isVisited[e.dest])
        {
            dfsUtil(graph, e.dest, isVisited);
        }
    }
}

void dfs(vector<Edge> graph[], int vertices)
{
    bool isVisited[vertices] = {false};
    for (int i = 0; i < vertices; i++)
    {
        if (!isVisited[i])
        {
            dfsUtil(graph, i, isVisited);
            cout << endl;
        }
    }
}

bool hasCycleUtil(vector<Edge> graph[], bool isVisited[], int src, int parent)
{
    isVisited[src] = true;
    for (const Edge &e : graph[src])
    {
        int neighbor = e.dest;
        if (!isVisited[neighbor])
        {
            if (hasCycleUtil(graph, isVisited, neighbor, src))
            {
                return true;
            }
        }
        else
        {
            if (parent != src)
            {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(vector<Edge> graph[], int vertices)
{
    bool isVisited[vertices] = {false};
    for (int i = 0; i < vertices; i++)
    {
        if (!isVisited[i])
        {
            if(hasCycleUtil(graph, isVisited, i, -1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int vertices = 7;
    vector<Edge> graph[vertices];

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

    cout << "DFS traversal of the graph:" << endl;
    dfs(graph, vertices);

    if (hasCycle(graph, vertices))
    {
        cout << "Cycle found!";
    }
    else
    {
        cout << "Cycle not found!";
    }
    return 0;
}
