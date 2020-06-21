#include<bits/stdc++.h>
using namespace std;

void printPath(int parent[], int source){

    if (parent[source] == - 1) return;
    printPath(parent, parent[source]);
    printf("%d ", source);
}

int main(){

    int V, K;
    scanf("%d %d", &V, &K);

    vector<int> edge[V + 1], cost[V + 1];

    int a, b, c;

    for(int i = 1; i <= K; i++){
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(b);
        edge[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }

    int d[V + 1], parent[V + 1];

    bool visit[V + 1];

    for (int i = 1; i <= V; i++){
        d[i] = INT_MAX;
        parent[i] = -1;
        visit[i] = false;
    }

    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, 1));
    d[1] = 0;
    visit[1] = true;

    while (!pq.empty()){

        pair<int, int> top = pq.top();
        pq.pop();

        int  u = top.second;
        int ucost = d[u];
        visit[u] = true;

        for (int i = 0; i < edge[u].size(); i++){

            int v = edge[u][i];
            int vcost = cost[u][i] + ucost;

            if (!visit[v] && d[v] > vcost){
                parent[v] = u;
                d[v] = vcost;
                pq.push(make_pair(-1 * vcost, v));
            }
        }
    }

    if (d[V] == INT_MAX)printf("-1\n");
    else {
        printf("1 ");
        printPath(parent, V);
    }

    return 0;
}

