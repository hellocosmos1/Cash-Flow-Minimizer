#include <bits/stdc++.h>
using namespace std;

class person {
public:
    string name;
    int netAmount;
    set<string> types;
};

int getMinIndex(person listOfNetAmounts[], int numPeople) {
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < numPeople; i++) {
        if (listOfNetAmounts[i].netAmount == 0) continue;
        if (listOfNetAmounts[i].netAmount < min) {
            minIndex = i;
            min = listOfNetAmounts[i].netAmount;
        }
    }
    return minIndex;
}

int getSimpleMaxIndex(person listOfNetAmounts[], int numPeople) {
    int max = INT_MIN, maxIndex = -1;
    for (int i = 0; i < numPeople; i++) {
        if (listOfNetAmounts[i].netAmount == 0) continue;
        if (listOfNetAmounts[i].netAmount > max) {
            maxIndex = i;
            max = listOfNetAmounts[i].netAmount;
        }
    }
    return maxIndex;
}

pair<int, string> getMaxIndex(person listOfNetAmounts[], int numPeople, int minIndex, person input[], int maxNumTypes) {
    int max = INT_MIN;
    int maxIndex = -1;
    string matchingType;

    for (int i = 0; i < numPeople; i++) {
        if (listOfNetAmounts[i].netAmount == 0) continue;
        if (listOfNetAmounts[i].netAmount < 0) continue;

        vector<string> v(maxNumTypes);
        vector<string>::iterator ls = set_intersection(
            listOfNetAmounts[minIndex].types.begin(), listOfNetAmounts[minIndex].types.end(),
            listOfNetAmounts[i].types.begin(), listOfNetAmounts[i].types.end(),
            v.begin());

        if ((ls - v.begin()) != 0 && max < listOfNetAmounts[i].netAmount) {
            max = listOfNetAmounts[i].netAmount;
            maxIndex = i;
            matchingType = *(v.begin());
        }
    }

    return make_pair(maxIndex, matchingType);
}

void printAns(vector<vector<pair<int, string>>> ansGraph, int numPeople, person input[]) {
    cout << "\nThe transactions for minimum cash flow are as follows:\n\n";
    for (int i = 0; i < numPeople; i++) {
        for (int j = 0; j < numPeople; j++) {
            if (i == j) continue;

            if (ansGraph[i][j].first != 0 && ansGraph[j][i].first != 0) {
                if (ansGraph[i][j].first == ansGraph[j][i].first) {
                    ansGraph[i][j].first = 0;
                    ansGraph[j][i].first = 0;
                } else if (ansGraph[i][j].first > ansGraph[j][i].first) {
                    ansGraph[i][j].first -= ansGraph[j][i].first;
                    ansGraph[j][i].first = 0;
                    cout << input[i].name << " pays ₹" << ansGraph[i][j].first << " to " << input[j].name << " via " << ansGraph[i][j].second << endl;
                } else {
                    ansGraph[j][i].first -= ansGraph[i][j].first;
                    ansGraph[i][j].first = 0;
                    cout << input[j].name << " pays ₹" << ansGraph[j][i].first << " to " << input[i].name << " via " << ansGraph[j][i].second << endl;
                }
            } else if (ansGraph[i][j].first != 0) {
                cout << input[i].name << " pays ₹" << ansGraph[i][j].first << " to " << input[j].name << " via " << ansGraph[i][j].second << endl;
            } else if (ansGraph[j][i].first != 0) {
                cout << input[j].name << " pays ₹" << ansGraph[j][i].first << " to " << input[i].name << " via " << ansGraph[j][i].second << endl;
            }

            ansGraph[i][j].first = 0;
            ansGraph[j][i].first = 0;
        }
    }
    cout << "\n";
}

void minimizeCashFlow(int numPeople, person input[], unordered_map<string, int>& indexOf, int numTransactions, vector<vector<int>>& graph, int maxNumTypes) {
    person listOfNetAmounts[numPeople];

    for (int p = 0; p < numPeople; p++) {
        listOfNetAmounts[p].name = input[p].name;
        listOfNetAmounts[p].types = input[p].types;

        int amount = 0;
        for (int i = 0; i < numPeople; i++) amount += graph[i][p];
        for (int j = 0; j < numPeople; j++) amount -= graph[p][j];

        listOfNetAmounts[p].netAmount = amount;
    }

    vector<vector<pair<int, string>>> ansGraph(numPeople, vector<pair<int, string>>(numPeople, {0, ""}));

    int numZeroNetAmounts = 0;
    for (int i = 0; i < numPeople; i++)
        if (listOfNetAmounts[i].netAmount == 0) numZeroNetAmounts++;

    while (numZeroNetAmounts != numPeople) {
        int minIndex = getMinIndex(listOfNetAmounts, numPeople);
        pair<int, string> maxAns = getMaxIndex(listOfNetAmounts, numPeople, minIndex, input, maxNumTypes);

        int maxIndex = maxAns.first;

        if (maxIndex == -1) {
            ansGraph[minIndex][0].first += abs(listOfNetAmounts[minIndex].netAmount);
            ansGraph[minIndex][0].second = *(input[minIndex].types.begin());

            int simpleMaxIndex = getSimpleMaxIndex(listOfNetAmounts, numPeople);
            ansGraph[0][simpleMaxIndex].first += abs(listOfNetAmounts[minIndex].netAmount);
            ansGraph[0][simpleMaxIndex].second = *(input[simpleMaxIndex].types.begin());

            listOfNetAmounts[simpleMaxIndex].netAmount += listOfNetAmounts[minIndex].netAmount;
            listOfNetAmounts[minIndex].netAmount = 0;

            if (listOfNetAmounts[minIndex].netAmount == 0) numZeroNetAmounts++;
            if (listOfNetAmounts[simpleMaxIndex].netAmount == 0) numZeroNetAmounts++;
        } else {
            int transactionAmount = min(abs(listOfNetAmounts[minIndex].netAmount), listOfNetAmounts[maxIndex].netAmount);
            ansGraph[minIndex][maxIndex].first += transactionAmount;
            ansGraph[minIndex][maxIndex].second = maxAns.second;

            listOfNetAmounts[minIndex].netAmount += transactionAmount;
            listOfNetAmounts[maxIndex].netAmount -= transactionAmount;

            if (listOfNetAmounts[minIndex].netAmount == 0) numZeroNetAmounts++;
            if (listOfNetAmounts[maxIndex].netAmount == 0) numZeroNetAmounts++;
        }
    }

    printAns(ansGraph, numPeople, input);
}

int main() {
    cout << "\n\t\t\t\t********************* Welcome to CASH FLOW MINIMIZER SYSTEM ***********************\n\n\n";
    cout << "This system minimizes the number of transactions among multiple people using different modes of payment. One person (Universal Person) supports all modes and can act as an intermediary.\n\n";

    cout << "Enter the number of people participating in the transactions.\n";
    int numPeople;
    cin >> numPeople;

    person input[numPeople];
    unordered_map<string, int> indexOf;

    cout << "Enter the details of the people and their payment modes:\n";
    cout << "Person name, number of payment modes, and the payment modes (no spaces).\n";

    int maxNumTypes;
    for (int i = 0; i < numPeople; i++) {
        if (i == 0) {
            cout << "Universal Person: ";
        } else {
            cout << "Person " << i << ": ";
        }

        cin >> input[i].name;
        indexOf[input[i].name] = i;
        int numTypes;
        cin >> numTypes;

        if (i == 0) maxNumTypes = numTypes;

        string type;
        while (numTypes--) {
            cin >> type;
            input[i].types.insert(type);
        }
    }

    cout << "Enter the number of transactions.\n";
    int numTransactions;
    cin >> numTransactions;

    vector<vector<int>> graph(numPeople, vector<int>(numPeople, 0));

    cout << "Enter the details of each transaction:\n";
    cout << "Debtor, Creditor, and Amount\n";
    for (int i = 0; i < numTransactions;
