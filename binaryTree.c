/*binary tree*/
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode Tree
typedef struct treeNode Node

struct treeNode
{
    int content;
    Tree *left;
    Node *right;
};


Tree* makeEmpty();
Tree* findNode(Tree* tree, int index);
Node* findMinLeft(Tree* tree);
void insertNode(Tree* tree, Node* node);
void deleteNode(Tree* tree, Node* node);

Tree* makeEmpty()
{
    tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->left = NULL;
    tree->right = NULL;
    tree->content = -1;
    return tree;
}

Tree* findNode(Tree* tree, int index)
{
    Node* curNode = tree;
    if (index > curNode->content)
    {
        findNode(curNode->right, index);
    } 
    else if (index < curNode->content)
    {
        findNode(curNode->left, index);
    }
    else
    {
        printf("Current node is %d\n", curNode->content);
        return curNode;
    }
}

void insertNode(Tree* tree, Node* node)
{
    Node* curNode = tree;
    if (NULL == curNode)
    {
        curNode = node;
        return;
    }
    if (index > curNode->content)
    {
        insertNode(curNode->right, node);
    } 
    else if (index < curNode->content)
    {
        insertNode(curNode->left, node);
    }
    else
    {
        printf("Insert node has been in the tree.\n");
        return;
    }
}

void deleteNode(Tree* tree, Node* node)
{
    Node* curNode = tree;
    Node* tmpNode;
    if (node->content > curNode->content)
    {
        deleteNode(curNode->right, node);
    } 
    else if (node->content < curNode->content)
    {
        deleteNode(curNode->left, node);
    }
    else
    {
        if (curNode->left == NULL && curNode->right == NULL)
        {
            free(curNode);
            curNode = NULL;
            return;
        }
        else if (curNode->left != NULL && curNode->right == NULL)
        {
            curNode = curNode->left;
            free(curNode);
            curNode = NULL;
        }
        else if (curNode->left == NULL && curNode->right != NULL)
        {
            curNode = curNode->right;
            free(curNode);
            curNode = NULL;
        }
        else
        {
            tmpNode = findMinLeft(curNode->right);
            curNode = tmpNode;
            free(tmpNode);
            tmpNode = NULL;
        }
        return curNode;
    }
}

Node* findMinLeft(Tree* tree)
{
    Node* curNode = tree;
    while (NULL != curNode->left)
    {   
        curNode = curNode->left;
    }

    return curNode;
}
