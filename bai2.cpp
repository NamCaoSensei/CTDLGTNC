#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

#define TRUE 1

#define FALSE 0

#define VOCUNG 10000000

struct Graph
{
    int N;
    int **A;
};

struct Dijkstra
{
    Graph graph;
    int start;
    int end;
    int *truoc;
    int *dist;
    int *T;
};

string GetName(int v)
{
    if (v < 0) return "Unknown";
    return "V" + to_string(v + 1);
}

void Nhap(Dijkstra &d)
{
    FILE* f = freopen("inputbai2.txt", "r", stdin);
    cin >> d.graph.N;
    cin >> d.start >> d.end;

    d.graph.A = new int*[d.graph.N];
    for (int i = 0; i < d.graph.N; i++)
    {
        d.graph.A[i] = new int[d.graph.N];
        for (int j = 0; j < d.graph.N; j++)
        {
            cin >> d.graph.A[i][j];
            if (d.graph.A[i][j] == 0) d.graph.A[i][j] = VOCUNG;
        }
    }

    fclose(f);
}

void HienThi(Dijkstra d)
{
    cout << "Do thi vua nhap la:" << endl;
    cout << "- So dinh cua do thi: " << d.graph.N << endl;
    cout << "- Ma tran trong so cua do thi:" << endl;
    for (int i = 0; i < d.graph.N; i++)
    {
        for (int j = 0; j < d.graph.N; j++)
        {
            if (d.graph.A[i][j] == VOCUNG)
                cout << 0 << "\t";
            else cout << d.graph.A[i][j] << "\t";
        }
        cout << endl;
    }
}

bool CheckFullT(Dijkstra d)
{
    for (int i = 0; i < d.graph.N; i++)
    {
        if (!d.T[i]) return 0;
    }
    return 1;
}

void RunDijkstra(Dijkstra &d)
{
    d.truoc = new int[d.graph.N];
    d.dist = new int[d.graph.N];
    d.T = new int[d.graph.N];

    int s = d.start;
    for (int v = 0; v < d.graph.N; v++)
    {
        d.dist[v] = VOCUNG;
        d.truoc[v] = -1;
        d.T[v] = FALSE;
    }
    d.dist[s] = 0;

    while (!CheckFullT(d))
    {
        int u = -1, minp = VOCUNG;
        for (int v = 0; v < d.graph.N; v++)
        {
            if (!d.T[v] && d.dist[v] < minp)
            {
                u = v;
                minp = d.dist[v];
            }
        }
        if (u == -1) break;
        d.T[u] = TRUE;

        for (int v = 0; v < d.graph.N; v++)
        {
            if (!d.T[v] && d.graph.A[u][v] != VOCUNG
                    && (d.dist[u] + d.graph.A[u][v] < d.dist[v]))
            {
                d.dist[v] = d.dist[u] + d.graph.A[u][v];
                d.truoc[v] = u;
            }
        }
    }
}

void TimDuongDiNganNhat(Dijkstra &d, int u, int v)
{
    d.start = u;
    d.end = v;
    RunDijkstra(d);

    if (d.dist[v] >= VOCUNG)
    {
        cout << "Khong co duong di tu " << GetName(u)
            << " den " << GetName(v) << endl;
        return;
    }

    cout << "Duong di ngan nhat tu " << GetName(u)
        << " den " << GetName(v) << " la:" << endl;
    cout << GetName(v);
    int i = d.truoc[v];
    while (i != -1)
    {
        cout << "<=" << GetName(i);
        i = d.truoc[i];
    }
    cout << endl << "Do dai duong di la : " << d.dist[v] << endl;
}

int main()
{
    Dijkstra d;
    Nhap(d);
    HienThi(d);
    TimDuongDiNganNhat(d, d.start, d.end);

    for (int i = 0; i < d.graph.N; ++i) {
        delete[] d.graph.A[i];
    }
    delete[] d.graph.A;
    delete[] d.truoc;
    delete[] d.dist;
    delete[] d.T;
}