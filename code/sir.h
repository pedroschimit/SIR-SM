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
