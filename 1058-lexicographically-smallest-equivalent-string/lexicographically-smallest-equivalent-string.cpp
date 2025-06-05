#include <vector>
#include <string>
using namespace std;

class Solution {
    // Inner class to implement the UnionFind data structure
    class UnionFind {
    private:
        vector<int> parent; // Array to store the parent of each element

    public:
        // Constructor: Initializes the UnionFind with 'n' elements
        UnionFind(int n) {
            parent.resize(n);
            // Initially, each element is its own parent (separate sets)
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        // Find: Finds the root (representative) of the set that 'x' belongs to
        int find(int x) {
            // Path compression: Update 'x's parent to point directly to the root
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        // Union: Merges the sets that 'x' and 'y' belong to
        void unionSets(int x, int y) {
            int rootX = find(x); // Find the root of 'x'
            int rootY = find(y); // Find the root of 'y'
            // Attach the larger root to the smaller root to keep the smallest char as representative
            if (rootX != rootY) {
                if (rootX < rootY) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootX] = rootY;
                }
            }
        }
    };

public:
    // Main function to find the smallest equivalent string
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26); // Create a UnionFind for 26 lowercase letters

        // Build the equivalency map based on s1 and s2
        for (int i = 0; i < s1.size(); i++) {
            char c1 = s1[i]; // Get the character from s1 at index i
            char c2 = s2[i]; // Get the character from s2 at index i
            uf.unionSets(c1 - 'a', c2 - 'a'); // Union the sets of c1 and c2
        }

        // Transform baseStr using the equivalency map
        string result; // Use string for storing the result
        for (char c : baseStr) {
            // Find the representative of the set that 'c' belongs to
            result += (char)(uf.find(c - 'a') + 'a'); // Append the smallest equivalent character
        }

        return result; // Return the result string
    }
};
