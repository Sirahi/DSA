#pragma once
#include <vector>
#include <queue>

using WeightedAdjacencyMatrix = std::vector<std::vector<int>>;

class BFSGraphMatrix
{
public:
    static std::vector<int> bfs(const WeightedAdjacencyMatrix& graph, const int source, const int needle)
    {
        auto seen = std::vector<bool>(graph.size(), false);
        auto prev = std::vector<int>(graph.size(), -1);

        std::queue<int> Q;
        Q.push(source);

        while (!Q.empty())
        {
            const int curr = Q.front();
            Q.pop();

            if (curr == needle)
            {
                break;
            }

            const std::vector<int>& adjacency = graph[curr];

            for (int i = 0; i < graph.size(); i++)
            {
                if (adjacency[i] == 0)
                {
                    continue;
                }

                if (seen[i])
                {
                    continue;
                }

                seen[i] = true;
                prev[i] = curr;
                Q.push(i);
            }
        }

        if (prev[needle] == -1)
        {
            return {};
        }

        int curr = needle;
        std::vector<int> out = {};


        while (prev[curr] != -1)
        {
            out.push_back(curr);
            curr = prev[curr];
        }

        std::reverse(out.begin(), out.end());
        out.insert(out.begin(), source);

        return out;
    }
};
