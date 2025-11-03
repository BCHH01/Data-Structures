#ifndef _mytree_h
#define _mytree_h

#include <stdio.h>

typedef int NodeData;
typedef struct _TreeNode {
    NodeData data;
    struct _TreeNode *left, *right;
} TreeNode, *TreeNodePtr;

typedef NodeData (*str2data)(const char *str);
NodeData default_s2i(const char *s);

typedef void (*visit_func)(TreeNodePtr node);
void default_visit_func(TreeNodePtr node);


TreeNodePtr buildTreeFromFile(FILE *in, str2data f);
void saveTreeToFile(FILE *out, TreeNodePtr root);
void freeTree(TreeNodePtr root);
void preOrder(TreeNodePtr root, visit_func visit);
void inOrder(TreeNodePtr root, visit_func visit);
void postOrder(TreeNodePtr root, visit_func visit);

TreeNodePtr buildBSTFromFile(FILE *in, str2data f);

#endif
