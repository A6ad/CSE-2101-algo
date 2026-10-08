#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];
// find with path compression — O(log N) amortized (near O(1))
int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;   // path compression
    return leader;
}
// union by size
void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (leader1 == leader2)   // already same set
        return;
    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}
int main()
{
    memset(par, -1, sizeof(par));
    // group_size initialized to 1 for every node
    for (int i = 0; i < 1005; i++) group_size[i] = 1;
    dsu_union(1, 2);
    dsu_union(2, 0);
    dsu_union(3, 1);
    for (int i = 0; i < 6; i++)
        cout << i << " -> " << par[i] << endl;
    return 0;
}