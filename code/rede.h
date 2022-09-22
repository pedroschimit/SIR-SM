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
#define _REDE_H_

/* REDE */

#define NEIGH_MOORE		0
#define NEIGH_VONNE		1
#define NEIGH_SM			2

void rede();
void return_pos(int i, int j, int *x, int *y);

#endif
