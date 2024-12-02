#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* next[2]; // Binary trie: next[0] for 0, next[1] for 1
    TrieNode() {
        next[0] = next[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; i--) { // Assuming 32-bit integers
            int bit = (num >> i) & 1;
            if (!cur->next[bit]) {
                cur->next[bit] = new TrieNode();
            }
            cur = cur->next[bit];
        }
    }

    int findMaxXOR(int num) {
        TrieNode* cur = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit; // Try to go the opposite direction for max XOR
            if (cur->next[opposite]) {
                maxXOR |= (1 << i); // Include this bit in the result
                cur = cur->next[opposite];
            } else {
                cur = cur->next[bit];
            }
        }
        return maxXOR;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Trie trie;
    int maxXOR = 0, prefixXOR = 0;

    // Insert 0 to handle cases where a subarray itself gives the max XOR
    trie.insert(0);

    for (int i = 0; i < n; i++) {
        prefixXOR ^= arr[i];             // Compute the prefix XOR
        maxXOR = max(maxXOR, trie.findMaxXOR(prefixXOR)); // Find max XOR ending at this index
        trie.insert(prefixXOR);          // Insert the current prefix XOR into the trie
    }

    cout << maxXOR << endl;

    }
    
    return 0;
}
