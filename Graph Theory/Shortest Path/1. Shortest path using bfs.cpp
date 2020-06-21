#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, e, c, u, v;
    cin >> n >> e;
    vector<int> edge[n];
    vector<int> cost[n];

    for (int i = 0; i < e; i++){
        cin >> u >> v >> c;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }

    int d[n + 1], vcost, ans;
    for (int i = 0; i <= n; i++)d[i] = INT_MAX;

    queue<int> q;

    int source, destination;
    cin >> source >> destination;
    q.push(source);
    d[source] = 0;

    while (!q.empty()){
        int u = q.front();
        int ucost = d[u];
        q.pop();

        printf("\nnow processing node = %d\n", u);

        for (int i = 0; i < edge[u].size(); i++){
            int v = edge[u][i];
            vcost = cost[u][i] + ucost;
            printf("node = %d cost = %d\n", v, vcost);
            if (d[v] > vcost){
                printf("previous cost = %d changed cost = %d\n", d[v], vcost);
                d[v] = vcost;
                printf("node %d inserted into queue\n", v);
                q.push(v);
            }
        }
    }

    ans = d[destination];
    for (int i = 0; i < n; i++){
        printf("shortest path from %d to %d = %d\n", source, i, d[i]);
    }
    return 0;
}
