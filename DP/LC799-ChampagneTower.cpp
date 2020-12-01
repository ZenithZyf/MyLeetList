class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> vol{double(poured)};
        for (int i = 1; i <= query_row; i++) {
            vector<double> tmp(vol.size() + 1, 0);
            if (vol[0] > 1) tmp[0] += (vol[0] - 1) / 2;
            if (vol[vol.size() - 1] > 1) tmp[vol.size()] += (vol[vol.size() - 1] - 1) / 2;
            for (int j = 1; j < vol.size(); ++j)
                tmp[j] += max((vol[j - 1] - 1) / 2, 0.) + max((vol[j] - 1) / 2, 0.);
            vol = tmp;
        }
        return min(vol[query_glass], 1.);
    }
};
