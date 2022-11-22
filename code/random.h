#ifndef _RANDOM_H_
#define _RANDOM_H_

/* Random number library */
#define NNN 624
#define MMM 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */
static unsigned long mt[NNN]; /* the array for the state vector  */
static int mti=NNN+1; /* mti==N+1 means mt[N] is not initialized */
/*Funcion declaration*/
void init_genrand(unsigned long s);
void init_by_array(unsigned long init_key[], int key_length);
unsigned long genrand_int32(void);
long genrand_int31(void);
double genrand_real1(void);
double genrand_real2(void);
double genrand_real3(void);
double genrand_res53(void);
/* Random number library */

#endif
