#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node
{
	int value;
	struct Node* left;
	struct Node* right;
}Node;

Node* insert(Node* node, int val);
void postOrder(Node* node);
double timeExec(struct timespec start, struct timespec end);

int main()
{
	int n;
	int i;
	struct timespec start, end;
	
	scanf("%d", &n);
	
	printf("\n");

	clock_gettime(CLOCK_REALTIME, &start);	//execTime
	int* arr = malloc(sizeof(int) * n);
	
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	Node* root = NULL;
	
	//insertion
	for(i = 0; i < n; i++)
		root = insert(root, arr[i]);

	//traversal
	postOrder(root);
	clock_gettime(CLOCK_REALTIME, &end);	//execTime
	
	printf("\nExecution Time : %lf ms\n", timeExec(start, end));	//execTime
	
	return 0;
}

Node* insert(Node* node, int val)
{
	if(node == NULL)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode -> value = val;
		newNode -> left = NULL;
		newNode -> right = NULL;
		return newNode;
	}

	if(val <= node -> value)	//repeated values are appended as left children of the already existing values
		node -> left = insert(node -> left, val);
	else
		node -> right = insert(node -> right, val);

	return node;	//returning the root of the modified tree	
}

void postOrder(Node* node)
{
	if(node == NULL)
		return;

	postOrder(node -> left);
	postOrder(node -> right);
	printf("%d\n", node -> value);
}

double timeExec(struct timespec start, struct timespec end)
{
	double t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001;

	return t;
}
