int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
    int dp[daysSize], j, minCost, dayCost, weekCost, monthCost;
    bool day, week, month;
    for (int i = 0; i < daysSize; i++) {
        minCost = 365000;
        day = week = month = true;
        j = i;
        while (1) {
            j--;
            if (j < 0) {
                break;
            }
            if (day && days[i] - days[j] >= 1) {
                dayCost = dp[j] + costs[0];
                minCost = minCost < dayCost ? minCost : dayCost;
                day = false;
            }
            if (week && days[i] - days[j] >= 7) {
                weekCost = dp[j] + costs[1];
                minCost = minCost < weekCost ? minCost : weekCost;
                week = false;
            }
            if (month && days[i] - days[j] >= 30) {
                monthCost = dp[j] + costs[2];
                minCost = minCost < monthCost ? minCost : monthCost;
                month = false;
            }
        }
        if (day) {
            minCost = minCost < costs[0] ? minCost : costs[0];
        }
        if (week) {
            minCost = minCost < costs[1] ? minCost : costs[1];
        }
        if (month) {
            minCost = minCost < costs[2] ? minCost : costs[2];
        }
        dp[i] = minCost;
    }
    return dp[daysSize - 1];
}