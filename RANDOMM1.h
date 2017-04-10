#ifndef H_randomm1
#define H_randomm1

#include "BOY.h"
#include "MISER.h"
#include "GENEROUS.h"
#include "GEEKS.h"
#include "GIRL.h"
#include "DESPERATE.h"
#include "NORMAL.h"
#include "CHOOSY.h"
#include "GIFT.h"

#include<bits/stdc++.h>




char* randomm1 (int *arr1)
{
	int i, p;
	srand((unsigned int)time(NULL));
	FILE* fptr;
      //char words[10][10];
	char **words;
     words = (char **)malloc(20*sizeof(char*));
	for(i=0;i<20;i++)
    {
      words[i]=(char *)malloc((10)*sizeof(char));

    }
	fptr = fopen ("test1.txt","r");
	for(i = 0;fscanf(fptr,"%s",words[i]) && !feof(fptr);i++){}
	
	p = rand()%20;
	while (arr1[p] == 1) {
		p = rand()%20;
	}
	arr1[p] = 1;
	fclose (fptr);
	return words[p];
} 

#endif
