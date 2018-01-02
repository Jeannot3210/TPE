/* -*- c-basic-offset: 3 -*- 
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

/**
 * @author Louis Goupil <louis.goupil@ecole.ensicaen.fr>
 * @version 0.0.1
 */

/**
 * @file TPE.h
 */

#ifndef __TPE_H
#define __TPE_H

#include <image.h>
 
extern void give_moments(image i ,int num_block,int n,int m,int* M0,double* M1,double* M2);

typedef struct RAG* rag;

typedef struct cellule* cellule;

typedef struct moments* moments;

struct moments {
   int MO;
   double M1[3];
   double M2[3];
};

struct cellule {
   int block;
   cellule next;
};

struct RAG {
   image img;
   int nb_blocks;
   long double erreur_partition;
   moments m;
   int* father;
   cellule neighbors;
};

static void init_moments_priv(rag r, int n, int m);

static void init_father_priv(rag r);

static void init_neighbors_priv(rag , int n, int m);

extern rag create_RAG(image i, int n, int m);

#endif
