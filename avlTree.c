/*AVL TREE(Typpo of balance tree)*/
#include <stdio.h>
#include <stdlib.h>

typeof struct avlNode Tree;
typeof struct avlNode Node;
struct avlNode
{
    int content;
    int height;
    Node* left;
    Node* right;
};

Tree* makeEmpty();
void findNode();
void insertNode();
Tree* deleteNode();
int getHeight(Tree* tree);

Tree* makeEmpty()
{
    Tree* tree = (Tree*)malloc(sizeof(avlNode));
    tree->left = tree->right = NULL;
    tree->height = -1;
}

void findNode(Tree* tree, Node* node)
{
    
}

int getHeight(Tree* tree)
{
    return tree->height;    
}

void singleRotationWithLeft(Node* node_1)
{
    Node* node_2 = node_1->left;

    //single rotation to banlance AVL tree
    //ignore the height
    node_1->left = node_2->right;
    node_2->right = node_1;

    return;    
}

void singleRotationWithRight(Node* node_1)
{
    Node* node_2 = node_1->right;

    //single rotation to banlance AVL tree
    //ignore the height
    node_1->right = node_2->left;
    node_2->left = node_1;

    return;
}

void doubleRotationWithLeft(Node* node_1)
{
    Node* node_2 = node_1->left;
    Node* node_3 = node_2->right;

    //double rotation to balance AVL tree
    node_1->left = node_3->right;
    node_2->right = node_3->left;
    node_3->left = node_2;
    node_3->right = node_1;

    return;
}

void doubleRotationWithRight(Node* node_1)
{
    Node* node_2 = node_1->right;
    Node* node_3 = node_1->left;

    //double rotation to banlance AVL tree
    node_1->right = node_3->left;
    node_2->left = node_3->right;
    node_3->left = node_1;
    node_3->right = node_2;

    return;
}

Tree* insertNode(Tree* tree, Node* node)
{
    if (NULL == tree)
    {
        return node;
    }
    else if (node->content < tree->cnotent)
    {
        tree->left = insertNode(tree->left, node);
        if (getHeight(tree->left) - getHeight(tree->right) == 2)
        {
            if (node->content < tree->left->content)
            {
                singleRotationWithLeft(tree);
            }
            else
            {
                doubleRotationWithLeft(tree);
            }
        }
    } 
    else
    {
        tree->right = insertNode(tree->right, node);
        if (getHeight(tree->right) - getHeight(tree->left) == 2)
        {
            if (node->content > tree->right->content)
            {
                singleRotationWithRight(tree);
            }
            else
            {
                doubleRotationWithRight(tree);
            }
        }
    }

    return tree;
}


