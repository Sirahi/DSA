#pragma once

#include <vector>

struct GraphEdge;

using WeightedAdjacencyList = std::vector<std::vector<GraphEdge>>;

struct GraphEdge
{
    int to;
    int weight;
};

class DijkstraList
{
public:
    static std::vector<int> shortestPath(const int source, const int sink, const WeightedAdjacencyList& array)
    {
        auto seen = std::vector<bool>(array.size(), false);
        auto prev = std::vector<int>(array.size(), -1);
        auto dists = std::vector<int>(array.size(), std::numeric_limits<int>::max());

        dists[source] = 0;

        while (hasUnvisited(seen, dists))
        {
            const int lo = getLowestUnvisited(seen, dists);

            seen[lo] = true;

            const std::vector<GraphEdge>& adj = array[lo];

            for (const GraphEdge& edge : adj)
            {
                if (seen[edge.to])
                {
                    continue;
                }

                const int dist = dists[lo] + edge.weight;

                if (dist < dists[edge.to])
                {
                    prev[edge.to] = lo;
                    dists[edge.to] = dist;
                }
            }
        }

        std::vector<int> out = {};

        int curr = sink;

        while (prev[curr] != -1)
        {
            out.push_back(curr);
            curr = prev[curr];
        }

        out.push_back(source);
        std::reverse(out.begin(), out.end());

        return out;
    }

private:
    static bool hasUnvisited(const std::vector<bool>& seen, const std::vector<int>& dists)
    {
        for (int i = 0; i < seen.size(); i++)
        {
            if (!seen[i] && dists[i] < std::numeric_limits<int>::max())
            {
                return true;
            }
        }

        return false;
    }

    static int getLowestUnvisited(const std::vector<bool>& seen, const std::vector<int>& dists)
    {
        int idx = -1;
        int lowestDist = std::numeric_limits<int>::max();

        for (int i = 0; i < seen.size(); i++)
        {
            if (!seen[i] && dists[i] < lowestDist)
            {
                lowestDist = dists[i];
                idx = i;
            }
        }

        return idx;
    }
};
