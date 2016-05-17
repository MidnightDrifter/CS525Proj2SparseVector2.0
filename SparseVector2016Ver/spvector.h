#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H
#include <cstdio> /* printf */

struct ElementNode
{
	int    data;
	int    pos;
	struct ElementNode* next;
};



struct RowNode
{
	int pos;
	struct ElementNode* elements;
	struct RowNode* next;
};


/*===================*
* element functions *
*===================*/

/** \brief print elements as a vector, adding 0's for non-existing positions assume the length of the vector = dim doesn't check if the list contains positions beyond dim
* \param 'ElementNode const * p_e1' == A constant pointer that defines the head of the given vector
* \param 'char * fmt' == A string that defines how to format the output of the vector for the 'printf' function
* \param 'int dim' == The length of the given vector
* \return The elements of the vector printed as a vector
**/
void printf_elements(ElementNode const * p_el, char *fmt, int dim);

/**
* \brief print all elements in the list with positions
* \param 'ElementNode const * p_e1' == A constant pointer to the head of the given list **/
void print_elements(ElementNode const * p_el); /* no zeros */

											   /** \brief insert an element into a listt, list is ordered using pos, if position pos is already occupied, the value of the node should be updated with val, if val=0, then the element should be deleted, return 0 if operation is successful, 1 if malloc failed
											   * \param 'ElementNode  * * p_e' == a pointer to the head of the list to insert into
											   * \param 'int pos' == the position where you need to insert the node
											   * \param 'int val' == the data of the node to insert
											   * \return 0 if successful insert, 1 if malloc failed
											   **/
int insert_element(ElementNode  * * p_e, int pos, int val);

/**
* \brief delete an element at position pos if it exists
* \param 'ElementNode  * * p_e' == a pointer to the head of the list to delete from
* \param 'int pos' == the position of the node to delete
* \return Nothing, simply  deletes the node if it exists
**/
void delete_element(ElementNode  * *p_e, int pos);

/**
* \brief get the value at the given position, p_e is the head pointer
* \param 'ElementNode const * p_e' == a constant pointer to the head of the vector to get the value from
* \param 'int pos' == the position of the node to get the value of, if it exists
* \return 0 if the node doesn't exist, the data within the node otherwise
**/
int  get(ElementNode const * p_e, int pos);

/**
* \brief scalar product of 2 lists.
* \param 'ElementNode const * p_e1' == a constant pointer to the head of the first vector
* \param 'ElementNode const * p_e2' == a constant pointer to the head of the second vector
* \return The integer product of the scalar / dot product of two given vectors
**/
int scalar_product(ElementNode const * p_e1, ElementNode const * p_e2);

/**
* \brief adds 2 lists as vectors, returns a new list
* \param 'ElementNode const * p_e1' == a constant pointer to the head of the first vector
* \param 'ElementNode const * p_e2' == a constant pointer to the head of the second vector
* \return A pointer to the head of the vector that represents the sum of the two input vectors
**/
ElementNode  * add(ElementNode const * p_e1, ElementNode const * p_e2);

/**
* \brief deallocate a list
* \param 'ElementNode  * p_e' == a pointer to the head of the vector to deallocate
* \return Nothing, simply  deallocates the vector
**/
void free_elements(ElementNode  * p_e);

//int insert_element(ElementNode** e, int i, int j);






/*===============*
* row functions *
*===============*/

/** \brief prints rows as a matrix, adding 0's for non-existing positions (both for non-existing rows and elements), assume the number of rows = dim, assume the length of the vector = dim, doesn't check if the list contains positions beyond dim
* \param 'RowNode const * p_r' == a pointer to the first row of the matrix
* \param char *fmt
* \param 'int dim' == the dimension of the vector and the number of rows in the matrix
* \return Nothing, simply creates the matrix
**/
void printf_rows(RowNode const * p_r, char *fmt, int dim);

/*
* prints all non-zero elements of the list of rows */
void print_rows(RowNode const * p_r);

/*
* inserts a list of elements at position pos.
* If a row at position pos already exists, do not insert, return 2
* If the list p_e is empty, do nothing (don't insert a NULL pointer into p_r)
* returns 1 if malloc fails
* returns 2 if position pos already exists
* returns 0 otherwise */
int insert_row(RowNode  * *p_r, int pos, ElementNode  * p_e);

/* inserts a new element at pos_col
* in the row corresponding to position pos_row
* (pos_row'th row, pos_col'th column)
* uses the same rules as insert_element */
int insert_element2(RowNode  * *pp_r, int pos_row, int pos_col, int val);

/* returns a pointer to a row at position pos if it exists,
* NULL otherwise */
RowNode  * find_row(RowNode  * *pp_r, int pos);

/* transposes a list of rows:
* it's the matrix transposition if you view rows as a matrix
* anyways - if an element in the original RowNode list
* is on row i at position j, then in the transposed
* it is in the row j at position i.
* Notice that it's possible to get empty rows in the transposed
* matrix (for example the following matrix
* [ 1 0 4 ]     [ 1 2 3 ]
* [ 2 0 5 ] ->  [ 0 0 0 ]
* [ 3 0 6 ]     [ 4 5 6 ]
* for full credit the transposed matrix should contain only 2
* rows (positions 0 and 2)
* Returns a new list of rows. Input list p_r should not be modified.*/
RowNode  * transpose(RowNode const * p_r);

/* multiply two lists of RowNodes as matricies.
* Algorithm:
* 1) transpose the second list.
* 2) Now [i,j]'th element of the product matrix
* is the scalar product of i'th row of the first
* and the j'th row of the transposed.
* Returns a new list of rows. Input lists p_r1, p_r2 should not be modified. */
RowNode  * mult(RowNode const * p_r1, RowNode const * p_r2);

/*
* deallocate a list of RowNodes */
void free_rows(RowNode  * p_r);

/*
* Calculates the determinant of the list of RowNodes viewed as a matrix.
* Dimension is required!
* extra credit, discuss algorithm with me first */
int  determinant(RowNode const * p_r, int dim);
#endif
