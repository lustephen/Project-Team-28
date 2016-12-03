#include <iostream>
#include <string>

class Settings
{
	private:
		double exchangerate;
		double minexchangerate;
		double minprofit;
		
	public:
		void setExchangeRate(double exchange);
		void setMinExchangeRate(double minexchange);
		void setMinProfit(double minprof);
		
		double getExchangeRate();
		double getMinExchangeRate();
		double getMinProfit();
};
