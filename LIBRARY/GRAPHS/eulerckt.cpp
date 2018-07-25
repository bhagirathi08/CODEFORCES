//
// Created by bhagirathi on 4/3/2018.
//

#define MAX 200005
multiset<int> edge[MAX];
vector<int> ans;

void EulerCircuit(int u){
    while(!edge[u].empty()){
        int v=*edge[u].begin();
        edge[u].erase(v);
        edge[v].erase(u);
        EulerCircuit(v);
    }
    ans.push_back(u);
}

