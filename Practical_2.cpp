#include <bits/stdc++.h>
using namespace std;

struct Edge {
   int source, destination, weight;
};

class Demo{
    int V,E;
    vector<Edge> edges;
    public:
    void input(){
        cout<<"Enter number of vertices"<<endl;
        cin>>V;
        cout<<"Enter number of edges"<<endl;
        cin>>E;
        cout<<"Enter edges in the format sorce destination weight"<<endl;
        for(int i=0;i<E;i++){
            Edge edge;
            cout<<"Enter edge "<<i+1<<endl;
            cin>>edge.source>>edge.destination>>edge.weight;
            edges.push_back(edge);
        }
    }
    void bellman_ford(){
        cout<<"Enter source vertex"<<endl;
        int source;
        cin>>source;
        vector<int> output(V,INT_MAX);
        output[source]=0;
        for(int i=1;i<=V-1;i++){
            for(auto edge:edges){
                int u=edge.source;
                int v=edge.destination;
                int weight=edge.weight;
                if(output[u]!=INT_MAX && output[u]+weight<output[v]){
                    output[v]=output[u]+weight;
                }
            }
        }
        for(auto edge:edges){
            int u=edge.source;
            int v=edge.destination;
            int weight=edge.weight;
            if(output[u]!=INT_MAX && output[u]+weight<output[v]){
                cout<<"Graph contains negative weight cycle"<<endl;
                return;
            }
        }
        cout<<"Vertex Distance from Source"<<endl;
        for(int i=0;i<V;i++){
            if(output[i]==INT_MAX){
                cout<<i<<"\t\t"<<"INF"<<endl;
            }
            else{
                cout<<i<<"\t\t"<<output[i]<<endl;
            }
        }

    }
};





int main(){
    Demo bf;
    bf.input();
    bf.bellman_ford();

    return 0;
}

/*
 Sample Input and Output:
    Enter number of vertices
    5
    Enter number of edges
    5
    Enter edges in the format src dest weight
    Enter edge 1
    1 3 2
    Enter edge 2
    4 3 -1
    Enter edge 3
    2 4 1
    Enter edge 4
    1 2 1
    Enter edge 5
    0 1 5
    Enter source vertex
    0
    Vertex Distance from Source
    0               0
    1               5
    2               6
    3               6
    4               7
*/
