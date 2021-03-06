/*
 * Copyright (C) 2015-2018 Rahmat M. Samik-Ibrahim (2016-2)
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV05 Wed Nov  1 19:51:21 WIB 2017
 * REV04 Tue Dec 13 15:19:04 WIB 2016
 * START Wed Sep 30 00:00:00 UTC 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "99-myutils.h"
#define  nSem 7

sem_t	sem[nSem];

void* thread1 (void* a) {
   sem_wait   (&sem[1]);
   printf("T1X\n");
   sem_post   (&sem[4]);
}

void* thread2 (void* a) {
   sem_wait   (&sem[2]);
   printf("T2X\n");
   sem_post   (&sem[5]);
   sem_post   (&sem[1]);
}

void* thread3 (void* a) {
   printf("T3X\n");
   sem_post   (&sem[6]);
   sem_post   (&sem[2]);
}

void* thread4 (void* a) {
   sem_wait   (&sem[4]);
   printf("T44\n");
   sem_wait   (&sem[5]);
   printf("T45\n");
   sem_wait   (&sem[6]);
   printf("T46\n");
}

void main(void) {
   printf("MAIN\n");
   for (int ii=1;ii<nSem;ii++)
      sem_init(&sem[ii], 0, 0);
   daftar_trit   (thread1);
   daftar_trit   (thread2);
   daftar_trit   (thread3);
   daftar_trit   (thread4);
   jalankan_trit ();
   beberes_trit  ("TREXIT");
}

/* Mon Jun 25 23:00:10 WIB 2018
 * Notes by Muhammad Iqbal Mahendra
 *
 * Pada awal program, didefine nSem adalah 7.
 * Kemudian, program men-declare sebuah mutex bernama sem 
 * dengan panjang 7.
 *
 * Pada fungsi main, terdapat for loop di mana sem_init akan 
 * menginisiasi sebanyak 7 elemen di mutex sem dengan nilai 0.
 *
 * Jika program bertemu dengan sem_post, maka nilai dari elemen 
 * tersebut akan bertambah 1.
 * Jika program bertemu dengan sem_wait, check apakah elemennya 
 * bernilai 0. Jika bernilai 0, maka program akan menunda proses 
 * hingga elemen tersebut bernilai 1.
 *
 * Pada thread1, terdapat sem_wait untuk sem[1]. 
 * Karena sem[1] bernilai 0, maka program akan menunda proses pada 
 * line di bawahnya. Baris kode di bawahnya akan dijalankan ketika 
 * sem[1] sudah tidak bernilai 0, yaitu ketika program bertemu dengan 
 * sem_post(sem[1]). Pada thread-thread lainnya pun akan menjalankan 
 * hal yang sama ketika terdapat sem_wait dan sem_post
 *
 */
