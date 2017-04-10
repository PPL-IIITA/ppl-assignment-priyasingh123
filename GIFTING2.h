#ifndef H_gifting2
#define H_gifting2

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
void gifting2(FILE* fp)
{
	BOY boy;
	GIRL girl;
	GIFT gift;
	int left, compat;
	char str[10];
	char str1[10];
	double happ;
	FILE *fp1, *fp2, *fp3;
	for (; !feof(fp);) {
		fscanf (fp,"%d %lf %s %s",&compat,&happ,str,str1);
		//cout<<"boy"<<" "<<str<<endl;
		fp1 = fopen ("CSV.txt","r");
		for (; !feof(fp1);) {
			fscanf(fp1,"%s %d %d %d %s %s\n",boy.name,&boy.attract,&boy.budget,&boy.int_level,boy.type,boy.status);
		//	cout<<boy.name<<endl;
			if (!strcmp (str,boy.name)) {
		//		cout<<"hell"<<endl;
				fclose(fp1);
				break;
				
			}
		}

		fp3 = fopen ("CSV1.txt","r");
		for (; !feof(fp3);) {
			fscanf(fp3,"%s %d %d %d %s %s\n",girl.name,&girl.attract,&girl.budget,&girl.int_level,girl.type,girl.status);
		//	cout<<boy.name<<endl;
			if (!strcmp (str1,girl.name)) {
		//		cout<<"hell"<<endl;
				fclose(fp3);
				break;
				
			}
		}
		//cout<<str<<" "<<boy.name<<endl;
		int budget = boy.budget;
		int total = 0;
		int total1 = 0;
		while (!feof(fp2) && total <= girl.budget ) {
			fscanf(fp2,"%d %d %s",&gift.price,&gift.value,gift.type);
			if (gift.price < budget) {
				total = total+gift.price;
				total1 = total1+gift.value;
				budget = budget-gift.price;
			}			
		}
		
		if (strcmp ("choosy",girl.type) == 0) {
			girl.happ  = log(total+(2*total1));
			if (strcmp ("miser",boy.type) == 0) {
				boy.happ = budget;
			}
			else if (strcmp ("Generous", boy.type) == 0) {
				boy.happ = girl.happ;
			}
			else if (strcmp ("Geeks", boy.type) == 0) {
				boy.happ = girl.int_level;
			}
			happ = boy.happ+girl.happ;
			compat = abs (girl.int_level - boy.int_level) + abs (girl.attract - boy.attract)+abs(boy.budget-girl.budget);
			cout<<compat<<" "<<happ<<" "<<boy.name<<" "<<girl.name<<endl;	
			
		}
		else if (strcmp ("normal",girl.type) == 0) {
			girl.happ = total+total1;
			if (strcmp ("miser",boy.type) == 0) {
				boy.happ = budget;
			}
			else if (strcmp ("Generous", boy.type) == 0) {
				boy.happ = girl.happ;
			}
			else if (strcmp ("Geeks", boy.type) == 0) {
				boy.happ = girl.int_level;
			}
			happ = boy.happ+girl.happ;
			compat = abs (girl.int_level - boy.int_level) + abs (girl.attract - boy.attract)+abs(boy.budget-girl.budget);
			cout<<compat<<" "<<happ<<" "<<boy.name<<" "<<girl.name<<endl;
		}
		else if (strcmp ("desperate",girl.type) == 0) {
			girl.happ = exp (total);
			if (strcmp ("miser",boy.type) == 0) {
				boy.happ = budget;
			}
			else if (strcmp ("Generous", boy.type) == 0) {
				boy.happ = girl.happ;
			}
			else if (strcmp ("Geeks", boy.type) == 0) {
				boy.happ = girl.int_level;
			}
			happ = boy.happ+girl.happ;
			compat = abs (girl.int_level - boy.int_level) + abs (girl.attract - boy.attract) + abs(boy.budget-girl.budget);
			cout<<compat<<" "<<happ<<" "<<boy.name<<" "<<girl.name<<endl;
			
		}
	}		
}

#endif
