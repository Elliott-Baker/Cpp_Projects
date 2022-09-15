/*
	Name: Elliott Baker
	ID: 904116291
	File Name: project1_Baker_ecb0105.cpp
	Compile using g++
	Sources: I used the internet to find the correct syntax for do-while loops
	I also used the lecture slides and information from Dr. Li in class. 
*/
#include <iostream>
using namespace std;

/*
	This program calculates months required to pay off loan.
	Will prompt user for input until it is valid. 
	When the input is valid, the calculations begin. 
*/
int main()
{
    double balance;         // loan amount to be paid off - user input
    double itr_rate;        // fixed yearly interest rate - user input
	double month_payment;   // monthly payment amount
	
    double itr_month;       // fixed yearly interest rate divided by 12
    double interest;        // interest owed per month
    double principal;       // principal paid
    int months = 0;         // number of months
    double itr_counter;     // total interest paid

	
    do {
		
		/*
			Prompts user indefinitely until valid loan amount is given.
			Valid loan amount is positive. 
		*/
		do {
        cout << "\nLoan Amount: ";
        cin >> balance;
		
			if (balance <= 0) 
			{
				cout << "Invalid loan amount. Try again...\n";
				continue;
			}
			else 
			{
				break;
			}
		}
		while (true);

		/*
			Prompts user indefinitely until valid interest rate is given. 
			Valid interest is non-negative.
		*/
		do {
		cout << "Interest Rate (% per year): ";
        cin >> itr_rate;
        itr_rate = itr_rate / 100;  // converts from percentage to decimal
        itr_month = itr_rate / 12;  // calculates monthly interest rate
		
			if (itr_rate < 0) 
			{
				cout << "Negative interest rate not allowed. Try again...\n";
				continue;
			}
			else 
			{
				break;
			}
		}
		while (true);
		
		/*
			Prompts user indefinitely until valid monthly payment is given. 
			Valid monthly payment must be greater than initial interest. 
		*/
		do {
        cout << "Monthly Payments: ";
        cin >> month_payment;
        cout << endl;
		
		if ((month_payment - (itr_month * balance)) <= 0) 
		{
			cout << "This loan cannot be paid off with the given monthly payment.\n";
			continue;
		}
		else 
		{
			break;
		}
		}
		while (true);
		
		break;
    }
    while (true);
	
	// Table format
    cout << "*****************************************************************\n";
    cout << "\tAmortization Table\n";
    cout << "*****************************************************************\n";
    cout << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
    cout << months << "\t$" << balance << "\t\tN/A\tN/A\tN/A\t\tN/A\n";
	
	// Number formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

	
	// While-loop makes "payments" on the loan as long as balance >= 0. 
    while (balance >= 0) {  
	
		/* The case where the monthly payment exceeds remaining balance.
			Monthly payment is modified. While-loop is broken. 
		*/
        if (balance <= month_payment) {
            interest = itr_month * balance;
            month_payment = balance + interest;
            principal = month_payment - interest;
            balance = balance - principal;
            itr_counter += interest;
            months++;
            cout << months << "\t$" << balance << "\t\t$" << month_payment << "\t" << (itr_month * 100) << "\t$" << interest << "\t\t$" << principal << "\n"; // interest rate converted back to percentage
            break;
            
        }
		// All regular cases
        else {
            interest = itr_month * balance; 
            principal = month_payment - interest;
            balance = balance - principal;
            itr_counter += interest;
            months++;  
			if (balance > 1000) {
				cout << months << "\t$" << balance << "\t$" << month_payment << "\t" << (itr_month * 100) << "\t$" << interest << "\t\t$" << principal << "\n"; // if balance > 1000 formatting changes
			}
			else {
            cout << months << "\t$" << balance << "\t\t$" << month_payment << "\t" << (itr_month * 100) << "\t$" << interest << "\t\t$" << principal << "\n"; // interest rate converted back to percentage
			}
		}
    }

    cout << "*****************************************************************\n";

	// If it only took 1 month to pay off loan, output is modified for readability. 
    if (months == 1) {
        cout << "\nIt takes " << months << " month to pay off the loan." << endl;
    }
    else {
        cout << "\nIt takes " << months << " months to pay off the loan." << endl;

    }
    cout << "Total interest paid is: $" << itr_counter << "\n" << endl;
    }