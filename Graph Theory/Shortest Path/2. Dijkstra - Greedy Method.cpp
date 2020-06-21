#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, e, u, v, c;
    cin >> n >> e;
    vector<int> edge[n], cost[n];
    for (int i = 0; i < e; i++){
        cin >> u >> v >> c;
        edge[u].push_back(v);
        cost[u].push_back(c);
    }
    int dist[n + 1];
    for (int i = 0; i <= n; i++)dist[i] = INT_MAX;

    priority_queue<pair<int, int> > pq;

    int source, destination;
    cin >> source >> destination;
    pq.push(make_pair(0, source));
    dist[source] = 0;

    pair<int, int> top;

    while(!pq.empty()){
        top = pq.top();
        cout << "node = " << top.second  << " weight = " << top.first << endl;
        pq.pop();
        printf("\nnow processing node = %d\nReachable nodes are:\n", top.second);
        int ucost = dist[top.second];
        for (int i = 0; i < edge[top.second].size(); i++){
            int vcity = edge[top.second][i], vcost = cost[top.second][i] + ucost;
            printf("node = %d cost = %d\n", vcity, vcost);
            if (dist[vcity] > vcost){
                dist[vcity] = vcost;
                pq.push(make_pair(vcost, vcity));
            }
        }
    }
    int ans = dist[destination];
    for (int i = 0; i < n; i++){
        printf("shortest path from %d to %d = %d\n", source, i, dist[i]);
    }
    return 0;
}
