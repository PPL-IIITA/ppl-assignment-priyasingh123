#ifndef H_randomm
#define H_randomm

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


char* randomm (int *arr)
{
	int i, p;
	srand((unsigned int)time(NULL));
	FILE* fptr;
      //char words[10][10];
	char **words;
     words = (char **)malloc(200*sizeof(char*));
	for(i=0;i<200;i++)
    {
      words[i]=(char *)malloc((10)*sizeof(char));

    }
	fptr = fopen ("test.txt","r");
	for(i = 0;fscanf(fptr,"%s",words[i]) && !feof(fptr);i++){}
	
	p = rand()%200;
	while (arr[p] == 1) {
		p = rand()%200;
	}
	arr[p] = 1;
	fclose (fptr);
	return words[p];
}

#endif
