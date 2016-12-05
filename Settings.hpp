#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <string>
//Settings classed used to save exchange rate and minimum purchase cost for each account, May not be used
class Settings
{
	private:
		double exchangerate;
		double minpurchase;

	public:
		void setExchangeRate(double exchange);
		void setMinPurchase(double minpurch);

		double getExchangeRate();
		double getMinPurchase();

		friend std::ostream& operator<<(std::ostream& os, const Settings& set)
  	{
  		// write out individual members of s with an end of line between each one
  		os << set.exchangerate << '\n';
  		os << set.minpurchase << '\n';
  		return os;
  	}

  	// Extraction operator
  	friend std::istream& operator>>(std::istream& is, Settings& set)
  	{
  		// read in individual members of s
  		is >> set.exchangerate >> set.minpurchase;
  		return is;
  	}
};

#endif
