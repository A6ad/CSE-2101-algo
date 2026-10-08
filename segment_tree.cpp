#include <bits/stdc++.h>
using namespace std;
vector<int> tree;

void build(int node, int l, int r, vector<int> &arr)
{
    if (l == r)
    {
        tree[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;

    build(2 * node + 1, l, mid, arr);
    build(2 * node + 2, mid + 1, r, arr);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}
int query(int node, int l, int r, int start, int end)
{

    if (r < start || l > end)
        return 0;

    if (l >= start && r <= end)
    {
        return tree[node];
    }

    int mid = (l + r) / 2;
    int leftsum = query(2 * node + 1, l, mid, start, end);
    int rightsum = query(2 * node + 2, mid + 1, r, start, end);

    return leftsum + rightsum;
}
void update(int node, int l, int r, int index, int value)
{
    if (l == r)
    {
        tree[node] = value;
        return;
    }
    int mid = (l + r) / 2;
    if (index <= mid)
        update(2 * node + 1, l, mid, index, value);
    else
        update(2 * node + 2, mid + 1, r, index, value);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}
int main()
{
    vector<int> arr = {2, 1, 5, 3, 4, 7, 6, 8};
    int n = arr.size();
    tree.resize(4 * n);
    build(0, 0, n - 1, arr);
    cout << "Range Sum (0 to 5): " << query(0, 0, n - 1, 0, 5) << endl;

    update(0, 0, n - 1, 2, 10);
    cout << "Range Sum (0 to 5) after update: " << query(0, 0, n - 1, 0, 5) << endl;
}