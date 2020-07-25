#include <algorithm>
#include <vector>
using namespace std;

// QUICK SORT

// Partition function for Quick Sort
// This function takes the last element as pivot, places the pivot element at
// its correct position in sorted array, and places all smaller (smaller than
// pivot) to left of pivot and all greater elements to right of pivot.
int partition(vector<int>& a, int low, int high) {
    // 'i' marks the boundary for elements less than the pivot.
    // All elements before index 'i' are less than the pivot.
    int i = low;
    int pivot = a[high];  // Choose the last element as the pivot
    for (int j = low; j < high; j++) {
        // If current element is less than the pivot
        if (a[j] < pivot) {
            // Swap a[j] with a[i] so that a[i] is less than pivot
            swap(a[i], a[j]);
            // Move the boundary of elements less than pivot forward
            i++;
        }
    }
    // Place the pivot after the last element smaller than it
    swap(a[i], a[high]);
    // Now, a[i] is at its correct sorted position
    return i;
}

// ----------------------------------------------------------------------------

// LAZY SEGMENT TREE

// Segment Tree with Lazy Propagation for range maximum queries and range
// updates
class SegTree {
   public:
    int size;
    int neutral = 0;   // Neutral value for max operation
    vector<int> tree;  // Segment tree array
    vector<int> lazy;  // Lazy propagation array

    // Constructor: initializes segment tree and lazy arrays
    SegTree(int n) {
        size = n;
        tree = vector<int>(4 * n, neutral);
        lazy = vector<int>(4 * n, -1);  // -1 means no pending update
    }

    // Pushes the pending update at 'curr' to its children
    void push(int curr, int currL, int currR) {
        if (lazy[curr] == -1) return;  // No pending update
        // Apply the pending update to the current node
        tree[curr] = (tree[curr], lazy[curr]);
        if (currL != currR) {
            // Propagate the update to the children
            lazy[curr * 2] = max(lazy[curr * 2], lazy[curr]);
            lazy[curr * 2 + 1] = max(lazy[curr * 2 + 1], lazy[curr]);
        }
        // Clear the lazy value for the current node
        lazy[curr] = -1;
    }

    // Range maximum query with lazy propagation
    int query(int ql, int qr, int curr, int currL, int currR) {
        push(curr, currL, currR);  // Ensure any pending updates are applied
        if (currL > qr || currR < ql) return neutral;       // No overlap
        if (currL >= ql && currR <= qr) return tree[curr];  // Total overlap
        int m = (currL + currR) / 2;
        int left = query(ql, qr, curr * 2, currL, m);
        int right = query(ql, qr, curr * 2 + 1, m + 1, currR);
        return max(left, right);  // Combine results
    }
    // Public query function
    int query(int ql, int qr) { return query(ql, qr, 1, 0, size - 1); }

    // Range update with lazy propagation
    void update(int ql, int qr, int curr, int currL, int currR, int val) {
        push(curr, currL, currR);  // Ensure any pending updates are applied
        if (currL > qr || currR < ql) return;  // No overlap
        if (currL >= ql && currR <= qr) {
            // Apply the update and mark children for lazy update
            lazy[curr] = val;
            push(curr, currL, currR);
            return;
        }
        int m = (currL + currR) / 2;
        update(ql, qr, curr * 2, currL, m, val);
        update(ql, qr, curr * 2 + 1, m + 1, currR, val);
        // Update the current node based on children
        tree[curr] = max(tree[curr * 2], tree[curr * 2 + 1]);
    }
    // Public update function
    void update(int ql, int qr, int val) {
        return update(ql, qr, 1, 0, size - 1, val);
    }
};

// ----------------------------------------------------------------------------

// COMBINATORICS

class Solution {
   public:
    const int M = 1e9 + 7;  // Modulo value for calculations
    const int N = 1005;     // Maximum value for n in nCr
    vector<int> fact;       // fact[i] stores i! % M (factorial modulo M)
    vector<int> rfact;      // rfact[i] stores modular inverse of i! % M

    // Constructor: precomputes factorials and their modular inverses
    Solution() {
        fact.resize(N, 0);
        rfact.resize(N, 0);
        calculate();
    }

    // Computes a^n % M using binary exponentiation
    int power(int a, int n) {
        if (n == 0) return 1;
        if (n % 2 == 0) {
            int temp = power(a, n / 2);
            return (1ll * temp * temp) % M;
        }
        return (1ll * a * power(a, n - 1)) % M;
    }

    // Precomputes factorials and their modular inverses up to N
    void calculate() {
        fact[0] = 1;
        rfact[0] = 1;
        for (int i = 1; i < N; i++) {
            fact[i] = (1ll * fact[i - 1] * i) % M;
            // rfact[i] = (i!)^{-1} % M using Fermat's Little Theorem
            // power(i, M - 2) is the modular inverse of i % M
            // Fermat's Little Theorem: a^(p-1) ≡ 1 (mod p) for prime p
            // a^(p-2) ≡ a^{-1} (mod p)
            // so, power(i, M - 2) is the modular inverse of i % M
            // rfact[i] = (i!)^{-1} % M using Fermat's Little Theorem
            rfact[i] = (1ll * rfact[i - 1] * power(i, M - 2)) % M;
        }
    }

    // Returns nCr % M using precomputed factorials and inverses
    int combination(int n, int r) {
        long long temp = fact[n];
        temp *= rfact[n - r];
        temp %= M;
        temp *= rfact[r];
        temp %= M;
        return temp;
    }
};

// ----------------------------------------------------------------------------

// LPS

// Computes the Longest Prefix Suffix (LPS) array for the given pattern string.
// The LPS array is used in the KMP (Knuth-Morris-Pratt) string matching
// algorithm. lps[i] stores the length of the longest proper prefix of
// pattern[0..i] which is also a suffix.
vector<int> getLps(string pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);  // Initialize LPS array with zeros

    int j = 0;  // Length of the previous longest prefix suffix
    for (int i = 1; i < n; i++) {
        // If there is a mismatch, fall back to the previous possible prefix
        // length
        while (j > 0 && pattern[i] != pattern[j]) {
            // int prevIndex = j - 1;
            // int newIndex = lps[prevIndex] - 1;
            // j = newIndex + 1; // Update j to the next best candidate
            j = lps[j - 1];
        }
        // If characters match, extend the current prefix length
        if (pattern[i] == pattern[j]) {
            j++;
        }
        lps[i] = j;  // Set the LPS value for position i
    }
    return lps;  // Return the computed LPS array
}

// ----------------------------------------------------------------------------

// Computes the Z-array (Z-function) for the given string s.
// Z[i] is the length of the longest substring starting at s[i] which is also a
// prefix of s. Useful for pattern matching and string analysis.
vector<int> calcZ(string s) {
    int n = s.size();
    vector<int> Z(n, 0);  // Initialize Z-array with zeros

    // [x, y] is the interval with maximum y such that s[x..y] is a prefix
    // substring
    for (int i = 1, x = 0, y = 0; i < n; i++) {
        // If i is within the current [x, y] interval, use previously computed
        // values to initialize Z[i]
        if (i <= y) {
            // Use the value from the corresponding prefix
            // y - i is the distance from i to the end of the current prefix
            // Z[i - x] is the value from the corresponding prefix
            // min(y - i, Z[i - x]) is the minimum of the two values
            Z[i] = min(y - i, Z[i - x]);
        }

        // Try to extend Z[i] as much as possible by direct comparison
        while (i + Z[i] < n && s[i + Z[i]] == s[Z[i]]) {
            // Increment Z[i] if characters match
            Z[i]++;
        }

        // If the substring [i, i + Z[i] - 1] extends past y, update [x, y]
        if (i + Z[i] - 1 > y) {
            x = i;
            y = i + Z[i] - 1;
        }
    }
    return Z;  // Return the computed Z-array
}

// ----------------------------------------------------------------------------

// BINARY LIFTING

// TreeAncestor supports efficient queries for the k-th ancestor of any node in
// a rooted tree using the binary lifting technique (precomputing 2^j-th
// ancestors for each node).
class TreeAncestor {
    // par[i][j] stores the 2^j-th ancestor of node i, or -1 if it doesn't
    // exist.
    vector<vector<int>> par;

   public:
    // Constructor: Preprocesses the parent array to fill the binary lifting
    // table. n: number of nodes in the tree parent: parent[i] is the parent of
    // node i, or -1 if i is the root
    TreeAncestor(int n, vector<int>& parent) {
        par = vector<vector<int>>(n, vector<int>(20));
        // The 2^0-th ancestor (immediate parent) for each node
        for (int i = 0; i < n; i++) par[i][0] = parent[i];
        // Compute 2^j-th ancestors for j = 1 to 19
        for (int j = 1; j < 20; j++) {
            for (int i = 0; i < n; i++) {
                // If the 2^{j-1}-th ancestor does not exist, neither does the
                // 2^j-th
                if (par[i][j - 1] == -1) {
                    par[i][j] = -1;
                } else {
                    // The 2^j-th ancestor is the 2^{j-1}-th ancestor of the
                    // 2^{j-1}-th ancestor
                    par[i][j] = par[par[i][j - 1]][j - 1];
                }
            }
        }
    }

    // Returns the k-th ancestor of node, or -1 if it does not exist.
    // Uses binary lifting: for each bit in k, move up by the corresponding 2^i
    // steps.
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if ((1 << i) & k) {
                node = par[node][i];
                if (node == -1) return -1;  // No such ancestor exists
            }
        }
        return node;
    }
};

// ----------------------------------------------------------------------------