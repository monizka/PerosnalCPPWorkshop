// CodingPuzzlePlayground.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "bits/stdc++.h"
#include "MetaCodingPuzzle.h"

int main()
{
    long long result1 = getMaxAdditionalDinersCount(10, 1, 2, vector<long long>({ 2, 6 }));
    std::cout << "expected return value = "  << result1 <<"\n";

    long long result2 = getMaxAdditionalDinersCount(15, 2, 3, vector<long long>({ 11, 6, 14 }));
    std::cout << "expected return value = " << result2 << "\n";

    long long result3 = getMaxAdditionalDinersCount(std::numeric_limits<long long>::max(), std::numeric_limits<long long>::max(), 0, vector<long long>());
    std::cout << "Expected Return Value = " << result3 << "\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
