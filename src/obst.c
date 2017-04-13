/*! \file obst.c
 *  \brief     This implements the optimal binary search tree program.
 *  \author    BIN MOHMAD SHAH hariz
 *  \author    PRADA MEIJA Robinson
 *  \version   1.0
 *  \date      13/4/2017 
 *  \copyright Hariz&Robinson.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include "obst.h"

int **costs; /*!< Array for stock all possible cost optimals */
int **weights;  /*!< Array for stock all possible weights sum */
int **roots; /*!< Array for stock all possible roots combination */
int *p; /*!< Array for stock the frequency for each element */
int *keys; /*!< Array for the roots */

/**
 * \brief creation of binary search tree root function
 * \param i the starting root
 * \param j the ending root
 * \return { new OBST type(root) if succeeds; null otherwise }
 */
OBST *create_obst(int i, int j) {

	OBST *p;
	if(i == j)
		p = NULL;

	else {
		p = malloc(sizeof(*p));
		p->key = roots[i][j];	
		p->left = create_obst(i, roots[i][j] - 1); 
		p->right = create_obst(roots[i][j], j); 
	}

	return p;

}

/**
 * \brief print on stdout of binary search tree function
 * \param *tree pointer to binary search tree (type OBST)
 * \param node root of the tree
 */
void print_tree(OBST *tree, int node) {

	if(tree == NULL || !node) {
		printf("Error");
	}
	else {
		OBST *current = malloc(sizeof(*current));
		current = tree;
		
		while(current->key != node) {
			if(current->key > node) 
				current = current->left;
			else 
				current = current->right;
		}

		printf("{");
		if(current->left == NULL) 
			printf("-1,");
		else {
			printf("%d,",keys[current->left->key]);
		}
		
		if(current->right == NULL) 
			printf(" -1");
		else {
			printf(" %d",keys[current->right->key]);
		}
		printf("}");		
	}
	
}

/**
 * \brief create all the possible weight matrices of binary search function
 * \param n the number of element in the dictionary
 */
void create_matrices(int n){

	int x, min;
	int i, j, k, h, m;

	for(i = 0; i <= n; i++) {	
		for(j = i + 1; j <= n; j++) {
			weights[i][j] = weights[i][j-1] + p[j];
		}
	}

	for(i = 0; i <= n; i++){
		costs[i][i] = weights[i][i];
	}
		
	for(i = 0; i <= n - 1; i++) {
		j = i + 1;
		costs[i][j] = costs[i][i] + costs[j][j] + weights[i][j];
		roots[i][j] = j;
	}

	for(h = 2; h <= n; h++) {
		for(i = 0; i <= n - h; i++) {
			j = i + h;
			m = roots[i][j-1];
			min = costs[i][m-1] + costs[m][j];
			for(k = m+1; k <= roots[i+1][j]; k++){	
				x = costs[i][k-1] + costs[k][j];
				if(x < min) {
					m = k;
					min = x;
				}
			}
			costs[i][j] = weights[i][j] + min;
			roots[i][j] = m;
		}
	}
}

/**
 * allocation memory 
 * \brief allocate memory for all global variable function
 * \param n the number of element in the dictionary
 * \param *freqFile the file which contains the frequency for each element
 */
void init_all(int n, FILE *freqFile) {

	costs = malloc((n+1)*sizeof(int*));
	weights = malloc((n+1)*sizeof(int*));
	roots = malloc((n+1)*sizeof(int*));
	p = malloc((n+1)*sizeof(int));
	keys = malloc((n+1)*sizeof(int)); 

	for(int i=1;i<=n;i++){   
		fscanf(freqFile,"%d", p+i);
		keys[i] = i-1;
	}

	for (int i=0; i<=n; i++){
		costs[i] = (int*) malloc((n+1)*sizeof(double));
		weights[i] = (int*) malloc((n+1)*sizeof(int));
		roots[i] = (int*) malloc((n+1)*sizeof(int));
	}

}

/**
 * \brief print on stdout the code c correspondant to benchmarks function
 * \param n the number of element in the dictionary
 */
void print_all(int n){
	printf("static long BSTdepth = %d; // pour info. Non demandé\n",costs[0][n]);
	printf("static int BSTroot = %d;\n",keys[roots[0][n]]);
	OBST *mytree = create_obst(0,n);
	printf("static int BSTtree[%d][2] = {\n",n);
	for(int i = 1 ; i <= n ; i++) {
		print_tree(mytree,i);
		if(i != n) 
			printf(", \n");
	}
	printf(" };\n");

	printf("static int opt =%i;\n",costs[0][n]);
	printf("static int p[%i] = {\n",n);
	for(int i = 1 ; i <= n ; i++) {
		printf("%i", p[i]);
		if(i != n) 
			printf(", \n");
	}
	printf("};\n");

}

/**
 * print on stdout the value of each double pointer variable use for debug
 * \param **matrix the double pointer variable
 * \pqrqm n the number of element in the dictionary
 */
void print_matrix(int **matrix, int n){
	for(int i = 0; i <= n; i++){
		for(int j = i; j <= n; j++)
			printf("%i ", matrix[i][j]); printf("\n");
	}

}






