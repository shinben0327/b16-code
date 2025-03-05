#include "shortest_paths_sparse.hpp"
#include <priority_queue.hpp>

#include <cmath>

inline bool relax(const SparseGraph &graph, std::vector<hop_t> &DP, int r,
                  int v)
{
    auto Duv = DP[v].weight;
    float Duv_via_r = DP[r].weight + inf; // Initialize with infinity

    // Search for the edge from r to v
    for (const auto &edge : graph[r]) {
        if (edge.vertex == v) {
            Duv_via_r = DP[r].weight + edge.weight;
            break;
        }
    }

    if (Duv_via_r < Duv) {
        DP[v] = {Duv_via_r, r};
        return true;
    }
    return false;
}

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});

    // WRITE YOUR CODE HERE
    DP[source].weight = 0;

    for (int iter = 0; iter < V - 1; ++iter) {
        has_negative_cycle = false;
        for (int r = 0; r < V; ++r) {
            for (int v = 0; v < V; ++v) {
                has_negative_cycle |= relax(graph, DP, r, v);
            }
        }
    }

    return DP;
}

struct triplet_t {
    float d;
    int r;
    int v;
};

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});

    // WRITE YOUR CODE HERE

    return DP;
}