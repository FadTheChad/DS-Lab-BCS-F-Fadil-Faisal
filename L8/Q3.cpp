#include <iostream>
#include <climits>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : data(v), left(nullptr), right(nullptr)
    {
    }
};

class BinarySearchTree
{
    TreeNode* root;

    TreeNode* add(TreeNode* curr, int val)
    {
        if (curr == nullptr)
        {
            return new TreeNode(val);
        }

        if (val < curr->data)
        {
            curr->left = add(curr->left, val);
        }
        else if (val > curr->data)
        {
            curr->right = add(curr->right, val);
        }

        return curr;
    }

    bool check(TreeNode* curr, TreeNode* low, TreeNode* high)
    {
        if (curr == nullptr)
        {
            return true;
        }

        if (low && curr->data <= low->data)
        {
            return false;
        }

        if (high && curr->data >= high->data)
        {
            return false;
        }

        return check(curr->left, low, curr) &&
               check(curr->right, curr, high);
    }

    void inorder(TreeNode* curr)
    {
        if (!curr)
        {
            return;
        }
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }

public:
    BinarySearchTree() : root(nullptr)
    {
    }

    void make(int arr[], int size)
    {
        root = nullptr;
        for (int i = 0; i < size; i++)
        {
            root = add(root, arr[i]);
        }
    }

    bool valid()
    {
        return check(root, nullptr, nullptr);
    }

    void show()
    {
        inorder(root);
        cout << endl;
    }

    void setRoot(TreeNode* r)
    {
        root = r;
    }

    TreeNode* getRoot()
    {
        return root;
    }
};

int main()
{
    int list1[] = {12, 7, 25, 3, 9};
    int size1 = 5;

    BinarySearchTree tree1;
    tree1.make(list1, size1);

    cout << "Tree 1 - Inorder: ";
    tree1.show();

    if (tree1.valid())
    {
        cout << "Valid BST\n\n";
    }
    else
    {
        cout << "Not a BST\n\n";
    }

    TreeNode* A = new TreeNode(30);
    TreeNode* B = new TreeNode(10);
    TreeNode* C = new TreeNode(40);
    TreeNode* D = new TreeNode(50);

    A->left = B;
    A->right = C;
    B->left = D;

    BinarySearchTree tree2;
    tree2.setRoot(A);

    cout << "Tree 2 - Inorder: ";
    tree2.show();

    if (tree2.valid())
    {
        cout << "Valid BST\n";
    }
    else
    {
        cout << "Not a BST\n";
    }

    return 0;
}
