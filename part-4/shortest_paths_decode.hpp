#ifndef __shortest_paths_decode__
#define __shortest_paths_decode__

#include "graph.hpp"
#include <algorithm>
#include <vector>

inline std::vector<int> decode(const std::vector<hop_t> &DP, int v)
{
    std::vector<int> path;

    if (DP[v].vertex != -1)
    {
        path.push_back(DP[v].vertex);
    }

    return path;
}

#endif // __shortest_paths_decode__
