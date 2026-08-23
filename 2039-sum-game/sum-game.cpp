class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int sumLeft = 0, sumRight = 0;
        int qLeft = 0, qRight = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                qLeft++;
            else
                sumLeft += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                qRight++;
            else
                sumRight += num[i] - '0';
        }

        // Alice wins if she can force the final sums to be different.
        // Normalize the situation so that the side with more '?' is
        // considered first.
        int diff = sumLeft - sumRight;
        int qDiff = qLeft - qRight;

        if ((qDiff & 1) != 0)
            return true;

        // Bob can draw only if the existing difference can be exactly
        // compensated by the question marks.
        return diff != -(qDiff / 2) * 9;
    }
};