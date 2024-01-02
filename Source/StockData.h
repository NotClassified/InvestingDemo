#pragma once
#include <JuceHeader.h>

class StockData
{
public:
	std::vector<float> prices;

	void SetPrices(juce::String csvString);
};

