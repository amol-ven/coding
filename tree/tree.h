#ifndef _TREE_H
#define _TREE_H

#define LEFT 1
#define RIGHT 2

typedef struct node
{
	//struct node *parent;
	struct node *childL, *childR;
	int key;
}node_t;


//void treeToArray(node_t **arr, node_t *root, int offset, int max_array_length);
void treeToArray(node_t **arr, node_t *root, int max_array_length);
//node_t *createNode(node_t *parent, node_t *childL, node_t *childR, int key);
node_t *create_node(int key);
void rotate(node_t **root, node_t *r, int direction);
void dispTreeArray(node_t **array,int max_array_length);


















#endif
