#include <iostream>
#include <string>
#include <vector>
#include <ctime>


int main() {
	//IF THE USER IF A BUYER CASE
	double varEstPurchase;
	double varExchangeRate;
	int count = 0;
	
	while (count == 0) {
		std::cout << "You have chosen to be a Buyer, Please fill out below" << std::endl << "Enter your Estimated purchase cost $(1.00 - 40.00): ";
		std::cin >> varEstPurchase;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		while (varEstPurchase < 1.00 || varEstPurchase > 40.00) {
			std::cout << "Invalid input, Please enter your Estimated Purchase Cost $(1.00-40.00): ";
			std::cin >> varEstPurchase;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}


		std::cout << std::endl << "Enter your Exchange rate (0.55-.99) ";
		std::cin >> varExchangeRate;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		while (varExchangeRate < .55 || varExchangeRate > .99) {
			std::cout << "Invalid input, Please Enter Your Exchange Rate: ";
			std::cin >> varExchangeRate;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}

		int staller = 0;
		std::string decision;
		std::string decision2;
		while (staller == 0) {
			std::cout << "You have chosen to search for $" << varEstPurchase << " at an exchange rate of " << varExchangeRate << std::endl;
			std::cout << "Do you accept (Y/N)? ";
			std::cin >> decision;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			if (decision == "Y" || decision == "y") {
				staller = 1;
				count = 1;
			}
			else if (decision == "N" || decision == "n") {
				int holder = 0;
				while (holder == 0) {
					std::cout << "Would you like to change your preferences (Y/N)? (N goes back to main menu) ";
					std::cin >> decision2;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(1000, '\n');
					}
					if (decision2 == "Y" || decision2 == "y") {
						holder = 1;		
						staller = 1;
						count == 0;
					}
					else if (decision2 == "N" || decision2 == "n") {
						holder = 1;
						staller = 1;
						count = 1;
						//some other var = 1 so that it goes back to main menu
					}
					else {	//error holder loop
						std::cout << "Invalid choice, Please try again." << std::endl;
					}
				}
			}
			else {	//error staller while loop
				std::cout << "Invalid choice, Please try again." << std::endl;
				
			}

		}	//end of staller while loop

	}	//end of count while loop


	std::cout << "Processing..." << std::endl;

	//Pass to buyer class to find best person (lowest exchange rate, meets sellers min purchase requirement)

	/*
	Buyer *user = new Buyer(varEstPurchase, varExchangeRate);
	std::vector<Seller*> sellerlist;
	createSellerPop(sellerlist);
	SortAndCalculate *sellercompute = new SortAndCalculate(user, sellerlist);

	NEED TROUBLESHOOTING AFTER THIS (Danilo, Beatrice)

	if(sellercompute->avaliableSellerCheck())
	{
		bool tr = false;
		char Y_N;
		sellercompute->buyerFlow();
		//Don't know what you want to do with the selected seller
		Seller *selectedSeller=sellercompute->getSelectedSeller();
		std::cout<<"Seller: "<<selectedSeller->getName()<<" has exchange rate: "<<selectedSeller->getExchangeRate()<<std::endl;
		std::cout<<"Would you like to trade with "<<selectedSeller->getName()<<" Y/N"<<std::endl;
		cin >> Y_N;
		
		//trouble shooting here for poor input
		//if(~="Y"||"y")
		//pass the seller to a seller vector in the account class? to store the seller
		//else
		//std::cout<<"Seller not selected. FlexBucksMarket will now exit. Have a nice day!"<<std::endl;
		
		do
		{
			if(Y_N == 'Y' || Y_N == 'y')
			{
				//pass users estpurcahse sellers exchange rate and sellers name
			}
		
			else if(Y_N == 'N' || Y_N == 'n')
			{
				cout << "Transaction Cancelled. Have a nice day!" << endl;
				break;
			}
		
			else
			{
				cout << "Error: Invalid Input" << endl;
				tr = true;
				
				std::cout<<"Seller: "<<selectedSeller->getName()<<" has exchange rate: "<<selectedSeller->getExchangeRate()<<std::endl;
				std::cout<<"Would you like to trade with "<<selectedSeller->getName()<<" Y/N"<<std::endl;
				cin >> Y_N;
			}
			
		}while(tr);
		
	}

	else
	{
		cout << "There is no match << endl;
		break;
	}

	Pass parameters to find best Seller for the user to buy from
	
	*/




	//IF THE USER IS A SELLER CASE
	double varMinPurchase;
	double varExchangeRate2;
	int scount = 0;

	while (scount == 0) {
		std::cout << "You have chosen to be a Seller, Please fill out below" << std::endl << "Enter your Minimum Purchase cost $(1.00 - 40.00): ";
		std::cin >> varMinPurchase;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		while (varMinPurchase < 1.00 || varMinPurchase > 40.00) {
			std::cout << "Invalid input, Please enter your Minimum Purchase Cost $(1.00-40.00): ";
			std::cin >> varMinPurchase;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}


		std::cout << std::endl << "Enter your Exchange rate (0.55-.99) ";
		std::cin >> varExchangeRate2;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		while (varExchangeRate2 < .55 || varExchangeRate2 > .99) {
			std::cout << "Invalid input, Please Enter Your Exchange Rate: ";
			std::cin >> varExchangeRate2;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		}

		int sstaller = 0;
		std::string sdecision;
		std::string sdecision2;
		while (sstaller == 0) {
			std::cout << "You have chosen to search for a Minimum Purchase of $" << varMinPurchase << " at an exchange rate of " << varExchangeRate2 << std::endl;
			std::cout << "Do you accept (Y/N)? ";
			std::cin >> sdecision;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			if (sdecision == "Y" || sdecision == "y") {
				sstaller = 1;
				count = 1;
			}
			else if (sdecision == "N" || sdecision == "n") {
				int sholder = 0;
				while (sholder == 0) {
					std::cout << "Would you like to change your preferences (Y/N)? (N goes back to main menu) ";
					std::cin >> sdecision2;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(1000, '\n');
					}
					if (sdecision2 == "Y" || sdecision2 == "y") {
						sholder = 1;
						sstaller = 1;
						scount == 0;
					}
					else if (sdecision2 == "N" || sdecision2 == "n") {
						sholder = 1;
						sstaller = 1;
						scount = 1;
						//some other var = 1 so that it goes back to main menu
					}
					else {	//error sholder loop
						std::cout << "Invalid choice, Please try again." << std::endl;
					}
				}
			}
			else {	//error sstaller while loop
				std::cout << "Invalid choice, Please try again." << std::endl;

			}

		}	//end of sstaller while loop

	}	//end of scount while loop

		//Pass to seller lass to find best person (highest exchange rate and meets min purchase requirement)

		/*
		Seller *user2 = new Seller(varMinPurchase, varExchangeRate);
		std::vector<Buyer*> buyerlist;
		createSellerPop(buyerlist);
		SortAndCalculate *buyercompute = new SortAndCalculate(user2, buyerlist);
		
		if(buyercompute->avaliableSellerCheck())
	{
		buyercompute->sellerrFlow();
		//Don't know what you want to do with the selected seller
		Buyer *selectedBuyer=buyercompute->getSelectedBuyer();
		std::cout<<"Buyer: "<<selectedBuyer->getName()<<" has exchange rate: "<<selectedBuyer->getExchangeRate()
		<<" and a estimated purchase of "<<selectedBuyer->getEstPurchase()<<std::endl;
		std::cout<<"Would you like to trade with "<<selectedBuyer->getName()<<" Y/N"<<std::endl;
		//trouble shooting here for poor input
		//if(~="Y"||"y")
		//pass the buyer to a buyer vector in the account class? to store the buyer
		else
		std::cout<<"Buyer not selected. FlexBucksMarket will now exit. Have a nice day!"<<std::endl;
		
	}

	else
	{
		cout << "There is no match << endl;
		break;
	}

		NEED TROUBLESHOOTING AFTER THIS (Danilo, Beatrice)
		Check to see if something in vector meets requirements

		Pass parameters to find best buyer for the user to sell to
		*/


	std::cout << "Processing..." << std::endl;

	std::cout << std::endl << std::endl << "End of Program";
	int inputerer;
	std::cin >> inputerer;
	return 0;
}
