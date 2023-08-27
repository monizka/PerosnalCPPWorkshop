#pragma once

#include "bits/stdc++.h"
using namespace std;

#pragma region Warmup
string getWrongAnswers(int N, string C);

// C++ 20
//#include <ranges>

double getHitProbability(int R, int C, vector<vector<int>> G);
#pragma endregion

#pragma region Level 1

/// <summary>
/// 
/// </summary>
/// <param name="N">Number of seats</param>
/// <param name="K">Distancing guideline</param>
/// <param name="M">Number of current diners</param>
/// <param name="S">Seat number of diners</param>
/// <returns></returns>
long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S);

#pragma endregion