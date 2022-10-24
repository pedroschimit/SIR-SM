#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "rede.h"
#include "random.h"


int redeC;
int reder;
int redeiNeigh;
int redeside;

int count = 0;

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
		
	}
	else if(iNeigh==NEIGH_MOORE){
		redeC=8;
		reder=1;
	}else if(iNeigh==NEIGH_VONNE){
		redeC=4;
		reder=1;
	}
	
	init_genrand(time(NULL));
	
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
		
		k=p/(2*cam);
		k=k*(2*cam);
				
		if(k==0){
			tempi=-cam+(p%(2*cam));
			tempj=-cam;
		}else if(k==2*cam){
			tempi=cam;
			tempj=-cam+(p%(2*cam));
		}else if(k==4*cam){
			tempi=cam-(p%(2*cam));
			tempj=cam;
		}else if(k==6*cam){
			tempi=-cam;
			tempj=cam-(p%(2*cam));
		}
		
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
