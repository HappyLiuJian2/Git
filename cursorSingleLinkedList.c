/*cursor single linked list*/
//for no pointer or class lang. like fortran or basic
#include <stdio.h>
#include <stdlib.h>

#define SPACE_SIZE 10

typedef int Node;
typedef int List;

struct node
{
	char content;
	Node next;
}

struct node cursorSpace[SPACE_SIZE];

void initialCursorSpace();
Node cursorAlloc();
void cursorFree();

List makeEmpty();
void printList(List list);
void insertToIndex(List list, Node node, int index);
void deleteFromIndex(list list, int index);
void clearList();

// monitor of alloc and free struct Node.
// cursorSpace is the total memory that can be alloced.
// cursorSpace structure looks like:
//		------------------------------
//		-- slot -- Element -- next  --
//		--	0	--		   --	1   --				
//		--	1	--		   --	2   --
//		--	2	--		   --	3   --
//		--	3	--		   --	4   --
//		--	4	--		   --	5   --
//		--	5	--		   --	6   --
//		--	6	--		   --	7   --
//		--	7	--		   --	8   --
//		--	8	--		   --	9   --
//		--	9	--		   --	0   --
//		------------------------------
// we use cursor num to monitor pointer in C/C++
// in which zero(0) represnt NULL
// if the cursorPointer is big enough
// it looks much like a memory page table.
void initialCursorSpace()
{
	int i = 0;
	for (i = 0; i < SPACE_SIZE; i++)
	{
		cursorSpace[i].next = (i + 1)%10;
	}
	return;
}

Node cursorAlloc()
{
	Node p;
	p = cursorSpace[0].next;
	cursorSpace[0].next = cursorSpace[p].next;

	return p;
}

void cursorFree(Node p)
{
	cursorSpace[p].next = cursorSpace[0].next;
	cursorSpace[0].next = p;
}

List makeEmpty()
{
	List list = cursorAlloc();
	cursorSpace[list].content = 'i';
	return list;
}

void printList(List list)
{
	int index = list;

	while(cursorSpace[index] != 0)
	{
		printf("%s\n", cursorSpace[index].content);
		index = cursorSpace[index].next;
	}

	return;
}

void insertToIndex(List list, Node node, int index)
{
	int innerIndex = 0;
	Node currentNode = list;
	Node tmpNode;

	while(NULL != currentNode)
	{
		innerIndex++;
		if (innerIndex == index)
		{
			break;
		}
		currentNode = currentNode.next;
	}

	tmpNode = currentNode.next;
	currentNode.next = node;
	node.next = tmpNode.next;
	return;
}

void deleteFromIndex(list list, int index)
{
	int innerIndex = 0;
	Node currentNode = list;
	Node tmpNode;

	while(NULL != currentNode)
	{
		innerIndex++;
		if (innerIndex == index)
		{
			break;
		}
		currentNode = currentNode.next;
	}

	tmpNode = currentNode.next;
	currentNode.next = tmpNode.next;
	cursorFree(tmpNode);
	return;
}

void clearList()
{
	
}
