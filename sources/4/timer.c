/* fisierul timer.c */

#include <time.h>
#include <unistd.h>

clock_t aux;

void starton(void){
	 aux=clock();
	 }

float startoff(void){
	  return(clock()-aux)/2;
     }