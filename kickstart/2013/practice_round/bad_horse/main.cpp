#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>



struct Node
{
    std::string name;
    std::unordered_set<std::string> enemies;
    bool visited;
};

typedef std::unordered_map<std::string, std::unordered_set<std::string> > Graph;
typedef std::unordered_map<std::string, int> Group;

inline int flip(int next) {
    return next == 0 ? 1 : 0;
}

bool mark(const std::string& name, Graph& graph, Group& groups, int next) {
    if (groups[name] == -1) {
        // not visited yet
        // try setting it as next
        groups[name] = next;
        // recursively mark all enemies as next
        for (const auto& enemy : graph[name]) {
            if (!mark(enemy, graph, groups, flip(next))) {
                groups[name] = -1;
                return false;
            }
        }
        return true;
    }
    if (groups[name] != next) {
        return false;
    }
    return true;

} 

int main()
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        int M;

        std::cin >> M;
        Graph adj;
        Group group;
        std::string a, b;

        for (int j = 0; j < M; j++)
        {
            std::cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
            group[a] = -1;
            group[b] = -1;
        }
        
        for (auto& it : adj) {
            if (!mark(it.first, adj, group, 0) && !mark(it.first, adj, group, 1)) {
                std::cout << "Case #" << i + 1 << ": No" << std::endl;
                goto next_case;
            }
        }
        std::cout << "Case #" << i + 1 << ": Yes" << std::endl;
        next_case:
        continue;
    }
    return 0;
}
