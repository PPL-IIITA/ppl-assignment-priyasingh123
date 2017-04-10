#ifndef H_Choosy 
#define H_Choosy
#include<bits/stdc++.h>
#include "GIRL.h"
//!class name CHOOSY
using namespace std;

class CHOOSY : public GIRL {//! child class of GIRL class
	public:
	double cal_happ (int gift_price, int gift_value) { // calculates happiness
		double happ = (log(gift_price+(2*gift_value)));
		return (happ);
	}
};

#endif
