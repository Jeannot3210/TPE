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
#include "image.h"

extern void give_moments(image i ,int num_block,int n,int m,int* M0,double* M1,double* M2) {

   int H;
   int L;
   int k;
   int j;
   unsigned char* intens_pixel;
   
   if (image_move_to(i,num_block) == True) {
      H = image_give_hauteur(i);
      L = image_give_largeur(i);

      *M0 = (L/n)*(H/m);

      for (k=0; k<(L/n);k++) {
	 for (j= 0; j<(H/m); j++) {
	    
	    image_read_pixel(i,k,j,intens_pixel);
	    *M1 += *intens_pixel;
	    *M2 += ((double)*intens_pixel)* ((double)*intens_pixel);

	 }
      }
   }
}
	       
	      
      
	 
	 
