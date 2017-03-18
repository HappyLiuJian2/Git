#include <iostream>
#include <queue>
using namespace std;

typedef struct T_NODE_S* NODE;
typedef struct T_NODE_S* TREE;
typedef int ElementType;

struct T_NODE_S
{
	ElementType ele;
	TREE left_child;
	TREE right_child;
};

T_NODE_S root;

void initTree()
{
	root.ele = -1;
	root.left_child = NULL;
	root.right_child = NULL;
	return;
}

void printNode(NODE inode)
{
	cout << inode->ele << endl;
	return;
}

void BFSsearchTree()
{
	queue<NODE> sched_queue;
	sched_queue.push(&root);
	while (!sched_queue.empty())
	{
		NODE cur_node = sched_queue.front();
		sched_queue.pop();
		printNode(cur_node);
		if (NULL != cur_node->left_child)
			sched_queue.push(cur_node->left_child);
		if (NULL != cur_node->right_child)
		sched_queue.push(cur_node->right_child);
	}

}

int main()
{

}
