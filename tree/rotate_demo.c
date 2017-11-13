#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


#define ARRAY_SIZE 20

int main(void)
{
	node_t n1, n2, n3, n4;
	
	node_t *disp_array[ARRAY_SIZE];
	
	node_t *root = NULL;
	//n1.parent = NULL;
	n1.childL = &n2;
	n1.childR = &n3;
	n1.key = 1;
	
	//n2.parent = &n1;
	n2.key = 2;
	n2.childL = NULL;
	n2.childR = NULL;
	
	//n3.parent = &n1;
	n3.key = 3;
	n3.childL = NULL;
	n3.childR = &n4;

	n4.key = 4;
	n4.childL = NULL;
	n4.childR = NULL;

	root = &n1;

	insert_key(root, 5);
	
	treeToArray(disp_array, root, ARRAY_SIZE);

	dispTreeArray(disp_array, ARRAY_SIZE);
	printf("\n");

//	node_t *new = create_node(5);
//	if(new)
//	{
//		n3.childL = new;
//	}
//	treeToArray(disp_array, root, ARRAY_SIZE);
//	dispTreeArray(disp_array, ARRAY_SIZE);
//	printf("\n");


	rotate(&root, &n3, LEFT);

	treeToArray(disp_array, root, ARRAY_SIZE);
	dispTreeArray(disp_array, ARRAY_SIZE);
	printf("\n\n");



	return 0;
}
