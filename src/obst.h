#ifndef OBST_H_INCLUDED
#define OBST_H_INCLUDED

typedef struct OBST OBST;
struct OBST {
    int key;
    OBST *left, *right;
};

OBST *create_obst(int i, int j);
void print_test_tree(int i, int j);
void print_tree(OBST *tree, int node);
void create_matrices(int n);
void init_all(int n, FILE *freqFile);
void print_all(int n);
void print_matrix(int **matrix, int n);

#endif

