long digitSum(long n) {
	long sum = 0;
	while (n) {
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

int findSum(vector<long> arr, int n) {
	unordered_map<long, long> mp;
	long ans = -1;

	for (long i = 0; i < in; i++) {
		long dSum = digitSum(arr[i]);
		if (mp[dSum] != 0) {
			ans = max(ans, mp[dSum] + arr[i]);
		}
		mp[dSum] = max(mp[dSum], arr[i]);
	}
	return ans;
}