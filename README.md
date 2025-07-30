# Cash-Flow-Minimizer
This system minimizes the number of transactions among multiple banks in the different corners of the world that use different modes of payment. There is one world bank (with all payment modes) to act as an intermediary between banks that have no common mode of payment. 

# Getting-Started
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
