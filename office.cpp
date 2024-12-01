#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    unordered_map<int, vector<int>> adjacencyList;

    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        adjacencyList[node1].push_back(node2);
        adjacencyList[node2].push_back(node1);
    }

    int targetPopulation;
    cin >> targetPopulation;

    vector<int> currentState(numNodes, 1);
    int currentPopulation = numNodes;
    int days = 1;

    while (currentPopulation < targetPopulation) {
        vector<int> nextState(numNodes, 0);

        for (int node = 0; node < numNodes; node++) {
            int activeNeighbors = 0;

            for (int neighbor : adjacencyList[node]) {
                if (currentState[neighbor] == 1) {
                    activeNeighbors++;
                }
            }

            if (currentState[node] == 1 && activeNeighbors == 3) {
                nextState[node] = 1;
            } else if (currentState[node] == 0 && activeNeighbors < 3) {
                nextState[node] = 1;
            }
        }

        currentPopulation += count(nextState.begin(), nextState.end(), 1);
        currentState = nextState;
        days++;
    }

    cout << days;
    return 0;
}