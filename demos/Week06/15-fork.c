/*
 * (c) 2016-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV03 Wed Nov  1 14:00:40 WIB 2017
 * START Sun Dec 04 00:00:00 WIB 2016
 * wait()     =  suspends until its child terminates. 
 * fflush()   =  flushes the user-space buffers.
 * getppid()  =  get parent PID
 * ASSUME pid >= 1000 && pid > ppid **
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define  NN 2

void main (void) {
   int ii, rPID, rPPID, id1000=getpid();
   for (ii=1; ii<=NN; ii++) {
      fork();
      wait(NULL);
      rPID = getpid()-id1000+1000; /* "relative" */
      rPPID=getppid()-id1000+1000; /* "relative" */
      if (rPPID < 1000 || rPPID > rPID) rPPID=999;
      printf("Loop [%d] - rPID[%d] - rPPID[%4d]\n", ii, rPID, rPPID);
      fflush(NULL);
   }
}

/* Sat Jun 23 21:48:17 WIB 2018
 * Notes by MA
 * Fork dilakukan di DALAM for, yang berarti childnya 
 * akan mempunyai nilai ii sendiri dan begitu pula parentnya
 * 
 * Oleh karena itu, 
 * akan terdapat banyak child yang dia akan ikut looping juga
 */
