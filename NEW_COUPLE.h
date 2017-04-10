#ifndef H_new_couple 
#define H_new_couple 

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

void new_couple (FILE* fp) {
	int i,compat;
	double happ;
	char str[10], str1[10];
	GIRL girl;
	BOY boy;
	FILE *fp1;
	cout<<"NEW COUPLES ARE:"<<endl;
	fp1 = fopen ("CSV1.txt","r");
	for (i = 300; i <= 3000 ; ) {
		for (;!feof(fp);) {
			fscanf (fp,"%d %lf %s %s",&compat,&happ,str,str1);
			if (happ < i) {
				
				fscanf(fp1,"%s %d %d %d %s %s",girl.name,&girl.attract,&girl.budget,&girl.int_level,girl.type,girl.status);
				while ( strcmp(str1, girl.name) == 0) {
					fscanf(fp1,"%s %d %d %d %s %s",girl.name,&girl.attract,&girl.budget,&girl.int_level,girl.type,girl.status);
				}
				cout<<str<<" "<<girl.name<<endl;
				//fclose (fp1);
			}
		}
		rewind(fp);
		i = i+1000;
	}
}

#endif
