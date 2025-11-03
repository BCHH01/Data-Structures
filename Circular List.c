/**
 * Print the children IDs starting from the given first child.
 * @param first The pointer to the first child (may be NULL).
 */
void printChildren(Child *first) {
    Child* First_Child = first;
	printf("Children: [ ");
	if (first != NULL) {
		do {
			printf("%d ", First_Child->id);
            First_Child = First_Child->next;
		} while (First_Child != first);
	}
	printf("]\n");
}

/**
 * Remove the m-th child from the circular list.
 * @param first The first child for starting the count.
 * @param m The (positive) count to the target child.
 * @return The pointer to the new first child.
 */
Child *countOut(Child *first, int m) {
	if (first == NULL) {
		return first;
	}
	
    if (first->next == first) {
        free(first);
        return NULL;
    }
	
	for(int i = 0; i < (m - 1); i++) {
		first = first->next;
	}
	
	Child* previous = first, *firstNode = first;
	while(previous->next != first) {
		previous = previous->next;
	}
	previous->next = firstNode->next;
    first = previous->next;
    free(firstNode);
    return first;
}
