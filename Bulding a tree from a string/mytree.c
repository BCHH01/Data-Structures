#include "mytree.h"
#include <string.h>
#include <stdlib.h>

NodeData default_s2i(const char *s) {
	int v;
	sscanf(s, "%d", &v);
	return v;
}

TreeNodePtr buildTreeFromFile(FILE *in, str2data f) {
	char item[100];
	TreeNodePtr root; 
	
	fscanf(in, "%s", item);
	
	/* empty tree */
	if (item[0]=='@') {
		return NULL;
	}
	
	/* root node */
	root = (TreeNodePtr)malloc(sizeof(TreeNode));
	root->data = f(item);
	root->left = buildTreeFromFile(in, f);
	root->right = buildTreeFromFile(in, f);
	
	return root;
}

void saveTreeToFile(FILE *out, TreeNodePtr root) {
	if (root==NULL) {
		fprintf(out, "@ ");
		return;
	}
	
	fprintf(out, "%d ", root->data);
	saveTreeToFile(out, root->left);
	saveTreeToFile(out, root->right);
}

void default_visit_func(TreeNodePtr node) {
	printf("%d ", node->data);
}

void preOrder(TreeNodePtr root, visit_func visit) {
	if (root==NULL) { return; }
	
	visit(root);
	preOrder(root->left, visit);
	preOrder(root->right, visit);
}

TreeNodePtr addToBST(TreeNodePtr root, NodeData v) {
	if (root==NULL) {
		root = (TreeNodePtr)malloc(sizeof(TreeNode));
		root->data = v;
		root->left = NULL;
		root->right = NULL;
	} else if (root->data>v) {
		root->left = addToBST(root->left, v);
	} else if (root->data<v) {
		root->right = addToBST(root->right, v);
	}
	return root;
}

TreeNodePtr buildBSTFromFile(FILE *in, str2data f) {
	char item[100];
	int v;
	TreeNodePtr root = NULL;
	
	while (fscanf(in, "%s", item)==1) {
		v = f(item);
		root = addToBST(root, v);
	}
	return root;	
}