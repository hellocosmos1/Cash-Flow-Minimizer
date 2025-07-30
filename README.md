# Cash-Flow-Minimizer
This system minimizes the number of transactions among multiple banks in the different corners of the world that use different modes of payment. There is one world bank (with all payment modes) to act as an intermediary between banks that have no common mode of payment. 

# Getting-Started
The Cash Flow Minimizer project aims to minimize the number of transactions among multiple banks with different payment modes. It solves the problem of finding an optimal solution to settle the debts between people using the minimum number of transactions.There is one person (with all payment modes) to act as an intermediary between peoples that have no common mode of payment.
The algorithm used in this project is based on the concept of finding the net amount for each bank and then determining the transactions required to balance the cash flow. The algorithm consists of the following steps:


Create a Person class that represents each bank participating in the transactions. The Person class has attributes such as the name, net amount, and a set of payment modes it supports.


Implement the getMinIndex method, which finds the person with the minimum net amount from the list of banks. It skips the person if its net amount is already zero.


Implement the getSimpleMaxIndex method, which finds the person with the maximum net amount from the group of people. It skips the person if its net amount is zero.


Implement the getMaxIndex method, which finds the person with the maximum net amount and a common payment type with the person having the minimum net amount. It iterates over different people, checks if the net amount is positive, and finds the common payment type using the intersection operation on the sets of payment modes.


Implement the printAns method, which prints the transactions required for minimizing the cash flow. It iterates over people debts and credits and prints the transactions between people where the net amount is non-zero. It updates the net amounts and sets the transaction amounts to zero after printing.


Implement the minimizeCashFlow method, which performs the main cash flow minimization logic. It calculates the net amount for each bank and initializes an empty 2D graph to store the transaction amounts between banks. It iterates everyone have a net amount of zero. In each iteration, it finds the person with the minimum net amount and the person with the maximum net amount and a common payment type. It determines the transaction amount and updates the net amounts accordingly. It also updates the graph with the transaction amounts.


Implement the main method, which serves as the entry point of the program. It prompts the user to input the number of person, persons details (name, number of payment modes, and payment modes), number of transactions, and transaction details (sender bank, receiver bank, and amount). It then calls the minimizeCashFlow method with the provided inputs to calculate and print the minimum cash flow transactions.


The Cash Flow Minimizer project uses data structures like arrays, lists, sets, and maps to store and process the bank and transaction information efficiently. The algorithm ensures that the cash flow is minimized by determining the optimal transactions between banks based on their net amounts and common payment types.Overall, this project provides a practical solution to optimize cash flow transactions among multiple people, considering their different payment modes, and minimizes the number of transactions required to settle the debts.

People:

Amit 

Bhavna

Chirag

Deepa

Eshan

Farhan

Payment Obligations:

<img width="499" height="386" alt="image" src="https://github.com/user-attachments/assets/240ae4e9-deba-40ab-8fcb-317a3b968d92" />


Payment Modes Supported:
Amit	: Google Pay, PhonePe, Paytm
Bhavna	: Google Pay, PhonePe
Chirag	: PhonePe
Deepa	: Google Pay, Paytm
Farhan	: Paytm
Eshan	: PhonePe, Paytm

Net Balances:


<img width="721" height="330" alt="image" src="https://github.com/user-attachments/assets/724ec529-5794-4a09-a895-a13ef3e8a6ac" />


Now the idea is that we are finding the person which has minimum net amount(max debtor) (say person X, net amount x) and then finding the person which has the maximum net amount( max creditor) (say person Y, net amount y) and also has a common payment mode (say M1) with the former person. Then we find minimum of absolute value of x and y, lets call it z.
Now X pays the amount z to Y. Then 3 cases may arrived:

If (magnitude of x) < y => X is completely settled and so removed from the list.
If (magnitude of x) > y => Y is completely settled and so removed from the list.
If (magnitude of x) = y => X and Y both are completely settled and so both are removed from the list.


**Minimum Transactions:**

Farhan pays Rs 600 to Deepa via Paytm
(Common mode: Paytm)

Eshan pays Rs 400 to Bhavna via PhonePe
(Common mode: PhonePe)

Chirag pays Rs 100 to Bhavna via PhonePe
(Common mode: PhonePe)

**✅ Final Minimum Transactions (with PhonePe):**
Farhan pays Rs 600 to Deepa via Paytm

Eshan pays Rs 400 to Bhavna via PhonePe

Chirag pays Rs 100 to Bhavna via PhonePe

# Conclusion
In the above example,different people had differnt payment modes and acted as debtor/creditor,However through this tool we found the way for effective fund transfer among people pertaning to less number of transactions by removing unneccessary intermediate transactions.

Thank You!
