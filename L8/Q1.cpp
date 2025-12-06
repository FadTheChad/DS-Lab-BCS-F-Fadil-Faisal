#include <iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) : value(d), left(nullptr), right(nullptr)
    {
    }
};

class BinarySearchTree
{
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr)
    {
    }

    TreeNode* findMin(TreeNode* curr)
    {
        while (curr && curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr;
    }

    void build(int arr[], int size)
    {
        root = nullptr;
        for (int i = 0; i < size; i++)
        {
            root = insert(root, arr[i]);
        }
    }

    TreeNode* insert(TreeNode* curr, int val)
    {
        if (curr == nullptr)
        {
            return new TreeNode(val);
        }

        if (val < curr->value)
        {
            curr->left = insert(curr->left, val);
        }
        else if (val > curr->value)
        {
            curr->right = insert(curr->right, val);
        }

        return curr;
    }

    void inorder(TreeNode* curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        inorder(curr->left);
        cout << curr->value << " ";
        inorder(curr->right);
    }

    void preorder(TreeNode* curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        cout << curr->value << " ";
        preorder(curr->left);
        preorder(curr->right);
    }

    void postorder(TreeNode* curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->value << " ";
    }

    TreeNode* find(TreeNode* curr, int key)
    {
        if (curr == nullptr)
        {
            return nullptr;
        }

        if (curr->value == key)
        {
            return curr;
        }
        else if (key < curr->value)
        {
            return find(curr->left, key);
        }
        else
        {
            return find(curr->right, key);
        }
    }

    TreeNode* remove(TreeNode* curr, int key)
    {
        if (curr == nullptr)
        {
            return nullptr;
        }

        if (key < curr->value)
        {
            curr->left = remove(curr->left, key);
        }
        else if (key > curr->value)
        {
            curr->right = remove(curr->right, key);
        }
        else
        {
            if (curr->left == nullptr)
            {
                TreeNode* temp = curr->right;
                delete curr;
                return temp;
            }
            else if (curr->right == nullptr)
            {
                TreeNode* temp = curr->left;
                delete curr;
                return temp;
            }
            else
            {
                TreeNode* minNode = findMin(curr->right);
                curr->value = minNode->value;
                curr->right = remove(curr->right, minNode->value);
            }
        }
        return curr;
    }

    TreeNode* getRoot()
    {
        return root;
    }
};

int main()
{
    int arr[50];
    int n;

    cout << "Enter element count: ";
    cin >> n;

    cout << "Enter numbers for BST:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    BinarySearchTree tree;
    tree.build(arr, n);

    cout << "\nPreorder: ";
    tree.preorder(tree.getRoot());

    cout << "\nPostorder: ";
    tree.postorder(tree.getRoot());

    cout << "\nInorder: ";
    tree.inorder(tree.getRoot());

    int delVal;
    cout << endl << "Enter value to delete: ";
    cin >> delVal;
    tree.remove(tree.getRoot(), delVal);

    cout << endl << "Inorder after deletion: ";
    tree.inorder(tree.getRoot());

    int value;
    cout << endl << "Enter value to find: ";
    cin >> value;

    if (tree.find(tree.getRoot(), value))
    {
        cout << "Value found!";
    }
    else
    {
        cout << "Value not found!";
    }

    return 0;
}
