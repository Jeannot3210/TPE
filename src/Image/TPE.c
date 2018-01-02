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
 * @author Alan lutsen <alan.lutsen@ecole.ensicaen.fr>
 * @version 0.0.1
 */

/**
 * @file give_moment.c
 */

#include <stdio.h>
#include "../../include/TPE.h"

extern void give_moments(image i, int num_block, int n, int m, int* M0, double* M1, double* M2) {

   int H;
   int L;
   int k;
   int j;
   int l;
   unsigned char intens_pixel[3];

   H = image_give_hauteur(i);
   L = image_give_largeur(i);

   *M0 = (L/n)*(H/m);

   for (k=0; k<(L/n); k++) {
      for (j= 0; j<(H/m); j++) {
	    
	 image_read_pixel(i, H/n*((num_block-1)/m)+k, L/m*((num_block-1)%m)+j, intens_pixel);
	 for (l = 0; l < image_give_dim(i); l++) {
	    *(M1+l) += (double)*(intens_pixel+l);
	    *(M2+l) += ((double)*(intens_pixel+l))* ((double)*(intens_pixel+l));
	 }
      }
   }
}

static void init_moments_priv(rag r, int n, int m){
}

static void init_father_priv(rag r){
}

static void init_neighbors_priv(rag , int n, int m){
}

static void init_partition_error_priv(rag r){
}

extern rag create_RAG(image i, int n, int m) {
   rag r;
   
   r.img = i;
   r.nb_blocks = n*m;
   init_moments_priv(r, n, m);
   init_father_priv(r);
   init_neighbors_priv(r, n, m);
   init_partition_error_priv(r);

   return r;
}
