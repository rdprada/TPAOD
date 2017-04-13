/*! \file obst.h
 *  \brief     This is library for the optimal binary search tree program.
 *  \author    BIN MOHMAD SHAH hariz
 *  \author    PRADA MEIJA Robinson
 *  \version   1.0
 *  \date      13/4/2017 
 *  \copyright Hariz&Robinson.
 */

#ifndef OBST_H_INCLUDED
#define OBST_H_INCLUDED

typedef struct OBST OBST;
struct OBST {
  int key; /*!< the parent root */
  OBST *left;  /*!< the child root (left) */
  OBST *right;/*!< the child root (right) */
};


OBST *create_obst(int i, int j);
void print_test_tree(int i, int j);
void print_tree(OBST *tree, int node);
void create_matrices(int n);
void init_all(int n, FILE *freqFile);
void print_all(int n);
void print_matrix(int **matrix, int n);

#endif

