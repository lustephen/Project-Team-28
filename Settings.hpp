#include <iostream>
#include <string>

class Settings
{
	private:
		double maxdistance;
		double exchangerate;
		double mindistance;
		double minexchangerate;
		double minprofit;
		
	public:
		void setMaxDistance(double max);
		void setExchangeRate(double exchange);
		void setMinDistance(double min);
		void setMinExchangeRate(double minexchange);
		void setMinProfit(double minprof);
		
		double getMaxDistance();
		double getExchangeRate();
		double getMinDistance();
		double getMinExchangeRate();
		double getMinProfit();
};
