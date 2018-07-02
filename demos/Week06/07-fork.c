/*
 * (c) 2005-2017 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This is free software.
 * REV06 Wed Nov  1 13:35:19 WIB 2017
 * REV02 Mon Oct 24 10:43:00 WIB 2016
 * REV01 Sun Feb 27 08:31:46 WIB 2011
 * START 2005
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define DISPLAY1 "START * PARENT *** ** PID (%4d) ** **********\n"
#define DISPLAY2 "RANDOM: val1(%4d) -- val2(%4d) -- val3(%4d)\n"
/*************************************************** main ** */
void main(void) {
   pid_t val1, val2, val3;
   printf(DISPLAY1, getpid());
   val1 = fork();
   val2 = fork();
   val3 = fork();
   printf(DISPLAY2, val1, val2, val3);
/* *********** START BLOCK ***
   wait(NULL);
   wait(NULL);
   wait(NULL);
   *********** END * BLOCK *** */
}

/* Sat Jun 23  20:30:36 WIB 2018
 * Notes by MA
 * Pada program ini, hasil fork akan dimasukkan
 * ke dalam variabel val1, val2, dan val3
 *
 * Yang mana,
 * nilai dari fork hanya akan masuk ke parentnya, bukan childnya
 * karena proses child tidak memasukkan nilainya
 * ke variabel dari fork tersebut
 *
 * Lalu, karena tidak ada sleep atau wait,
 * maka setiap proses akan terus berjalan bersamaan
 * Yang nanti pada akhirnya akan terbentuk 8 proses,
 * dan hasil printnya akan random,
 * urutannya akan berbeda-beda setiap program ini berjalan
 */
