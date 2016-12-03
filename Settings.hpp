#ifndef SETTINGS_H
#define SETTINGS_H

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

		friend std::ostream& operator<<(std::ostream& os, const Settings& set)
  	{
  		// write out individual members of s with an end of line between each one
  		os << set.exchangerate << '\n';
  		os << set.minprofit << '\n';
  		return os;
  	}

  	// Extraction operator
  	friend std::istream& operator>>(std::istream& is, Settings& set)
  	{
  		// read in individual members of s
  		is >> set.exchangerate >> set.minprofit;
  		return is;
  	}
};

#endif
