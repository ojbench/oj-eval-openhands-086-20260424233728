#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int left;
    int right;
    TreeNode() : left(-1), right(-1) {}
};

vector<TreeNode> tree;
vector<int> inorder_result;

void inorder(int node, int depth) {
    if (node == -1) return;
    
    // Traverse left subtree first
    inorder(tree[node].left, depth + 1);
    
    // Visit current node
    inorder_result.push_back(node);
    
    // Traverse right subtree
    inorder(tree[node].right, depth + 1);
}

void swap_subtrees(int node, int depth, int k) {
    if (node == -1) return;
    
    // If current node depth is a multiple of k, swap its children
    if (depth % k == 0) {
        swap(tree[node].left, tree[node].right);
    }
    
    // Recursively process left and right subtrees
    swap_subtrees(tree[node].left, depth + 1, k);
    swap_subtrees(tree[node].right, depth + 1, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Resize tree to accommodate nodes 1 to n
    tree.resize(n + 1);
    
    // Read tree structure
    for (int i = 1; i <= n; i++) {
        cin >> tree[i].left >> tree[i].right;
    }
    
    int t;
    cin >> t;
    
    // Process each query
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        
        // Perform swap operations for nodes at depths that are multiples of k
        swap_subtrees(1, 1, k);  // Start from root (node 1) at depth 1
        
        // Generate inorder traversal
        inorder_result.clear();
        inorder(1, 1);
        
        // Output result
        for (size_t j = 0; j < inorder_result.size(); j++) {
            if (j > 0) cout << " ";
            cout << inorder_result[j];
        }
        cout << "\n";
    }
    
    return 0;
}