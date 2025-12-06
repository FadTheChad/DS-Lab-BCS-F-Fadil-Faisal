#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class FighterNode
{
public:
    int id;
    string name;
    int hp;
    int power;
    FighterNode* left;
    FighterNode* right;

    FighterNode(int i, string n, int h, int p) : id(i), name(n), hp(h), power(p), left(nullptr), right(nullptr)
    {
    }
};

class FighterBST
{
    FighterNode* root;

    FighterNode* getMin(FighterNode* node)
    {
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }

    void inorderShow(FighterNode* node)
    {
        if (!node)
        {
            return;
        }
        inorderShow(node->left);
        cout << "\nID: " << node->id << ", Name: " << node->name
             << ", HP: " << node->hp << ", AP: " << node->power;
        inorderShow(node->right);
    }

    FighterNode* addNode(FighterNode* node, int i, string n, int h, int p)
    {
        if (!node)
        {
            return new FighterNode(i, n, h, p);
        }

        if (i < node->id)
        {
            node->left = addNode(node->left, i, n, h, p);
        }
        else if (i > node->id)
        {
            node->right = addNode(node->right, i, n, h, p);
        }

        return node;
    }

    FighterNode* dropNode(FighterNode* node, int i)
    {
        if (!node)
        {
            return nullptr;
        }

        if (i < node->id)
        {
            node->left = dropNode(node->left, i);
        }
        else if (i > node->id)
        {
            node->right = dropNode(node->right, i);
        }
        else
        {
            if (!node->left)
            {
                FighterNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right)
            {
                FighterNode* temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                FighterNode* minNode = getMin(node->right);
                node->id = minNode->id;
                node->name = minNode->name;
                node->hp = minNode->hp;
                node->power = minNode->power;
                node->right = dropNode(node->right, minNode->id);
            }
        }
        return node;
    }

public:
    FighterBST() : root(nullptr)
    {
    }

    void add(int i, string n, int h, int p)
    {
        root = addNode(root, i, n, h, p);
    }

    void remove(int i)
    {
        root = dropNode(root, i);
    }

    FighterNode* getFirst()
    {
        FighterNode* temp = root;
        if (!temp)
        {
            return nullptr;
        }
        while (temp->left)
        {
            temp = temp->left;
        }
        return temp;
    }

    void display()
    {
        if (!root)
        {
            cout << "\n(Empty team)";
            return;
        }
        inorderShow(root);
        cout << endl;
    }

    FighterNode* getRoot()
    {
        return root;
    }
};

void fight(FighterBST& team1, FighterBST& team2, int round)
{
    cout << "\n========================";
    cout << "\n        ROUND " << round << "";
    cout << "\n========================\n";

    cout << "\n--- TEAM 1 ---";
    team1.display();
    cout << "\n--- TEAM 2 ---";
    team2.display();
    cout << endl;

    FighterNode* a = team1.getFirst();
    FighterNode* b = team2.getFirst();

    if (!a || !b)
    {
        return;
    }

    cout << "\nTeam 1 front: " << a->name << " (HP: " << a->hp << ")";
    cout << "\nTeam 2 front: " << b->name << " (HP: " << b->hp << ")\n";

    int hitA = a->power + (rand() % 5);
    b->hp -= hitA;
    cout << "Team 1 " << a->name << " hits " << b->name
         << " for " << hitA << " damage!\n";

    if (b->hp <= 0)
    {
        cout << "Team 2 " << b->name << " is down!\n";
        team2.remove(b->id);
        return;
    }

    int hitB = b->power + (rand() % 5);
    a->hp -= hitB;
    cout << "Team 2 " << b->name << " strikes back for " << hitB << " damage!\n";

    if (a->hp <= 0)
    {
        cout << "Team 1 " << a->name << " is out!\n";
        team1.remove(a->id);
    }
}

void battle(FighterBST& team1, FighterBST& team2)
{
    int round = 1;
    while (team1.getRoot() && team2.getRoot())
    {
        fight(team1, team2, round);
        round++;
    }

    if (!team2.getRoot())
    {
        cout << "\nTEAM 1 WINS!\n";
    }
    else
    {
        cout << "\nTEAM 2 WINS!\n";
    }
}

int main()
{
    srand(time(NULL));

    FighterBST team1, team2;

    team1.add(10, "Warrior", 45, 8);
    team1.add(5, "Archer", 30, 7);
    team1.add(15, "Mage", 25, 10);
    team1.add(3, "Shield", 50, 6);
    team1.add(8, "Rogue", 28, 9);

    team2.add(12, "Troll", 22, 5);
    team2.add(6, "Barbarian", 35, 8);
    team2.add(18, "Warlock", 30, 9);
    team2.add(1, "Zombie", 20, 4);
    team2.add(9, "Giant", 55, 7);

    cout << "\n==== BATTLE START ====\n";
    battle(team1, team2);

    return 0;
}
