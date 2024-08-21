#include "util.h"

using namespace std;

vector<vector<int>> createMatrice(int equations, int unknowns)
{
    vector<vector<int>> matrice {};
    int coefficient;
    char var;
    for (int i = 0; i < equations; i++)
    {
        vector<int> coeff {};
        for (int v = 0; v < unknowns + 1; v++)
        {
//ASCII conversion = index + 49 = lowercase letter
            var = v + 49;
            if (v != unknowns)
            {
                coefficient = readInt("Enter coefficient of " + var + ": ");
                coeff.push_back(coefficient);
            }
            else
            {
                coefficient = readInt("Enter answer of the equation: ");
                coeff.push_back(coefficient);
            }
        }
        matrice.push_back(coeff);
    }
    return matrice;
}

void displayEquations(vector<vector<int>> matrice)
{
    for (vector<int> eq : matrice)
    {
        char coe = 97;
        for (int j = 0; j < eq.size(); j++)
        {
            while (j < eq.size() - 1)
            {
                cout << "" << eq[j] << coe << " + ";
            }
        }
    }
}

vector<int> solve(vector<vector<int>> matrice)
{
    //placeholder
    return matrice[0];
}

vector<vector<int>> addRow(vector<vector<int>> matrice, vector<int> row1, vector<int> row2)
{
    //placeholer
    return matrice;
}

vector<vector<int>> multiplyRow(vector<vector<int>> matrice, vector<int> row1, vector<int> row2)
{
    //placeholder
    return matrice;
}

int main()
{
    string input = "x";
    vector<vector<vector<int>>> savedMatrices {};
    vector<vector<int>> matrice {};
    vector<int> coeff {};
    int equations;
    int unknowns;
    int systnum;
    while (input != "e")
    {
        if (input == "c")
        {
            equations = readInt(2, 9, "Enter number of equations: ", "Must be greater than 2: ");
            unknowns = readInt(2, 9, "Enter number of unknowns: ", "Must be greater than 2: ");
            savedMatrices.push_back(createMatrice(equations, unknowns));
        }
        if (input == "d")
        {
            cout << "You have " << savedMatrices.size() << "saved systems";
            systnum = readInt(1, savedMatrices.size(), "Display system: ");
            displayEquations(savedMatrices[systnum - 1]);
        }
        if (input == "s")
        {

        }
        if (input == "del")
        {

        }
        cout << "(c)reate new system" << endl << "(d)isplay existing system" << endl << "(s)olve existing system" << endl << "(del)ete a system" << endl << "(e)xit";
        getline(cin, input);
    }
    return 0;
}
