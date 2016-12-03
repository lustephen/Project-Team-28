#include <iostream>
#include <string>

class Settings
{
	private:
		double exchangerate;
		double minprofit;
		
	public:
		void setExchangeRate(double exchange);
		void setMinProfit(double minprof);
		
		double getExchangeRate();
		double getMinProfit();
};
