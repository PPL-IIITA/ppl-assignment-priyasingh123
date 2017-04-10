#ifndef H_breakup 
#define H_breakup

#include <bits/stdc++.h>

#include "BOY.h"
#include "MISER.h"
#include "GENEROUS.h"
#include "GEEKS.h"
#include "GIRL.h"
#include "DESPERATE.h"
#include "NORMAL.h"
#include "CHOOSY.h"
#include "GIFT.h"

using namespace std;

void breakup (FILE *fp )
{
	FILE * fp1, *fp2, *fp3;
	BOY boy;
	GIRL girl;
	GIFT gift;
	
	int compat;
	char girls[10];
	char boys[10]; 
	double happ;
	fp1 = fopen ("CSV.txt","r");
	for (;!feof(fp);) {
		fscanf(fp,"%lf %s %s",&happ,boys,girls);
		
		fp2 = fopen ("CSV1.txt","r");
		for (; !feof (fp2); ) {
			fscanf(fp2,"%s %d %d %d %s %s",girl.name,&girl.attract,&girl.budget,&girl.int_level,girl.type,girl.status);
			if (!strcmp(girl.name,girls)) {
				
				break;
			}
		}
		fclose (fp2);
		
		for (; !feof (fp1); ) {
			fscanf(fp1,"%s %d %d %d %s %s",boy.name,&boy.attract,&boy.budget,&boy.int_level,boy.type,boy.status);
			if (strcmp (boy.name, boys)) {
				if (girl.budget < boy.budget && girl.attract > boy.attract) {
					printf("%s %s\n",boy.name,girl.name);
					break;
				}
			}
		}
		
	}
}
#endif




