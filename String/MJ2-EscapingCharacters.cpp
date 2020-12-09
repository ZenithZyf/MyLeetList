int escaped = 0;
bool startCnt = false;

// loop through the input string
for (int i = 0; i < s.length(); i++) {
	char c = s.charAt(i);
	// if encountered a '#', we need reverse the flag
	if (c == '#') {
		startCnt = !startCnt;
		continue;
	}
	// if startCnt, and
	// if the previous char is '!' then we need to escape
	if (startCnt && s.charAt(i - 1) == '!') {
		if (islower(c))
			escaped++;
	}
}

return escaped;
