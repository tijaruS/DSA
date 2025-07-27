#include<bits/stdc++.h>


int main(){
int vertices, edges;
std::cin>>vertices>>edges;

std::vector<std::pair<int,int>> arr[vertices];
for(int i=0;i<edges;i++){
    int u,v,w;
    std::cin>>u>>v;
    arr[u].push_back({v,w});
    arr[v].push_back({u,w});
}




    return 0;
}
