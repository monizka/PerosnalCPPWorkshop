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
    // Prevent overflow for K
    if (N == K)
        return 0;

    // Create a lambda function to count available seat within range
    auto countAvailableSeat= [&](double from, double to) 
    {
        if (from > to)
            return 0LL;

        double emptySeatCount = (to - from) + 1;
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



long long getMaxAdditionalDinersCount2(long long N, long long K, int M, vector<long long> S)
{
    sort(S.begin(), S.end());

    long long count = 
        // Number of people who can sit before the first 
        max(static_cast<long long>(ceil((S[0] - K - 1) / static_cast<double>(K + 1))), 0LL) + 
        // and after the last person already sitting
        max(static_cast<long long>(ceil((N - (S[M - 1] + K + 1) + 1) / static_cast<double>(K + 1))), 0LL);

    int i = 0;
    // Calculate for all the allowed spaces between people
    while (i < M - 1) {
        long long start = S[i] + K + 1;
        long long end = S[++i] - K - 1;
        count += static_cast<long long>(ceil((end - start + 1) / static_cast<double>(K + 1)));
    }

    return count;
}

#pragma endregion

#pragma region Level 4
double getMinExpectedHorizontalTravelDistance(int N, vector<int> H, vector<int> A, vector<int> B) 
{
    // Write your code here
    return 0.0;
}
#pragma endreigon