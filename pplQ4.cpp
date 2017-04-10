#include <bits/stdc++.h>

#include "BREAKUP.h"


using namespace std;

void breakup (FILE *fp );
int main()
{
	FILE *fp;
	fp = fopen("k_happy.txt", "r");//open k_happy.txt file
	breakup(fp);
}


