#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <set>
#include <queue>

using namespace std;

const char name[100] = "E:/Tests/input.txt";
const char name2[100] = "E:/Tests/output.txt";

bool MatrixCheck(int abs, int task)
{
    if (task > abs) return false;
    else return true;
}

bool MatrixCheck2(int** a, int n)
{
    queue<int> Queue;
    vector <int> nodes(n);
    int check = 0;
    Queue.push(0);
    while (!Queue.empty())
    {
        int node = Queue.front();
        Queue.pop();
        nodes[node] = 2;
        for (int j = 0; j < n; j++)
        {
            if (a[node][j] != 0 && nodes[j] == 0)
            {
                Queue.push(j);
                nodes[j] = 1;
            }
        }
        check++;
    }
    if (check == n) return true;
    else return false;
}

void Copy(int** a, int** b, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

int main() 
{
    ifstream fin(name, ios::in);
    ofstream fout(name2, ios::out);
    int N, M, K, X, Y, W;
    vector<pair<int, int>> pcheck;
    vector<int> remaining;
    vector<pair<int, int>> edg;
    fin >> N >> M >> K;
    int** G = new int* [N];
    int** R = new int* [N];
    for (int i = 0; i < N; i++)
    {
        G[i] = new int[N];
        R[i] = new int[N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            G[i][j] = 0;
        }
    }

    int absolutegr = 0;
    for (int t = 0; t < M; t++)
    {
        fin >> X >> Y >> W;
        pair<int, int> time;
        time.first = X;
        time.second = Y;
        edg.push_back(time);
        X--; 
        Y--;
        if (W == 0)
        {
            G[X][Y] = 1;
            G[Y][X] = 1;
            absolutegr++;
        }
        else if (W == 1)
        {
            G[X][Y] = 2;  
            G[Y][X] = 2;
        }
    }
    Copy(R, G, N);
    
    if (!MatrixCheck(absolutegr, K))
    {
        fout << "no solution" << endl;
        for (int i = 0; i < N; i++)
        {
          delete[] G[i];
          delete[] R[i];
        }
        delete[]G;
        delete[]R;
        return 0;
    }

    if (!MatrixCheck2(G, N))
    {
      fout << "no solution" << endl;
      for (int i = 0; i < N; i++)
      {
        delete[] G[i];
        delete[] R[i];
      }
      delete[]G;
      delete[]R;
      return 0;
    }

    int edge = 0, Matrixchecker = 0;
    int *visit = new int[N];

    p1:
    for (int i = 0; i < N; i++) 
    {
        visit[i] = false;
    } 
    Copy(G, R, N);
    visit[Matrixchecker] = true;
    int x;           
    int y;            
    absolutegr = 0;
    while (edge < N - 1) 
    {
        int min = INT_MAX;
        x = 0;
        y = 0;   

        for (int i = 0; i < N; i++) {
            if (visit[i]) {
                for (int j = 0; j < N; j++) {
                    if (!visit[j] && G[i][j]) { 
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        } 

        if (G[x][y] == 1)
        {
            pair <int, int> zeroedge;
            zeroedge.first = x;
            zeroedge.second = y;
            pcheck.push_back(zeroedge);
            absolutegr++;
        }

        int a = x + 1, b = y + 1;
        for (int f = 0; f < edg.size(); f++)
        {
            if ((a == edg[f].first && b == edg[f].second) || (b == edg[f].first && a == edg[f].second))
            {
                remaining.push_back(edg[f].first);
                remaining.push_back(edg[f].second);
            }
        }
        remaining.push_back(G[x][y] - 1);
        visit[y] = true;
        edge++;

        if (absolutegr == K)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {    
                    if (G[i][j] == 1) {
                        bool sign = false;
                        for (int t = 0; t < pcheck.size(); t++)
                        {                  
                            if ((i == pcheck[t].first && j == pcheck[t].second) || (j == pcheck[t].first && i == pcheck[t].second))
                            {
                                sign = true;
                            }
                        }
                        if (!sign) G[i][j] = 0;
                    }
                }
            }

            if (!MatrixCheck2(G, N))
            {
                Matrixchecker++;
                if (Matrixchecker == N)
                {
                fout << "no solution" << endl;
                goto p2;
                }
                edge = 0;
                absolutegr = 0;
                remaining.clear();
                pcheck.clear();
                goto p1;              
            }
        }
    }
    absolutegr = 0;
    for (int i = 0; i < remaining.size(); i++)
    {
        if (remaining[i] == 0)
            absolutegr++;
    }
    
    if (absolutegr < K)
    {
        fout << "no solution" << endl;
        goto p2;
    }

    for (int g = 0; g < remaining.size(); g++)
    {
        fout << remaining[g] << " ";
        if ((g + 1) % 3 == 0) fout << endl;
    }
    p2:
    for (int i = 0; i < N; i++)
    {
        delete[] G[i];
        delete[] R[i];
    }
    delete[]G;
    delete[]R;
    delete[]visit;
    return 0;
}

















//for (int i = 0; i < N; i++)
           //{
           //    for (int j = 0; j < N; j++)
           //    {
           //        cout << G[i][j] << " ";
           //    }
           //    cout << endl;
    /*       //}
7 8 4
1 2 1
1 7 0
1 6 1
7 4 0
2 3 1
3 4 1
7 5 1
6 5 0

6 7 3
1 2 0 
1 3 0
1 6 1
2 4 1
3 4 1
4 5 0
6 5 1
*/
/*if (absolutegr < K)
    {
        int ender = K - absolutegr;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (G[i][j] == 1 && ender != 0)
                {
                    bool sign = false;
                    for (int t = 0; t < pcheck.size(); t++)
                    {
                        if ((i == pcheck[t].first && j == pcheck[t].second) || (j == pcheck[t].first && i == pcheck[t].second))
                        {
                            sign = true;
                        }
                    }
                    if (!sign)
                    {
                        int a = i + 1, b = j + 1;
                        for (int f = 0; f < edg.size(); f++)
                        {
                            if ((a == edg[f].first && b == edg[f].second) || (b == edg[f].first && a == edg[f].second))
                            {
                                remaining.push_back(edg[f].first);
                                remaining.push_back(edg[f].second);
                            }
                        }
                        remaining.push_back(G[i][j] - 1);
                        ender--;
                    }
                }
            }
        }
    }*/