#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, vector<int>> adj;
    void addEdge(int v, int w);
    void Check(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::Check(int v)
{
    visited[v] = true;
    for (int j = 0; j < adj[v].size(); ++j)
    {
        if (!visited[adj[v][j]])
        {
            Check(adj[v][j]);
        }
    }
}

void Rass(vector<string>names)
{
    for (int t = 0; t < names.size(); t++)
    {
        Graph g;
        ifstream fin(names[t], ios::in);
        int N, M;
        fin >> N >> M;
        for (int j = 0; j < M; j++)
        {
            int a, b;
            fin >> a >> b;
            a--; b--;
            g.addEdge(a, b);
        }
        bool checker = true;
        for (int i = 0; i < N; i++)
        {
            g.Check(i);
            int visitedcounter = g.visited.size();
            if (visitedcounter != N)
            {
                checker = false;
                break;
            }
            g.visited.clear();
        }
        if (checker) cout << "Strongly connected graph" << endl;
        else cout << "Not strongly connected graph" << endl;
    }
}

int main()
{
    string name1 = "E:/Tests/connected1.txt", name2 = "E:/Tests/connected2.txt", name3 = "E:/Tests/connected3.txt", name4 = "E:/Tests/notconnected1.txt", name5 = "E:/Tests/notconnected2.txt";
    vector<string>names;
    names.push_back(name1);
    names.push_back(name2);
    names.push_back(name3);
    names.push_back(name4);
    names.push_back(name5);
    Rass(names);
    return 0;
}