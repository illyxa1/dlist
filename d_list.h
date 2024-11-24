#define get(DLIST, AT, TYPE) (AT < DLIST.size)? (*(( (TYPE*) DLIST.link ) + AT)) : 0// : error(OWERFLOW) // macros, what makes new abstraction above dlist reading
#define set(DLIST, AT, TYPE, VALUE) (AT < DLIST.size)? (*(( (TYPE*) DLIST.link ) + AT)) = VALUE : 0// : error(OWERFLOW) // macros, what makes new abstraction above dlist writing
#define append(DLIST, TYPE, VALUE) (DLIST.at >= DLIST.size)? 								\
					(prepare_dlist(&DLIST), *(( (TYPE*) DLIST.link ) + DLIST.at++) = VALUE): \
				   	(*(( (TYPE*) DLIST.link ) + DLIST.at++) = VALUE)

#define MAXINC 64
//-= STRUCTS =---------------------------------------------------------------------------------------------------------------------------------------
struct dlist{
	size_t at;
	size_t size;
	size_t type_size;
	void *link;

};
//-= DEFS =------------------------------------------------------------------------------------------------------------------------------------------
int init_dlist(struct dlist *dlist_link, size_t size, size_t type_size); 
// initalise dlist of objects of "type_size" with size "size", and stores it to pointer on void in "link"
int prepare_dlist(struct dlist *dlist_link);
// if dlist owerfowed, prepaires it to adding new data
int is_dlist_overflow(struct dlist *dlist_link);
// checks on dlist overflowing
