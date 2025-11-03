#include "mytree.h"
#include <stdio.h>

int main(int argc, char **argv) {
	FILE *in, *out;
	TreeNodePtr root;
	
	if (argc<2) {
		printf("Syntax: %s <tree_file>\n", argv[0]);
		return -1;
	}
	
	in = fopen(argv[1], "r");
	
	root = buildTreeFromFile(in, default_s2i);
	fclose(in);
	
	printf("The tree is [ ");
	preOrder(root, default_visit_func);
	printf("]\n");
	
	out = fopen("out.txt", "w");
	saveTreeToFile(out, root);
	fclose(out);
	
	
	return 0;
}