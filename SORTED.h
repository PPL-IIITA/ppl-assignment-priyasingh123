#ifndef H_sorted 
#define H_sorted

#include "BOY.h"
#include "MISER.h"
#include "GENEROUS.h"
#include "GEEKS.h"
#include "GIRL.h"
#include "DESPERATE.h"
#include "NORMAL.h"
#include "CHOOSY.h"
#include "GIFT.h"
#include "RANDOMM.h"
#include "RANDOMM1.h"

#include<bits/stdc++.h>

void sorted (FILE *fp, FILE *fp1)
{
	char ch;
	int i, j;
	BOY boy[201];
	GIRL girl[21];
	FILE *fptr, *fptrptr;	
	fptr = fopen ("CSV.txt","r");
	fptrptr = fopen ("CSV1.txt","r");
	for (i = 0; !feof(fptr); i++) {
		fscanf(fptr,"%s %d %d %d %s %s\n",boy[i].name,&boy[i].attract,&boy[i].budget,&boy[i].int_level,boy[i].type,boy[i].status);
	}

	for (i = 0; !feof(fptrptr); i++) {
		fscanf(fptrptr,"%s %d %d %d %s %s\n",girl[i].name,&girl[i].attract,&girl[i].budget,&girl[i].int_level,girl[i].type,girl[i].status);
	}
	fclose (fptr);
	fclose (fptrptr);
	for (i = 0; i < 199; i++) {
		for (j = 0; j < 200-i-1; j++) {
			if (boy[j].attract > boy[j+1].attract) {
				boy[200] = boy[j];
				boy[j] = boy[j+1];
				boy[j+1] = boy[200];
			}
		}
	}
	for (i = 0; i < 200; i++) {
		fprintf(fp,"%s %d %d %d %s %s\n",boy[i].name,boy[i].attract,boy[i].budget,boy[i].int_level,boy[i].type,boy[i].status);
	}
	fptrptr = fopen ("CSV1.txt","r");
	for (i = 0; i < 19; i++) {
		for (j = 0; j < 20-i-1; j++) {
			if (girl[j].attract < girl[j+1].attract) {
				girl[20] = girl[j];
				girl[j] = girl[j+1];
				girl[j+1] = girl[20];
			}
		}
	}
	for (i = 0; i < 20; i++) {
		fprintf(fp1,"%s %d %d %d %s %s\n",girl[i].name,girl[i].attract,girl[i].budget,girl[i].int_level,girl[i].type,girl[i].status);
	}
	fclose (fp);
	fclose (fp1);
	/*int n = 200, i, temp, m = 20, arr[200] = {0,0}, arr1[20] = {0,0}, o = 50, flag = 0, var = -1;
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {
		temp = rand()%3;
		BOY boy;
		strcpy (boy.name, randomm (arr));	
		
		boy.budget = rand ()%1003;
		
		var = rand ()%102;
		while (var < flag) {
			var = rand ()%102;
		}
		boy.attract = var;
		flag = var;
		boy.int_level = rand ()%10;
		strcpy (boy.status, "single");
			
		if (temp == 0) {
			strcpy (boy.type , "miser");
		}
		else if (temp == 1) {
			strcpy (boy.type ,"Generous");
		}
		else {
			strcpy (boy.type , "Geek");
		}
	fprintf(fp,"%s %d %d %d %s %s\n"
,boy.name,boy.attract,boy.budget,boy.int_level,boy.type,boy.status);			
	//fp<<boy.name<<" "<<boy.attract<<" "<<boy.budget<<" "<<boy.int_level<<" "<<boy.type<<" "<<boy.status<<endl;
	
	}
	fclose (fp);


	flag = 105; var = -1;
	for (i = 0; i < m; i++) {
		temp = rand()%3;
		GIRL girl;
		strcpy (girl.name, randomm1 (arr1));	
		girl.budget = rand()%990;
		
		
		var = rand ()%3000;
		
		while (var > flag) {
			var = rand ()%3000;
		}
		girl.attract = var;
		flag = var;
		girl.int_level = rand ()%10;
		strcpy (girl.status, "single");
			
		if (temp == 0) {
			strcpy (girl.type , "desperate");
		}
		else if (temp == 1) {
			strcpy (girl.type ,"choosy");
		}
		else {
			strcpy (girl.type , "normal");
		}
	fprintf(fp1,"%s %d %d %d %s %s\n"
,girl.name,girl.attract,girl.budget,girl.int_level,girl.type,girl.status);			
	//fp<<boy.name<<" "<<boy.attract<<" "<<boy.budget<<" "<<boy.int_level<<" "<<boy.type<<" "<<boy.status<<endl;
	
	}
	fclose (fp1);*/
}

#endif
