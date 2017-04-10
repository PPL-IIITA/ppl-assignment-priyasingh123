#ifndef H_Normal
#define H_Normal
#include<bits/stdc++.h>
#include "GIRL.h"
using namespace std;
//! class name NORMAL
class NORMAL : public GIRL {//!child class of GIRL class
	public:
	double cal_happ (int gift_price, int gift_value) {//! calculates happiness
		double happ = gift_price+gift_value;
		return (happ);
	}
};

#endif
