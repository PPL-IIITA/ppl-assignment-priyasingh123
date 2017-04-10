#ifndef H_find_gf 
#define H_find_gf
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


void find_gf (FILE *fp) 
{
	int compat, size = 0, i;
	double happ;
	struct couple array[30];
	BOY boy;
	GIRL girl;
	for (; !feof(fp);) {
		fscanf(fp,"%d %lf %s %s",&compat,&happ,boy.name,girl.name);
		strcpy(array[size].name1, boy.name);
		strcpy(array[size].name2, girl.name);
		array[size].comp = compat;
		size++;
	}
	
	FILE *fp1;
	fp1 = fopen ("boys.txt","r");
	char boyy[10];
	int compatibility;
	
	for (; !feof(fp1); ) {
		//cout<<"heelo"<<endl;
		fscanf(fp1,"%d %s",&compatibility,boyy);
		for (i = 0; i < size; i++) {
		//	cout<<boyy<<" "<<array[i].name1<<endl;
			if (!strcmp(boyy, array[i].name1)) {
				cout<<boyy<<" "<<array[i].name2<<endl;
				break;
			}
		}
	}	
	fclose(fp1);
}
#endif
