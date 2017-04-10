#ifndef H_make_couple 
#define H_make_couple

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

void make_couple (FILE *fp, FILE* fp1)
{
	BOY  boy;
	GIRL girl;
	GIRL gf;
	//cout<<"hello"<<endl;
	for (; !feof (fp1);) {
		fscanf(fp1,"%s %d %d %d %s %s",girl.name,&girl.attract,&girl.budget,&girl.int_level,girl.type,girl.status);
		//cout<<"######"<<girl.name<<endl;
		for (; !feof(fp);) {
			fscanf(fp,"%s %d %d %d %s %s",boy.name,&boy.attract,&boy.budget,&boy.int_level,boy.type,boy.status);
			
			if (girl.attract >= boy.attract && boy.budget >= girl.budget) {
				cout<<girl.name<<" "<<boy.name<<endl;
				//cout<<"i am here"<<endl;
				break;
			}
			//else cout<<"nono"<<endl;
			
			
		}
	}
	fclose (fp);
	fclose(fp1);
}

#endif
