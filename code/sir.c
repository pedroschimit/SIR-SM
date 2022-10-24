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

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "sir.h"
#include "rede.h"
#include "random.h"


int estado[SIDE][SIDE];
int temp[SIDE][SIDE];

FILE *fresult;

int C, r;
float K;
float pi, PC, PD, PN;
float iniI;
int iNeigh;

void parseArgs( int qtde, char **args ); 
void loadinfo(char *buffer, char *folder);
 
int main(int argc, char *argv[])
 {

   int i, j, k, c;
   int iTAM;
   int it; 
   
   int ds, di, dr;
   int dsi, dir, dis, drs;
   
   float db, dc, de, dR0;
   double da;

   float p1;
   float p2;
   
   int nI, x, y;

   char fileepid[512], filefolder[256];
   
   iNeigh = NEIGH_SM;
   C=8;
   r=48;
   K=1.1;
   PC=(float)1/(float)14;
   PD=0.01;
   PN=(float)1/((float)365*(float)78);
   iniI = 0.005;
   
   srand (time(NULL)); 
   init_genrand(rand());

   parseArgs(argc, argv );
   
   rede(SIDE,C,r,NEIGH_SM);
   if(iNeigh==NEIGH_MOORE){
		C=8;
		r=1;
	}else if(iNeigh==NEIGH_VONNE){
		C=4;
		r=1;
	}

   for(i=0;i<SIDE;i++)
   	for(j=0;j<SIDE;j++)
      	estado[i][j]=S;

   for(k=0;k<SIDE*SIDE*iniI;){
    	i=rand()%SIDE;
      j=rand()%SIDE;
      if(estado[i][j]==S){
         estado[i][j]=I;
         k++;
      }
	}
	
	loadinfo("data.ini", filefolder);
	
	for(i=0;i<MAXFILES;i++){
		sprintf(fileepid, "%sSIR-SM_SIM_%04d.csv", filefolder, i);
	   fresult = fopen (fileepid, "r");
	   if (fresult!=NULL){
	   	fclose (fresult);
	   }else break;
	}

   fresult = fopen(fileepid, "w");
   fprintf(fresult, "S;I;R;S->I;I->R;I->S;R->S;a;b;c;e;R0\n");

   for(it=0;it<ITER;it++){
    	for(i=0;i<SIDE;i++)
      	for(j=0;j<SIDE;j++)
				temp[i][j] = estado[i][j];
    	
      printf("%d\n", it);
      ds=0; di=0; dr=0;
      dsi=0; dir=0; dis=0; drs=0;
      for(i=0;i<SIDE;i++){
      	for(j=0;j<SIDE;j++){
	       	nI=0;
	         if(estado[i][j]==S){
	            ds++;
	            
	            for(c=0;c<C;c++){
	
						return_pos(i, j, &x, &y);
	               
	               if(estado[x][y]==I) nI++;
	               
	            }
	            
	            pi=1-pow(E, -(float)nI*K);
	            p1=genrand_real1();
	            if(p1<pi)
	             {
	               temp[i][j] = I;
	               dsi++;
	             }
	            else
	             {
	               temp[i][j] = S;
	             }
	          }
	         else if(estado[i][j]==I)
	          {
	            di++;
	            p1=genrand_real1();
	            p2=genrand_real1();
	            temp[i][j]=I;
	            if(p1<PC)
	             {
	               temp[i][j]=R;
	               dir++;
	             }
	            else if(p2<PD)
	             {
	               temp[i][j]=S;
	               dis++;
	             }
	          }
	         else if(estado[i][j]==R){
	            dr++;
	            p1=genrand_real1();
	            if(p1<PN){
	               temp[i][j] = S;
	               drs++;
	            }
	            else{
	               temp[i][j] = R;
	            }
	         }
	      }
	   }
      
      
	   if (di && ds)
	   	da = (double)dsi/((double)(di) * (double)(ds));
	   else
	   	da = 0;
	   	
	   if (di)
	  		db = (float)dir/(float)di;
		else
	   	db = 0;
	    
	  if (di)
	   	dc = (float)dis/(float)di;
	   else
	   	dc = 0;
	     
	   if(drs) 
			de = (float)drs/(float)dr;
	   else 
			de = 0;
		  
	   if (db + dc > 0)
			dR0 = (float)(da*(double)SIDE*(double)SIDE/(double)(db + dc));
	  else
			dR0 = 0;
		  
	   fprintf(fresult, "%d;%d;%d;%d;%d;%d;%d;"
							  "%g;%f;%f;%f;%f\n", 
							  ds,di,dr,dsi,dir,dis,drs,
							  da, db, dc, de, dR0);
																				 
		for(i=0;i<SIDE;i++)
			for(j=0;j<SIDE;j++)
				estado[i][j] = temp[i][j];
   }
   
   fprintf(fresult, "Parameters;\n");
   fprintf(fresult, "SIDE;%d\n", SIDE);
   fprintf(fresult, "ITER;%d\n", ITER);
   fprintf(fresult, "C;%d\n", C);
   fprintf(fresult, "r;%d\n", r);
   fprintf(fresult, "K;%f\n", K);
   fprintf(fresult, "PC;%f\n", PC);
   fprintf(fresult, "PD;%f\n", PD);
   fprintf(fresult, "PN;%f\n", PN);
   fprintf(fresult, "iniI;%f\n", iniI);
   fprintf(fresult, "iNeigh;%d\n", iNeigh);
   fclose(fresult);
   
   return 0;
 }
 
void parseArgs(int qtde, char **args )
{
	int c;
	
	for( c = 0; c < qtde; c++ ){
		if( !(strcmp( *(args+c), "--PC" ) ) ){
			PC = atof(*(args + ++c));
		} 
		else if( !(strcmp( *(args+c), "--PD" ) ) ){
			PD = atof(*(args + ++c));
		} 
		else if( !(strcmp( *(args+c), "--PN" ) ) ){
			PN = atof(*(args + ++c));
		}
		else if( !(strcmp( *(args+c), "--K" ) ) ){
			K = atof(*(args + ++c));
		}
		else if( !(strcmp( *(args+c), "--C" ) ) ){
			C = atoi(*(args + ++c));	
		}
		else if( !(strcmp( *(args+c), "--R" ) ) ){
			r = atoi(*(args + ++c));
		}
		else if( !(strcmp( *(args+c), "--INII" ) ) ){
			iniI = atof(*(args + ++c));
		}

	}
}

void loadinfo(char *buffer, char *folder){

   FILE *fp;

   fp=fopen(buffer,"r");
   if(fp==NULL) printf("\nError opening the file");
   fscanf(fp,"\nresultfolder=%s\n",folder);

}
