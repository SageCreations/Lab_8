#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

ifstream inFile;
ofstream outFile;

int DptNum[9];
string Items[9];
int Qty[9];
int CostP[9];
int SaleP[9];
int totalC = 0, totalS = 0, lowestT, gTotal = 0;

void printStuff(int begin, int end)
{
    totalC = 0;
    totalS = 0;
    for (int i = begin; i < end; i++) {
        outFile << "\n" << setw(8) << Items[i] << setw(8) << Qty[i] << setw(9) << CostP[i] << ".00"
                << setw(7) << SaleP[i] << ".00" << setw(12) << CostP[i] * Qty[i] << ".00"
                << setw(7) << SaleP[i] * Qty[i] << ".00";
        totalC += CostP[i] * Qty[i];
        totalS += SaleP[i] * Qty[i];
    }
    outFile << "\n" << setw(10) << "Total" << "\t\t\t\t\t\t\t\t\t" << setw(1) << "$" << totalC << ".00"
            << setw(2) << "$" << totalS << ".00";

    lowestT = (totalC < totalS) ? totalC : totalS;
    outFile << setw(7) << "$" << lowestT << ".00";
    gTotal+=lowestT;
}

int main() {
    int dptNum, qty, costP, saleP;
    char items[10];

    inFile.open("C:\\Users\\realq\\CLionProjects\\Lab_8\\blinn.dat");
    outFile.open("C:\\Users\\realq\\CLionProjects\\Lab_8\\blinn.dout");
    if (!inFile)
    {
        cout << "\n\t\tCan't open data file: blinn.dat";
        exit(1);
    }
    else if (!outFile)
    {
        cout << "\n\t\tCan't open data file: blinn.dout";
        exit(1);
    }
    else {

        outFile << "\n\n\t\t\t\t\t\t\tBlinn Discount Apparel Company";
        outFile << "\n\t\t\t\t\t\t\t     Inventory Evaluation";
        outFile << "\n\t\t\t\t\t\t\t\t      11/01/2001";

        int counter = 0;
        while (inFile >> dptNum >> items >> qty >> costP >> saleP)
        {
            DptNum[counter] = dptNum;
            Items[counter] = items;
            Qty[counter] = qty;
            CostP[counter] = costP;
            SaleP[counter] = saleP;
            counter++;
        }

        outFile << "\n\n\n\t\t\t\t\t\t  Unit Cost\t\t\t\t\tExtended";
        outFile << "\n\t\t\tQuantity\tCost\tMarket\t\t\tCost\t Market\t\tLower Cost";

        outFile << "\n\nMens Dept";
        printStuff(0, 3);

        outFile << "\n\nLadies Dept";
        printStuff(3, 6);

        outFile << "\n\nGirls Dept";
        printStuff(6, 8);

        outFile << "\n\nBoys Dept";
        printStuff(8, 9);

        outFile << "\n Total Inventory\t\t\t\t\t\t\t\t\t\t\t" << setw(9) << "$" << gTotal << ".00";
    }
    return 0;
}