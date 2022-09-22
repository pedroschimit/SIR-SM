/* 
A C-program for a SIR model based on probabilistic cellular automata. Coded by Pedro Schimit.
Partially used on Schimit, P. H. T.; Monteiro, L.H.A. . On the basic reproduction number and the topological properties of the contact network: An epidemiological study in mainly locally connected cellular automata. Ecological Modelling, p. 1034-1042, 2009.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above text, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above text, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. The name of the contributor may not be used to endorse or promote products derived from this software without specific prior written permission.

This content is licensed under Creative Commons Attribution-ShareAlike 4.0 Internacional.

Any feedback is very welcome.
email: schimit @ gmail . com ; schimit @ alumni . usp . br (remove space)
*/

#include "rede.h"
#include "random.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

int redeC;
int reder;
int redeiNeigh;
int redeside;

int count = 0;

//int pos[RMAX+1][8*(RMAX+1)][2];
int *pos;

int abs(int i);
int offset(int x, int y, int z);

void rede(int side, int C, int r, int iNeigh){
	
	int x, y, cam, k;
	
	redeside=side;
	redeC=C;
	reder=r;
	redeiNeigh=iNeigh;
	count=0;
	
	if(iNeigh==NEIGH_SM){
		pos = (int *) malloc(((reder+1)*8*(reder+1)*2)*sizeof(int));
	}
	else if(iNeigh==NEIGH_MOORE){
		redeC=8;
		reder=1;
	}else if(iNeigh==NEIGH_VONNE){
		redeC=4;
		reder=1;
	}
	
	init_genrand(time(NULL));
	
	k=0;
	for(cam=1;cam<reder+1;cam++){
		for(x=-cam;x<=cam;x++){
			for(y=-cam;y<=cam;y++){
				if(x==cam || y==cam || x==-cam || y==-cam){
					pos[offset(abs(cam), k, 0)] = x;
					pos[offset(abs(cam), k, 1)] = y;
					k++;
				}
			}
		}
		k=0;
	}
	
}

void return_pos(int i, int j, int *x, int *y){
	
	int tempi, tempj, k;
	float p1, temp;
	int p, cam, somacel;
		
	if (redeiNeigh==NEIGH_SM){
		somacel = (2*reder+1)*(2*reder+1)-1;
		p1 = genrand_real2();
		temp=0;
		for(k=0;k<reder;k++){
			temp+=(float)(8*(reder-k))/(float)(somacel);
			if (p1 < temp) break;
		}
		cam=k+1;
				
		p=genrand_int32()%(8*cam);
		tempi = pos[offset(abs(cam), p, 0)];
		tempj = pos[offset(abs(cam), p, 1)];
		
	   *x = i+tempi;
	   *y = j+tempj;
	   
	}else if(redeiNeigh==NEIGH_MOORE){
		if(count==0){
			*x=i-1;
			*y=j-1;
		}else if(count==1){
			*x=i-1;
			*y=j;
		}else if(count==2){
			*x=i-1;
			*y=j+1;
		}else if(count==3){
			*x=i;
			*y=i-1;
		}else if(count==4){
			*x=i;
			*y=j+1;
		}else if(count==5){
			*x=i+1;
			*y=j-1;
		}else if(count==6){
			*y=j;
			*x=i+1;
		}else if(count==7){
			*x=i+1;
			*y=j+1;
		}
		count++;
		if(count==redeC) count = 0;
	}else if(redeiNeigh==NEIGH_VONNE){
		if(count==0){
			*x=i-1;
			*y=j;
		}else if(count==1){
			*x=i;
			*y=j-1;
		}else if(count==2){
			*x=i;
			*y=j+1;
		}else if(count==3){
			*x=i+1;
			*y=j;
		}
		count++;
		if(count==redeC) count = 0;
	}
	
   if (*x < 0) *x = redeside + *x;
   if (*y < 0) *y = redeside + *y;
   if (*x >= redeside) *x = *x - redeside;
   if (*y >= redeside) *y = *y - redeside;
   
}


int abs(int i){
	if(i<0) return -i;
	else return i;
}

int offset(int x, int y, int z) { 
    return (z * (reder+1) * (8*(reder+1))) + (y * (reder+1)) + x; 
}
