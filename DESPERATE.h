#ifndef H_Desperate
#define H_Desperate
#include<bits/stdc++.h>
#include "GIRL.h"
//!class name DESPERATE
using namespace std;

class DESPERATE : public GIRL { //!child class of GIRL class
	public:
	double cal_happ (int gift_price, int gift_value) {// calculates happiness
		double happ = exp (gift_price);
		return (happ);
	}
};

#endif
