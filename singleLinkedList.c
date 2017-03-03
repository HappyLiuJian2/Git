/*Single Linked List*/
#include <stdio.h>
#include <stdlib.h>

//node struct in a list
typedef struct node Node;
struct node
{
	char *content;
	Node *next;
};

//list struct
typedef struct list List;
struct list
{
	Node *head;
	int size;
};

List* makeEmpty();
void printList(List *list);
void insertToIndex(List* list, Node* node, int index);
void deleteFromIndex(list* list, int index);
void clearList();

List* makeEmpty()
{
	List* innerList = (List*)malloc(sizeof(List));
	Node* innerHead = (Node*)malloc(sizeof(Node));
	innerHead->content = "initial";
	innerList->head = innerHead;
	innerList->size = 1;
	return innerList;
}

void printList(List* list)
{
	Node* currentNode = list->head;

	while(NULL != currentNode)
	{
		printf("%s\n", currentNode->content);
		currentNode = currentNode->next;
	}
}

void insertToIndex(List* list, Node* node, int index)
{
	int innerIndex = 0;
	Node* currentNode = list->head;

	if (index > list->size)
	{
		printf("size is out of list.\n");
		return;
	}

    if (0 == index)
    {
        node->next = list->head;
        list->head = node;
        list->size++;
        return;
    }

	while(NULL != currentNode)
	{
		innerIndex++;
		if (index == innerIndex)
		{
			break;
		}
		currentNode = currentNode->next;
	}
	
	node->next = currentNode->next;
	currentNode->next = node;
    list->size++;
	return;
}

void deleteFromIndex(list* list, int index)
{
	Node* currentNode = list->head;
	Node* tmpNode;
	int innerIndex = 0;

	if (index > list->size)
	{
		printf("size is out of list.\n");
		return;
	}

    if (0 == index)
    { 
        list->head = currentNode->next;
        list->size--;
        free(currentNode);
        return;
    }

	while (NULL != currentNode)
	{
		innerIndex++;
		if (innerIndex == index)
		{
			break;
		}
		currentNode = currentNode->next;
	}

	tmpNode = currentNode->next;
	currentNode->next = tmpNode->next;
	free(tmpNode);
	return;
}

void clearList(List* list)
{
	Node* currentNode = list->head;
	Node* tmpNode;
	while(NULL != currentNode)
	{
		tmpNode = currentNode->next;
		free(currentNode);
		currentNode = tmpNode;
	}
	list->head = NULL;
	list->size = 0;
}

int main()
{
	List* list = makeEmpty();
	printList(list);
    Node* node = (Node*)malloc(sizeof(Node));
    node->content = "second";
    insertToIndex(list,node,1);
    printList(list);
	return 0;
}
