#include <cassert>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

constexpr int64_t INF = std::numeric_limits<int64_t>::max();

namespace graph
{
    /**
 * @brief 그래프에 꼭지점이나 노드나 간선을 더하는 함수
 * 
 * @param u 그래프의 아무 노드나 꼭지점
 * @param v 그래프의 아무 노드나 꼭지점
 */
    void addEdge(std::vector<std::vector<std::pair<int, int>>> *adj, int u, int v, int weight)
    {
        (*adj)[u - 1].push_back(std::make_pair(v - 1, weight));
        // (*adj)[v-1].push_back(std::make_pair(u-1, weight));
    }

    /**
 * @brief 이 함수는 다익스트라 알고리즘을 통해서 그래프의 시작 꼭지점과 목표 꼭지점을
 * 받아서 소스 꼭지점에서 타겟 꼭지점까지의 가장 짧은 거리를 반환한다.
 * @param adj 임력으로 들어온 그래프
 * @param s 소스 꼭지점
 * @param t 타겟 꼭지점
 * 
 * @return 타겟까지 가는 가장 짧은 거리를 반환한다.
 * 닿을 수 없는 거리는 -1을 반환한다.
*/

    int dijkstra(std::vector<std::vector<std::pair<int, int>>> *adj, int source, int t)
    {
        int n = adj->size();

        std::vector<int64_t> dist(n, INF);

        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>>>
            pq;

        pq.push(std::make_pair(0, source));

        dist[source] = 0;

        while (!pq.empty())
        {
            // second element of pair denotes the node / vertex
            int currentNode = pq.top().second;

            // first element of pair denotes the distance
            int currentDist = pq.top().first;

            pq.pop();

            for (std::pair<int, int> edge : (*adj)[currentNode])
            {
                if (currentDist + edge.second < dist[edge.first])
                {
                    dist[edge.first] = currentDist + edge.second;
                    pq.push(std::make_pair(dist[edge.first], edge.first));
                }
            }
            if (dist[t] != INF)
            {
                return dist[t];
            }
            return -1;
        }
    }
}