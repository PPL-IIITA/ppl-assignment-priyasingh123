#ifndef H_gifting
#define H_gifting

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
map<char, int> m;
void gifting(FILE* fp)
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
		left = 0;
		int val = 0, compat;
		int budget = boy.budget;
		double girl_happ, boy_happ;
	 
		fp2 = fopen ("CSV2.txt","r");
		for (; !feof(fp2);) {
			fscanf(fp2,"%d %d %s",&gift.price,&gift.value,gift.type);
			char a = gift.type[0];
			m[a] = 1;
			//cout<<"gift.type[0]"<<" "<<gift.type[0]<<endl;
			left = left+gift.price;
			val = val+gift.value;
			budget = budget-gift.price;
			
			if (budget < 0) {
				if (m['U'] != 1) {
					//rewind(fp2);
					fscanf(fp2,"%d %d %s",&gift.price,&gift.value,gift.type);
					while (strcmp(gift.type,"Utility")) {
						fscanf(fp2,"%d %d %s",&gift.price,&gift.value,gift.type);
					}
					left = left+gift.price;
					val = val+gift.value;
				}


				if (m['E'] != 1) {
					//rewind(fp2);
					fscanf(fp2,"%d %d %s",&gift.price,&gift.value,gift.type);
					while (strcmp(gift.type,"Essential")) {
						fscanf(fp2,"%d %d %s",&gift.price,&gift.value,gift.type);
					}
					left = left+gift.price;
					val = val+gift.value;
				}

				if (m['L'] != 1) {
					//rewind(fp2);
					fscanf(fp2,"%d %d %s",&gift.price,&gift.value,gift.type);
					while (strcmp(gift.type,"Luxury")) {
						fscanf(fp2,"%d %d %s",&gift.price,&gift.value,gift.type);
					}
					left = left+gift.price;
					val = val+gift.value;
				}
			}
			if (m['U'] == 1 && m['L'] == 1 && m['E'] == 1) {
				m.clear();
				if (girl.type == "choosy") {
					CHOOSY girll;
					girl_happ = girll.cal_happ (left, val);
				}
				else if (girl.type == "normal") {
					NORMAL girll;
					girl_happ = girll.cal_happ (left, val);
				}
				else  {
					DESPERATE girll;
					girl_happ = girll.cal_happ (left, val);
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
				compat = abs (girl.int_level - boy.int_level) + abs (girl.attract - boy.attract)+abs(boy.budget-girl.budget);
				cout<<compat<<" "<<boy.name<<" "<<girl.name<<endl;
				fclose(fp2);
				break;
				
			}
		}
		
	}
}

#endif
