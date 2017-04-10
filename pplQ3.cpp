#include <bits/stdc++.h>

#include "COMPATIBLE.h"
using namespace std;


void compatible (FILE *fp, FILE *fp1, FILE *fp2);
int main()
{
	FILE *fp, *fp1, *fp2, *fp3; 
	fp = fopen("CSV.txt", "r");	/*open file containing details of boys */
	fp1 = fopen("CSV1.txt", "r");	/*open file containing details of girls */
	fp2 = fopen("CSV2.txt", "r");	/*open file containing details of gifts */
	compatible (fp, fp1,fp2);
}


