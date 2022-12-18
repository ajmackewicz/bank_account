#pragma once
#include "NoServiceChargeChecking.h"

class HighInterestChecking : public NoServiceChargeChecking
{
public:
	static const double INTEREST_RATE;
	static const double MINIMUM_BALANCE;

public:
	// Constructor
	HighInterestChecking(string fn = "NoFN", string ln = "NoLN", double bal = 0.0);

	// Destructor
	~HighInterestChecking();
};
