#include <stdio.h>
#include "d_list.h"

int main()
{
	int i;
	struct dlist a; // firstly creating a new structure - a
	init_dlist(&a, 10, sizeof(int)); // init it with requaired type_size(sizeof(int)) and size(10)
	
	for (; !is_dlist_overflow(&a); append(a, int, a.at)); // check on dlist overfloving, then append new element
	for (i=0; i < a.size; i++) printf("%d, ", get(a, i, int)); // when iterating, we can use another var, just compare it with size
								   // next get a current element, and print it;

	printf("\nat:%ld;\nsize:%ld;\ntype_size:%ld;\nlinked_on:%d;\n", a.at, a.size, a.type_size, get(a, 0, int));
	// print info about structure

	
	printf("\nat:%ld;\nsize:%ld;\ntype_size:%ld;\nlinked_on:%d;\n", a.at, a.size, a.type_size, get(a, 0, int));
	return 0;
}
