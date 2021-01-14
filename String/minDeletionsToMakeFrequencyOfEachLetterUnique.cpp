int solution(const string& s) {
	// counter of characters to delete
	int count = 0;
	// array of counters of occurrences for all possible characters
	vector<int> occurrences('z' - 'a', 0);
	// count the occurrences
	for (char c : s) {
		++occurrences[c - 'a'];
	}

	priority_queue<int> pq;
	// put non-zero occurrences into the priority queue
	for (int c : occurrences) {
		if (c != 0) {
			pq.push(c);
		}
	}

	while (!pq.empty()) {
		// take the biggest frequency of a character
		int most_frequent = pq.top(); pq.pop();

		if (pq.empty()) {
			return count;
		}
		if (most_frequent == pq.top()) {
			if (most_frequent > 1) {
				pq.push(most_frequent - 1);
			}
			count++;
		}
	}
	return count;
}