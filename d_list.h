#define get(DLIST, AT, TYPE) (AT < DLIST.size)? (*(( (TYPE*) DLIST.link ) + AT)) : \
		error(E_INVALID_LIST_ELEMENT, __FILE__, __LINE__)
 // macros, what makes new abstraction above dlist reading
 //
#define set(DLIST, AT, TYPE, VALUE) (AT < DLIST.size)? (*(( (TYPE*) DLIST.link ) + AT)) = VALUE : \
		error(E_INVALID_LIST_ELEMENTT, __FILE__, __LINE__)
 // macros, what makes new abstraction above dlist writing
 //
#define append(DLIST, TYPE, VALUE) (DLIST.at >= DLIST.size)? 								\
					(prepare_dlist(&DLIST), *(( (TYPE*) DLIST.link ) + DLIST.at++) = VALUE): \
				   	(*(( (TYPE*) DLIST.link ) + DLIST.at++) = VALUE, (DLIST.pseudo_size < DLIST.at)?\
					 DLIST.pseudo_size++ :0)// error(E_OK, __FILE__, __LINE__))
				   
#define MAXINC 64
//-= STRUCTS =---------------------------------------------------------------------------------------------------------------------------------------
struct dlist{
	size_t at;
	size_t size;
	size_t pseudo_size;
	size_t type_size;
	void *link;

};
typedef struct dlist Dlist;
//-= DEFS =------------------------------------------------------------------------------------------------------------------------------------------
int init_dlist(Dlist *dlist_link, size_t size, size_t type_size); 
// initalise dlist of objects of "type_size" with size "size", and stores it to pointer on void in "link"
int prepare_dlist(Dlist *dlist_link);
// if dlist owerfowed, prepaires it to adding new data
int is_dlist_overflow(Dlist *dlist_link);
// checks on dlist overflowing
