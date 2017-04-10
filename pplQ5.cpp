#include <bits/stdc++.h>
#include "SORTED.h"
#include "MAKE_COUPLE.h"

using namespace std;
void sorted (FILE *fp, FILE *fp1);

int main()
{
	FILE *fptr, *fptrptr;
	fptr = fopen ("mod_boy.txt","w");
	fptrptr = fopen ("mod_girl.txt","w");
	sorted (fptr,fptrptr);
	fptr = fopen ("mod_boy.txt","r");
	fptrptr = fopen ("mod_girl.txt","r");
	make_couple (fptr, fptrptr);
	
}
