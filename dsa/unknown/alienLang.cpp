// alienLang.cpp : Nithin
// desc :
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> inDegree;

    // Build the graph and in-degree map
    for (const string& word : words) {
        for (char c : word) {
            if (graph.find(c) == graph.end()) {
                graph[c] = unordered_set<char>();
                inDegree[c] = 0;
            }
        }
    }

    // Compare adjacent words to determine the relationships
    for (int i = 1; i < words.size(); ++i) {
        const string& prev = words[i - 1];
        const string& curr = words[i];
        int len = min(prev.length(), curr.length());

        for (int j = 0; j < len; ++j) {
            if (prev[j] != curr[j]) {
                graph[prev[j]].insert(curr[j]);
                inDegree[curr[j]]++;
                break;
            }
        }
    }

    // Perform topological sort
    queue<char> q;
    for (const auto& entry : inDegree) {
        if (entry.second == 0) {
            q.push(entry.first);
        }
    }

    string result;
    while (!q.empty()) {
        char current = q.front();
        q.pop();
        result += current;

        for (char neighbor : graph[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check for a cycle in the graph
    if (result.length() != inDegree.size()) {
        return "";
    }

    return result;
}

int main() {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    string order = alienOrder(words);

    if (!order.empty()) {
        cout << "Order of letters: " << order << endl;
    } else {
        cout << "No valid order found." << endl;
    }

    return 0;
}
