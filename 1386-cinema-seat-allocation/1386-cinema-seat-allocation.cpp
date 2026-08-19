class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());

        int ans = 0;
        int i = 0;
        int rowsWithReservation = 0;

        while (i < reservedSeats.size()) {

            int currentRow = reservedSeats[i][0];
            set<int> s;

            while (i < reservedSeats.size() &&
                   reservedSeats[i][0] == currentRow) {

                s.insert(reservedSeats[i][1]);
                i++;
            }

            rowsWithReservation++;

            bool left = !s.count(2) && !s.count(3) &&
                        !s.count(4) && !s.count(5);

            bool middle = !s.count(4) && !s.count(5) &&
                          !s.count(6) && !s.count(7);

            bool right = !s.count(6) && !s.count(7) &&
                         !s.count(8) && !s.count(9);

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        // Rows having no reserved seats
        ans += (n - rowsWithReservation) * 2;

        return ans;
    }
};