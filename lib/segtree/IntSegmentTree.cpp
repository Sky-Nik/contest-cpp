#include <algorithm>
#include <vector>

struct SegmentTreeNode {
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    int from, to;
    int value;

    SegmentTreeNode() { }

    SegmentTreeNode(int from, int to, int value) :
        left(nullptr), right(nullptr), from(from), to(to), value(value) {}
}

typedef SegmentTreeNode* SegmentTree;

int GetValue(const SegmentTreeNode& node) {
    if (node) {
        return node.value;
    } else {
        return 0;  // changable
    }
}

SegmentTree BuildSegmentTree(const std::vector<int>& array, int from, int to) {  // [from, to)
    int middle = (from + to) >> 1;

    auto root = new SegmentTreeNode(from, to, 0);

    if (from + 1 != to) {
        root->left = BuildSegmentTree(array, from, middle);
        root->right = BuildSegmentTree(array, middle, to);
    }

    root->value = GetValue(root->left) + GetValue(root->right);  // changable

    return root;
}

int GetValue(const SegmentTree& tree, int from, int to) {  // [from, to)
    if (from >= to) {
        return 0;  // changable
    }

    if (from == tree->from && to == tree->to) {
        return tree->value;
    }

    return GetValue(tree->left, from, std::min(to, tree->left->to)) +
        GetValue(tree->right, std::max(from, tree->right->from), to);  // changable
}

void UpdateValue(SegmentTree& tree, int position, int new_value) {
    if (tree->from + 1 == tree->to) {
        tree->value = new_value;
    } else if (position < tree->left->to) {
        UpdateValue(tree->left, position, new_value);
    } else {
        UpdateValue(tree->right, position, new_value);
    }

    tree->value = GetValue(tree->left) + GetValue(tree->right);  // changable
}
