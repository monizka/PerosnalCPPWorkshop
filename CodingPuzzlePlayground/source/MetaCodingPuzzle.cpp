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

#define SEAT_OCCUPIED false
#define SEAT_EMPTY true

#pragma region Level 1
long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S)
{
    constexpr long long llongMax = std::numeric_limits<long long>::max();

    unordered_map<long long, bool> seatAvailabilityMap;


    // Update seat status with diners
    for (int i = 0; i < M; ++i)
    {
        long long dinerSeatId = S[i] - 1LL;
        long long minDistancingBlockId = std::max(dinerSeatId - K, 0LL);
        long long maxDistancingBlockId = dinerSeatId < llongMax - K ?
            std::min(dinerSeatId + K, N) :
            llongMax;


        for (long long j = minDistancingBlockId; j <= maxDistancingBlockId; ++j) {
            seatAvailabilityMap[j] = SEAT_OCCUPIED;
        }
    }

    long long maxAdditionalDinersCount = 0;
    // counting maximum additional diners count
    for (long long i = 0; i < N; ++i)
    {
        if (seatAvailabilityMap.count(i) < 1 || seatAvailabilityMap[i])
        {
            maxAdditionalDinersCount++;
            i += K;
        }
    }

    return maxAdditionalDinersCount;
}
#pragma endregion