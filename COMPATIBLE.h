#ifndef H_compatible 
#define H_compatible

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

void compatible (FILE *fp, FILE *fp1, FILE *fp2)
{
	BOY boy;
	GIRL girl;
	GIFT gift;
	srand ((unsigned int) time (NULL));
	ofstream boys;
	boys.open("boys.txt");
	int  n = 0, m = 0, j, w = 0, t, arr[200] = {0,0}, arr1[20] = {0,0}, i, temp, flag, compat;
	/* making couples by checking that girl's maintenance cost should be less than boy's budget and that girl should meet the minimum level of attraction */
	while (m < 20) {

		fscanf(fp1,"%s %d %d %d %s %s",girl.name,&girl.attract,&girl.budget,&girl.int_level,girl.type,girl.status);

		while (n < 200) {	
			fscanf(fp,"%s %d %d %d %s %s",boy.name,&boy.attract,&boy.budget,&boy.int_level,boy.type,boy.status);
			if (rand() %5 == 0) {
				boys<<rand()%70<<" "<<boy.name<<endl;
			}
			if (arr1[m] == 0 && arr[n] == 0) {
				if (girl.budget > boy.budget) {
					n = n+1;
				}
				else if (girl.attract < boy.attract) {
					n = n+1;
				}
				else {
					cout<<boy.name<<" and "<<girl.name<<endl;
					w = w+1;
					arr1[m] = w;
					arr[n] = w;
					n = n+1;
					break;
					
				}
			}
			else if (arr[n] == 1) {
				n = n+1;
			}
		}
		m = m+1;
	}
	FILE *fp4;
	ofstream myfile4;
	myfile4.open("CSV4.txt");
	for (t = 1; t <= w; t++) {
		for ( i = 0; i < 20; i++) {
			if (arr1[i] == t) {
				temp = i;
				break;
			}

		}	
		for (i = 0; i < 200; i++) {
			if (arr[i] == t) {
				flag = i;
				break;
			}
		}
		rewind (fp);
		rewind (fp1);
		rewind (fp2);
		/* calculating and storing couple's compatibility , happiness, and names in another file */
		while (temp >= 0) {
			fscanf(fp1,"%s %d %d %d %s %s",girl.name,&girl.attract,&girl.budget,&girl.int_level,girl.type,girl.status);
			temp = temp-1;
		}
		while (flag >= 0) {
			fscanf(fp,"%s %d %d %d %s %s\n",boy.name,&boy.attract,&boy.budget,&boy.int_level,boy.type,boy.status);
			flag = flag-1;
	
		}
		double girl_happ, boy_happ; 
		
		compat = abs (girl.int_level - boy.int_level) + abs (girl.attract - boy.attract)+abs(boy.budget-girl.budget);
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
		if (girl.type == "choosy") {
			CHOOSY girll;
			girl_happ = girll.cal_happ (total, total1);
		}
		else if (girl.type == "normal") {
			NORMAL girll;
			girl_happ = girll.cal_happ (total, total1);
		}
		else  {
			DESPERATE girll;
			girl_happ = girll.cal_happ (total, total1);
		}
		if (boy.type == "miser") {
			MISER boyy;
			boy_happ = boyy.cal_happ (girl_happ);
		}
		else if (boy.type == "Generous") {
			GENEROUS boyy;
			boy_happ = boyy.cal_happ (girl_happ);
		}
		else {
			GEEKS boyy;
			boy_happ = boyy.cal_happ (girl_happ);
		}
		
		myfile4<<compat<<" "<<boy_happ+girl_happ<<" "<<boy.name<<" "<<girl.name<<endl;	

		if (rand() % 5 == 0) {
			boys<<compat<<" "<<boy.name<<endl;	
		}	
		
	}
	double happ;
	int check[20] = {0,0};
	char str[10];
	char str1[10];
	fp4 = fopen ("CSV4.txt","r");
	/* finding top five happy couples and storing in k_happy.txt*/
	ofstream myfile5;
	myfile5.open("k_happy.txt");
	cout<<"TOP FIVE HAPPIEST COUPLES ARE :"<<endl;
	for (int var = 0; var < 5; var++) {
		//fp4 = fopen ("CSV4.txt","r");
		double maxx = 0.0;
		int h = 0;
	
		for (i = 0; i < 10; i++) {
			fscanf (fp4,"%d %lf %s %s",&compat,&happ,str,str1);
			if (maxx < happ && check[i] == 0) {
				maxx = happ;
				h = i;
				
			}
			
		}
		check[h] = 1;
		rewind (fp4);
		
			while (h >= 0) {
				fscanf (fp4,"%d %lf %s %s",&compat,&happ,str,str1);
				h = h-1;
			}	
		cout<<happ<<" "<<str<<" "<<str1<<endl;/* printing top five happy couples onto the screen*/
		myfile5<<happ<<" "<<str<<" "<<str1<<endl;		
		
	}
	

	
	int check1[10] = {0,0};
	cout<<"TOP FIVE COMPATIBLE COUPLES ARE :"<<endl;
	for (int var = 0; var < 5; var++) {
		rewind(fp4);
		double maxx = 0.0;
		int h = 0;
	
		for (i = 0; i < 10; i++) {
			fscanf (fp4,"%d %lf %s %s",&compat,&happ,str,str1);
			if (maxx < compat && check1[i] == 0) {
				maxx = compat;
				h = i;
				
			}
			
		}
		check1[h] = 1;
		fclose (fp4);
		fp4 = fopen ("CSV4.txt","r");
			while (h >= 0) {
				fscanf (fp4,"%d %lf %s %s",&compat,&happ,str,str1);
				h = h-1;
			}	
		cout<<compat<<" "<<str<<" "<<str1<<endl;/* printing top five compatible couples onto the screen*/	
		
	}
}

#endif
