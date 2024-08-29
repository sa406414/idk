#include "util.h"
#include <string>

using namespace std;

vector<vector<int>> createMatrice(int equations, int unknowns);
void displayEquations(vector<vector<int>> matrice);
vector<int> solve(vector<vector<int>> matrice);
vector<vector<vector<int>>> deleteMatrice(vector<vector<vector<int>>> storage, int indx);

vector<vector<int>> addRow(vector<vector<int>> matrice, int row1Index, int row2Index);
vector<vector<int>> multiplyRow(vector<vector<int>> matrice, int rowIndex, int factor);

int main()
{
    string input = "x";
    vector<vector<vector<int>>> savedMatrices {};
    vector<vector<int>> matrice {};
    vector<int> coeff {};
    int equations;
    int unknowns;
    int systnum;
    int row1;
    int row2;
    int factor;
    // "Why are you here? 1) matrices 2) vectors 3) etc (add calc stuff in future)"
    while (input != "e")
    {
        if (input == "c")
        {
            equations = readInt(2, 9, "Enter number of equations: ", "Must be greater than 2: ");
            unknowns = readInt(2, 9, "Enter number of unknowns: ", "Must be greater than 2: ");
            cout << endl;
            savedMatrices.push_back(createMatrice(equations, unknowns));
            cout << endl;
        }
        if (input == "d")
        {
            cout << "You have " << savedMatrices.size() << " saved systems" << endl;
            systnum = readInt(1, savedMatrices.size(), "Display system: ");
            cout << endl;
            displayEquations(savedMatrices[systnum - 1]);
            cout << endl << endl;
        }
        if (input == "s")
        {
            cout << "You have " << savedMatrices.size() << " saved systems" << endl;
            systnum = readInt(1, savedMatrices.size(), "Solve system: ");
            row1 = readInt(1, savedMatrices[systnum - 1].size(), "Which row");
            factor = readInt("What factoer");
            multiplyRow(savedMatrices[systnum - 1], row1 - 1, factor);
        }
        if (input == "del")
        {
            cout << "You have " << savedMatrices.size() << " saved systems" << endl;
            systnum = readInt(1, savedMatrices.size(), "Delete system: ");
            savedMatrices = deleteMatrice(savedMatrices, systnum);
            cout << endl << endl;
        }
        cout << "(c)reate new system" << endl << "(d)isplay existing system" << endl << "(s)olve existing system" << endl << "(del)ete a system" << endl << "(e)xit" << endl << "> ";
        getline(cin, input);
        cout << endl;
    }
    return 0;
}

vector<vector<int>> createMatrice(int equations, int unknowns)
{
    vector<vector<int>> matrice {};
    int coefficient;
    char var;
    string varaible = "";
    for (int i = 0; i < equations; i++)
    {
        vector<int> coeff {};
        for (int v = 0; v < unknowns + 1; v++)
        {
//ASCII conversion = index + 97 = lowercase letter
            var = v + 97;
            if (v != unknowns)
            {
                string varaible(1, var);
                coefficient = readInt("Enter coefficient of " + varaible + ": ");
                coeff.push_back(coefficient);
            }
            else
            {
                coefficient = readInt("Enter answer of the equation: ");
                coeff.push_back(coefficient);
            }
        }
        matrice.push_back(coeff);
        cout << endl;
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
            coe = 97 + j;
            string coeAsString(1, coe);
            cout << "" << eq[j];
            if (j == eq.size() - 1)
            {
                cout << "";
            }
            else if (j != eq.size() - 2)
            {
                cout << "" << coeAsString << " + ";
            }
            else
            {
                cout << "" << coeAsString << " = ";
            }
        }
        cout << endl;
    }
}

vector<vector<vector<int>>> deleteMatrice(vector<vector<vector<int>>> storage, int systNumToDelete)
{
    vector<vector<vector<int>>> post {};
    for (int i = 0; i < storage.size(); i++)
    {
        if (i != systNumToDelete - 1)
        {
            post.push_back(storage[i]);
        }
    }
    return post;
}

vector<int> solve(vector<vector<int>> matrice)
{
    //placeholder
    return matrice[0];
}

vector<vector<int>> addRow(vector<vector<int>> matrice, int row1Index, int row2Index)
{
    vector<vector<int>> newMatrice {};
    vector<int> newRow {};
    for (int i = 0; i < matrice.size(); i++)
    {
        if (i != row1Index)
        {
            newMatrice.push_back(matrice[i]);
        }
        else
        {
            for (int k = 0; k < matrice[i].size(); k++)
            {
                
                // FINISH THIS: newRow.push_back(matrice[i][k] +);
            }
            newMatrice.push_back(newRow);
        }
    }
    return newMatrice;
}

vector<vector<int>> multiplyRow(vector<vector<int>> matrice, int rowIndex, int factor)
{
    //placeholder
    vector<vector<int>> newMatrice {};
    vector<int> newRow {};
    for (int i = 0; i < matrice.size(); i++)
    {
        if (i != rowIndex)
        {
            newMatrice.push_back(matrice[i]);
        }
        else
        {
            for (int num : matrice[i])
            {
                newRow.push_back(num * factor);
            }
            newMatrice.push_back(newRow);
        }
    }
    return newMatrice;
}
