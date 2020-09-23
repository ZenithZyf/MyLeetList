class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        
        int cand1 = nums[0];
        int cont1 = 0;
        int cand2 = nums[0];
        int cont2 = 0;
        
        for (int num : nums) {
            if (cand1 == num) {
                cont1++;
                continue;
            }
            if (cand2 == num) {
                cont2++;
                continue;
            }
            
            if (cont1 == 0) {
                cand1 = num;
                cont1++;
                continue;
            }
            if (cont2 == 0) {
                cand2 = num;
                cont2++;
                continue;
            }
            
            cont1--;
            cont2--;
        }
        
        cont1 = 0;
        cont2 = 0;
        for (int num : nums) {
            if (cand1 == num) cont1++;
            else if (cand2 == num) cont2++;
        }
        
        if (cont1 > nums.size() / 3) res.push_back(cand1);
        if (cont2 > nums.size() / 3) res.push_back(cand2);
        
        return res;
    }
};
