#include "directed-graph.cpp"
#include <vector>
#include <iostream>

using namespace std;

/**
 * You are given a list of projects and a list of dependencies
 * Projects : a, b, c, d...
 * Dependencies : (x, y) where y is dependent on x
 * All project dependencies must be built before project
 * Return a valid build order, or throw an error
 */

/**
 * Performs a dfs on the graph
 *
 * @param DirectedGraph& dg
 * @param int curr
 * @param vector<bool>& visited
 * @param vector<int>& res
 * @return void
 */
void dfs(DirectedGraph& dg, int curr, vector<bool>& visited, vector<int>& res)
{
    if (visited[curr]) return;

    visited[curr] = true;

    for (int v : dg.getAdjList(curr))
    {
        dfs(dg, v, visited, res);
    }

    res.push_back(curr);
}

/**
 * Returns a topological sort of the directed graph
 *
 * @param DirectedGraph& dg
 * @param int n
 * @param int start
 * @return vector<int>
 */
vector<int> topologicalSort(DirectedGraph& dg, int n, int start)
{
    // Start with vertex 0
    vector<bool> visited(n, false);

    vector<int> res;

    for (int i=0; i<n; i++)
    {
        if (visited[i]) continue;

        dfs(dg, i, visited, res);
    }

    return res;
}

int main()
{
    // (a, b, c, d, e, f)
    DirectedGraph dg = DirectedGraph(6);

    // (a, b) where a is dependent on b
    // b must be compiled before a
    // a ---> b
    vector<vector<int>> edges = {
        {3, 0},
        {1, 5},
        {3, 1},
        {0, 5},
        {2, 3},
    };

    dg.addEdges(edges);

    vector<int> topoSort = topologicalSort(dg, 6, 0);

    for (int elem : topoSort) cout << elem << " ";

    cout << endl;
}
