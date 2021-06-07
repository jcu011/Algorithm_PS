#include<bits/stdc++.h>
#define MAX 2001
using namespace std;

int N,M,K;
vector<int> adj[MAX]{};
int A[MAX]{};
int B[MAX]{};
bool vi[MAX]{};

bool dfs(int cur){
    if(vi[cur]) return false;
    vi[cur] = true;
    for(auto next : adj[cur]){
        if(B[next]==-1 || dfs(B[next])){
            A[cur] = next;
            B[next] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    int z,t;
    for(int i=1; i<=N; i++) {
        cin>>z;
        while(z--){
            cin>>t;
            adj[i].push_back(t);
            adj[i+N].push_back(t);
        }
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    int ans1 = 0;
    for(int i=1; i<=N; i++){
        memset(vi, 0, sizeof(vi));
        if(dfs(i)) ans1++;
    }
    
    int ans2 = 0;
    for(int i=N+1; i<=N+N; i++){
        memset(vi, 0, sizeof(vi));
        if(dfs(i)) ans2++;
        if(ans2==K) break;
    }

    cout<<ans1+ans2;
}