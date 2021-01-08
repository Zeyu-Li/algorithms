/* 
* Kruskal's Algorithm for Edged Based Graph
* Modified from: https://gist.github.com/MagallanesFito/791f736a0d21708794aafa11a0416201
*/ 
// Already in graph.cpp
// #include <vector>
// #include <utility>
#include <algorithm>
#include "../structs/graph.cpp"

class Graph_kruskal_n: public Graph {
    public:
        Graph_kruskal_n(): Graph() {};
        Graph_kruskal_n(int V, int E): Graph(V, E) {};
        // applied kruskal's algorithm to get MST 
        // (MST will be stored in a vector of 
        // pair(int weight, pair(int source, int destination))) 
        void kruskal(void);
        // minimum spanning tree
        std::vector<std::pair<int, std::pair<int, int>>> MST;
        void print_mst();
    private:
    // from https://gist.github.com/MagallanesFito/791f736a0d21708794aafa11a0416201#file-kruskal-cpp-L32
        struct Disjoint_set{
            int *parent,*rnk;
            int n;

            Disjoint_set(int n){
                this->n = n;
                parent = new int[n+1];
                rnk = new int[n+1];

                for(int i=0;i<=n;i++){
                    rnk[i] = 0;
                    parent[i] = i;
                }
            }
            ~Disjoint_set() {
                delete parent;
                delete rnk;
            }
            int Find(int u){
                if(u == parent[u]) return parent[u];
                else return Find(parent[u]);
            }
            // joins x and y groups
            void Union(int x,int y){
                if(x != y){
                    if(rnk[x] < rnk[y]){
                        rnk[y] += rnk[x];
                        parent[x] = y;
                    }
                    else{
                        rnk[x] += rnk[y];
                        parent[y] = x;
                    }
                }
            }
        };
};

void Graph_kruskal_n::kruskal() {
    // sort edges so to determine which edge to do first
    sort(edges.begin(),edges.end());

    // new instance of disjoinset
    Disjoint_set ds(V);

    // for all edges
    for (std::vector<std::pair<int,std::pair<int,int>>>::iterator it = edges.begin(); it != edges.end(); it++) {
        // source and destination
        int u = it->second.first;
        int v = it->second.second;

        // find u and v in disjoint set
        int set_u = ds.Find(u);
        int set_v = ds.Find(v);

        // if not in set, add to MST
        if (set_u != set_v) {
            int w = it->first;
            MST.push_back({w, {u, v}});
            
            ds.Union(set_u, set_v);
        }
    }
}

void Graph_kruskal_n::print_mst(void) {
    std::vector<std::pair<int, std::pair<int, int>>>::iterator it;
    for(it = MST.begin();it!=MST.end();it++){
        std::cout << it->second.first << " - " << it->second.second << " (" << it->first << ")" << std::endl;
    }
}
