#include <bits/stdc++.h>

using namespace std;

int visitAllNeighbors(int v, vector< queue<int> > &connectivity, bool *visited){
    long cost = 0;
    if(visited[v] == 1)
        return 0;
    visited[v] = 1;
    while(connectivity[v].empty() == 0){
        int u = connectivity[v].front();
        connectivity[v].pop();
        //printf("visited: %d %d\n", u, visited[u]);
        if(visited[u]==0)
            cost += 1+visitAllNeighbors(u, connectivity, visited);
    }
    return cost;
}

long long roadsAndLibraries(int n, int c_lib, int c_road, vector < vector<int> > &cities) {
    // Complete this function
    
    if(c_lib < c_road)
        return (long long)c_lib*(long long)n;
    
    vector< queue<int> > connectivity(n+1, queue<int>());
    bool visited[n+1];
    
    for(int i=n; i>0; i--){
        visited[i] = 0;
    }
    
    for(int i=cities.size()-1; i>=0; i--){
        connectivity[cities[i][0]].push(cities[i][1]);
        connectivity[cities[i][1]].push(cities[i][0]);
    }
    int libcount = 0, roadcount = 0;
    for(int i=n; i>=1; i--){
        //printf("i: %d %d\n", i, visited[i]);
        if(visited[i] == 0){
            libcount ++;
            roadcount += visitAllNeighbors(i, connectivity, visited);
        }
    }
    return (long long)libcount * (long long)c_lib + (long long)roadcount * (long long)c_road;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        int c_lib;
        int c_road;
        cin >> n >> m >> c_lib >> c_road;
        vector< vector<int> > cities(m,vector<int>(2));
        for(int cities_i = 0;cities_i < m;cities_i++){
           for(int cities_j = 0;cities_j < 2;cities_j++){
              cin >> cities[cities_i][cities_j];
           }
        }
        
        long long result = roadsAndLibraries(n, c_lib, c_road, cities);
        cout << result << endl;
    }
    return 0;
}
