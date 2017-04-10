#ifndef H_find_gf2
#define H_find_gf2
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
#include "STRUCTCOUPLE.h"
using namespace std;
void find_gf2 (FILE *fp) 
{
	int compat, size = 0, i;
	double happ;
	struct couple array[1000];
	char name[10], NAME[10];
	for (; !feof(fp);) {
		fscanf(fp,"%d %lf %s %s",&compat,&happ,name,NAME);
		strcpy(array[size].name1, name);
		strcpy(array[size].name2, NAME);
		array[size].comp = compat;
		size = size+1;
		
	}
	
	FILE *fp1;
	fp1 = fopen ("boys.txt","r");
	char boyy[10];
	int compatibility;
	
	for (; !feof(fp1); ) {
		
		fscanf(fp1,"%d %s",&compatibility,boyy);
		//cout<<"heelo"<<endl;
		for (i = 0; i < size; i++) {
			if (!strcmp(array[i].name1, boyy)) {
				//cout<<"hello"<<endl;
				cout<<boyy<<" "<<array[i].name2<<endl;
			}
		}
	}	
	fclose(fp1);
}
#endif
