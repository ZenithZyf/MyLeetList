class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if len(timeSeries) == 0:
            return 0
        
        ans = 0
        
        for i in range(1, len(timeSeries)):
            if timeSeries[i] >= timeSeries[i - 1] + duration:
                ans += duration
            else:
                ans += timeSeries[i] - timeSeries[i - 1]
                
        return ans + duration
