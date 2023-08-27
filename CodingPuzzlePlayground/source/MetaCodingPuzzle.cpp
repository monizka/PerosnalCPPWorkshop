#include "MetaCodingPuzzle.h"
using namespace std;

#pragma region Warmup
string getWrongAnswers(int N, string C)
{
    // Write your code here
    string outString = string();

    for (int i = 0; i < N; i++)
    {
        if (C[i] == 'A')
        {
            outString.push_back('B');
        }
        else if (C[i] == 'B')
        {
            outString.push_back('A');
        }
        else
        {
            return "";
        }
    }
    return outString;
}

double getHitProbability(int R, int C, vector<vector<int>> G)
{
    int element_sum = 0;

    // C++ 20
    //for (int i : std::views::iota(0,R))
    //{
    //    for (int j : std::views::iota(0, C))
    //    {
    //        element_sum = G[i][j];
    //    }
    //}

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            element_sum += G[i][j];
        }
    }

    return (double)element_sum / (R * C);
}
#pragma endregion

#pragma region Level 1
long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S)
{
    if (N == K)
        return 0;

    // Create a lambda function to cound available seat within range
    auto countAvailableSeat= [&](float from, float to) 
    {
        if (from > to)
            return 0LL;

        float emptySeatCount = (to - from) + 1;
        return static_cast<long long>(ceil( emptySeatCount / (K + 1) ) );
    };

    if (M == 0)
        return countAvailableSeat(1, N);

    std::set<long long> occupiedSeats(S.begin(), S.end());

    long long maxAdditionalDinersCount = 0LL;
    long long leftAvailableSeatNum = 1LL;

    for (const long long dinerSeatNum : occupiedSeats)
    {
        long long leftOccupied = max((dinerSeatNum - K), leftAvailableSeatNum);
        long long rightOccupied = dinerSeatNum < (N - K) ? (dinerSeatNum + K) : N;

        maxAdditionalDinersCount += countAvailableSeat(leftAvailableSeatNum, leftOccupied - 1);
        if (rightOccupied == N)
            return maxAdditionalDinersCount;
        
        leftAvailableSeatNum = rightOccupied + 1;
    }

    maxAdditionalDinersCount += countAvailableSeat(leftAvailableSeatNum, N);

    return maxAdditionalDinersCount;
}
#pragma endregion