#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc;
    scanf("%d", &tc);

    while(tc--){

        int V, K;
        scanf("%d %d", &V, &K);

        vector<int> edge[V + 1], cost[V + 1];

        int a, b, c;

        for(int i = 1; i <= K; i++){
            scanf("%d %d %d", &a, &b, &c);
            edge[a].push_back(b);
            cost[a].push_back(c);
        }

        int d[V + 1];
        for (int i = 1; i <= V; i++)d[i] = INT_MAX;

        priority_queue<pair<int, int> > pq;

        int A, B;
        scanf("%d %d", &A, &B);

        pq.push(make_pair(0, A));
        d[A] = 0;

        while (!pq.empty()){

            pair<int, int> top = pq.top();
            pq.pop();

            int  u = top.second;
            int ucost = d[u];

            for (int i = 0; i < edge[u].size(); i++){

                int v = edge[u][i];
                int vcost = cost[u][i] + ucost;

                if (d[v] > vcost){
                    d[v] = vcost;
                    pq.push(make_pair(vcost, v));
                }
            }
        }

        if (d[B] == INT_MAX)printf("NO\n");
        else printf("%d\n", d[B]);
    }
    return 0;
}
