#include <algorithm>
#include <vector>

template<typename value_t>
struct SegmentTreeNode {
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    int from, to;
    value_t value;

    SegmentTreeNode() { }

    SegmentTreeNode(int from, int to, value_t value) :
        left(nullptr), right(nullptr), from(from), to(to), value(value) {}
}

typedef SegmentTreeNode* SegmentTree;

template<typename value_t>
value_t GetValue(const SegmentTreeNode& node) {
    if (node) {
        return node.value;
    } else {
        return 0;  // changable
    }
}

template<typename value_t>
SegmentTree BuildSegmentTree(const std::vector<value_t>& array, int from, int to) {  // [from, to)
    // if (from == to) {
    //     return nullptr;
    // }

    int middle = (from + to) >> 1;

    auto root = new SegmentTreeNode(from, to, 0);

    if (from + 1 != to) {
        root->left = BuildSegmentTree(array, from, middle);
        root->right = BuildSegmentTree(array, middle, to);
    }

    root->value = GetValue(root->left) + GetValue(root->right);  // changable

    return root;
}

template<typename value_t>
value_t GetValue(const SegmentTree& tree, int from, int to) {  // [from, to)
    if (from >= to) {
        return 0;  // changable
    }

    if (from == tree->from && to == tree->to) {
        return tree->value;
    }

    return GetValue(tree->left, from, std::min(to, tree->left->to)) +
        GetValue(tree->right, std::max(from, tree->right->from), to);  // changable
}

template<typename value_t>
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
