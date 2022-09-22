#ifndef _SIR_H_
#define _SIR_H_

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "rede.h"
#include "random.h"

/* defines */
#define MAXFILES 1000
#define TAM 1000
#define S 0
#define I 1
#define R 2
#define ITER 100
#define ITERM 20
#define E 2.718281828459045

extern int C, r;
extern float K;
extern float pi, PC, PD, PN;
extern float iniI;
extern int iNeigh;

#endif
