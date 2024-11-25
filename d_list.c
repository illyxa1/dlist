#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "d_list.h"
#include "error.h"

// dlist - struckt, what must to contain link("link") on dynamic list with size ("size") of type with "type_size"
//-= FUNCTIONAL =------------------------------------------------------------------------------------------------------------------------------------
size_t correct_size(float size);
//-= GLOBAL =----------------------------------------------------------------------------------------------------------------------------------------
int init_dlist(Dlist *dlist_link, size_t size, size_t type_size)
{// initalisates dlist, sets sizes, alocates memory for array;
	if (dlist_link == NULL)
		error(E_INVALID_POINTER, __FILE__, __LINE__);

	dlist_link -> size = correct_size(size);
	dlist_link -> pseudo_size = size;
	dlist_link -> at = 0;
	dlist_link -> type_size = type_size;

	dlist_link -> link = malloc(type_size * dlist_link -> size);
	return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int prepare_dlist(Dlist *dlist_link)
{
	void *new_place;

	if (dlist_link == NULL)
		error(E_INVALID_POINTER, __FILE__, __LINE__);

	if ((dlist_link -> at) >= (dlist_link -> size)) // if array too small
	{
		if (dlist_link -> size < MAXINC)
		{
			dlist_link -> size *= 2;
			dlist_link -> pseudo_size ++;
		}
		else dlist_link -> size += MAXINC; // if array to big to incrase it 2 times

		new_place = malloc(dlist_link -> type_size * (dlist_link -> size)); // void** on new place void* 
		memcpy(new_place, dlist_link -> link, dlist_link -> type_size * dlist_link -> size);
		free(dlist_link -> link);
		dlist_link -> link = new_place; // redirection of array
	}// else everything is okay
	return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int is_dlist_overflow(Dlist *dlist_link)
{
	if ((dlist_link -> at) < (dlist_link -> size)) // if pointer on last smaller, than last 
		return 0;
	else
		return 1;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
//-= LOCAL =-----------------------------------------------------------------------------------------------------------------------------------------
size_t correct_size(float size)
{ // returns new size, what will be power of 2
	int c_size = 1;
	while (size > 1)
	{
		c_size *= 2;
		size /= 2;
	}
	return (size_t)c_size;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
