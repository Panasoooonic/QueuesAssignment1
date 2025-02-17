#include <iostream>


using namespace std;

struct User
{
	int faction;
	char* username;
	int level;
};


struct LinkedNode
{
	User user;
	LinkedNode* next;
};


struct Queue
{
	LinkedNode* head;
	LinkedNode* tail;
};



void getName(char* primaryName)
{
	char* newName = (char*)malloc(sizeof(char)*9);
	for (int j = 0; j < 10; j++)
	{
		int letterONum = rand() % 2 + 1; // Determine if the next part of the username is a letter or a number
		if (letterONum == 1)
		{
			int ranLetter = rand() % (122 - 97 + 1) + 97;
			*(newName + j) = char(ranLetter);
		}
		else
		{
			int ranNum = rand() % (57 - 48 + 1);+48;
			*(newName + j) = char(ranNum);
		}
	}
	cout << newName << endl;
	primaryName = newName;
}


int getFaction()
{
	int faction;
	int factionNum = rand() % 3 + 1;
	switch (factionNum)
	{
	case(1): {
		faction = 1;
		break;
	}
		
	case(2): {
		faction = 2;
		break;
	}
		
	case(3): {
		faction = 3;
		break;
	}
	}
	
	return faction;
}

User createUser()
{
	srand(time(0));
	struct User newUser;
	
	getName(newUser.username);
	
	newUser.faction = getFaction();
	newUser.level =  rand() % 60 + 1;

	return newUser;
}


int createLinkedNode(struct LinkedNode* node)
{
	User newUser = createUser();
	printf("OK1");
	node->user.username = newUser.username;
	printf("OK2");
	node->user.faction = newUser.faction;
	node->user.level = newUser.level;

	cout << node->user.faction << endl;
	printf("OK3");
	if ((strlen(node->user.username) == 10) &&
		(node->user.faction == 1 || node->user.faction == 2 || node->user.faction == 3) &&
		(node->user.level >= 1 && node->user.level <= 60))
	{
		
		cout << node->user.username << endl;
		node->next = NULL;
		return 0;
	}
	return 1;
}



Queue* createQueue()
{
	Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}


bool checkQueue(struct Queue* queue)
{
	if (queue->head == NULL)
	{
		return true;
	}

	return false;
}




void enqueueNode(struct Queue* queue, struct LinkedNode* node)
{
	bool isEmpty = checkQueue(queue);
	if (isEmpty)
	{
		queue->head = node;
		printf("\nQueue first head has been added");
	}
	else
	{
		node->next = queue->head;
		if (queue->tail == NULL)
		{
			queue->tail = queue->head;
			printf("\nQueue tail has been added");
		}
		queue->head = node;
	}
}


void dequeueNode(struct Queue* queue)
{
	//bool isEmpty = checkQueue(queue);
	if (queue->tail != NULL)
	{
		queue->head = queue->head->next;
		printf("\nHead of the queue has been removed");
	}
	else
	{
		queue->head = NULL;
		printf("\nHead of the queue has been removed, Queue is empty");
	}
}


int main(int argc, char* argv[])
{
	struct Queue* newQueue = createQueue();
	bool isEmpty = checkQueue(newQueue);
	if (isEmpty)
	{
		printf("\nQueue is empty");
	}
	else
	{
		cout << newQueue << endl;
		printf("\nQueue is not empty");
	}

	for (int i = 0; i < argc; i++)
	{
		struct LinkedNode* ptr = (struct LinkedNode*)malloc(sizeof(struct LinkedNode));
		int boolean = createLinkedNode(ptr);
		if (boolean == 0)
		{
			enqueueNode(newQueue, ptr);
		}
		else
		{
			printf("\nLinked node could not be queued due to error");
		}
		
	}

	for (int i = 0; i < argc; i++)
	{
		dequeueNode(newQueue);
	}
	
}