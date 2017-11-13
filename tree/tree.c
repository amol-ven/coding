#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

node_t *create_node(int key)
{
	node_t *new = (node_t *)malloc(sizeof(node_t));
	if(new)
	{
		new->key 	= key;
		new->childL = NULL;
		new->childR = NULL;
	}
	return new;
}

void insert_key(node_t *root, int key)
{
	node_t **link = NULL;
	if (!root)
		goto out;

	while (root) {
		if (key > root->key) {
			link  = &root->childR;
			root = root->childR;
		} else {
			link  = &root->childL;
			root = root->childL;
		}
	}
	//we reached a leaf.
	*link = create_node(key);

out:;
}

/*
 * 
 * name: treeToArray
 * @param arr pointer to array of node_t. The array must be initialised to all NULL.
 * @param root the root of the tree.
 * @param offset pass as 1. arr[0] is to be conventiolally set as NULL. So offset 1 indicates the loaction to start from.
 * @param max_array_length max length of the array pointed by arr.
 * @return void
 * 
 */
void _treeToArray(node_t **arr, node_t *root, int offset, int max_array_length)
{
	arr[offset] = root;
	
	
	if(root && ( (offset<<1)+1 < max_array_length) )
	{
		//printf("%2d ", root->key);
		_treeToArray(arr, root->childL, offset<<1, max_array_length);
		_treeToArray(arr, root->childR, (offset<<1) + 1, max_array_length);
	

	}
	else
	{

	}
	
}

void treeToArray(node_t **arr, node_t *root, int max_array_len)
{
	int i;
	for(i=0; i<max_array_len; i++)
	{
		arr[i] = NULL;
	}
	_treeToArray(arr, root, 1, max_array_len);
}
/*
void rotate(node_t *root, int direction)
{
	node_t *x, *T2;
	if(direction == RIGHT)
	{
		x = root->childL;
		T2 = x->childR;
 
		// Perform rotation
		x->childR = root;
		root->childL = T2;
	}
	else
	{
		x = root->childR;
		T2 = x->childL;
 
		// Perform rotation
		x->childL = root;
		root->childR = T2;
	}
}
*/

void rotate(node_t **root, node_t* focus, int direction)
{
	node_t *parent = NULL;
	if ((root == NULL) || (*root == NULL) || (focus == NULL))
		goto out;
	if (direction == LEFT)
		if(!focus->childR)
			goto out;
	if (direction == RIGHT) {
		if(!focus->childL)
			goto out;
	}
	node_t *tmp = *root;
	while (tmp != focus) {
		if (!tmp)
			break;
		parent = tmp;
		if (focus->key > tmp->key)
			tmp = tmp->childR;
		else
			tmp = tmp->childL;
	}

	//Either tmp points to r or r doesnt exist in tree of root
	printf("parent = %d    tmp now is %d\n", parent?parent->key:-1, tmp?tmp->key:-1);

	if(!tmp)
		goto out;

	node_t *new_focus = NULL;
	node_t *new_focus_child = NULL;
	if(direction == LEFT) {
		new_focus = focus->childR;
		new_focus_child = new_focus->childL;
		if(parent) {
			if(parent->childL == focus)
				parent->childL = new_focus;
			else if(parent->childR == focus)
				parent->childR = new_focus;
		}
		new_focus->childL = focus;
		focus->childR = new_focus_child;
		if(*root == focus)
			*root = new_focus;
	} else {
		new_focus = focus->childL;
		new_focus_child = new_focus->childR;
		if(parent) {
			if(parent->childL == focus)
				parent->childL = new_focus;
			else if(parent->childR == focus)
				parent->childR = new_focus;
		}
		new_focus->childR = focus;
		focus->childL = new_focus_child;
		if(*root == focus)
			*root = new_focus;
	}
out:;
}

void dispTreeArray(node_t **array, int max_array_length)
{
	int index=0;
	
	for(index=0;index<max_array_length;index++)
	{
		if(array[index]!=NULL)
		{
			printf("%2d ", array[index]->key);
		}
		else
		{
			printf("** ");
		}
	}
}
 
