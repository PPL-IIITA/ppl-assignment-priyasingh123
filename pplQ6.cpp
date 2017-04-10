#include <bits/stdc++.h>
#include "NEW_COUPLE.h"

using namespace std;


void new_couple (FILE* );
int main()
{
	FILE *fp;
	fp = fopen ("CSV3.txt","r");
	new_couple(fp);
	fclose (fp);
}


