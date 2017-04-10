#include <bits/stdc++.h>
#include "FIND_GF.h"
#include "FIND_GF2.h"
#include "FIND_GF1.h"

using namespace std;


void find_gf (FILE *fp) ;
void find_gf2 (FILE *fp) ;

int main()
{
	FILE *fp;
	fp = fopen ("CSV3.txt","r");
	srand ((unsigned int) time (NULL));
	int temp = rand()%3;
	if (temp == 0) {
		find_gf1 (fp);	// array
	}
	else if (temp == 1) {
		find_gf2(fp);	//hash table
	}
	else {
		find_gf (fp);	//through array
	}
	fclose (fp);
}

