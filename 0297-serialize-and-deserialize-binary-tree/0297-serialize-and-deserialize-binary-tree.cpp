
class Codec {
    ostringstream oss;
    int i = 0;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) return " x";

        string left = serialize(root->left);

        string right = serialize(root->right);

        return " " + to_string(root->val) + left + right;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream iss(data);
        return helper(iss);
    }

    TreeNode *helper(istringstream& iss) {
        string el;
        
        iss >> el;

        if (el == "x") return nullptr;

        TreeNode *root = new TreeNode(stoi(el));

        root->left = helper(iss);
        root->right = helper(iss);

        return root;
    }

};
