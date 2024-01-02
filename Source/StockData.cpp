#include "StockData.h"

void StockData::SetPrices(juce::String csvString)
{
	const int COLUMN = 2;

	juce::String string = csvString;
	//while (string != "")
	for (int i = 0; i < 10; i++)
	{
		for (int i = 0; i < COLUMN - 1; i++)
			string = string.substring(string.indexOf(",\"") + 1);
		prices.push_back( string.substring(0, string.indexOf("\"")).getFloatValue() );
		int escapeIndex = string.indexOf("\n");
		if (escapeIndex == -1)
			string == "";
		string = string.substring(escapeIndex + 1);
	}
}