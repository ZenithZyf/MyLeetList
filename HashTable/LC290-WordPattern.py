class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        # mapping: pattern to s
        # rmapping: s to pattern
        mapping = dict()
        rmapping = dict()
        # Index for cropping out the corresponding str in s
        start = 0
        end = 0
        # Go through all elements in the pattern
        # and find out the corresponding part same to the mapping or not
        for i in pattern:
            # move end to the space
            while end < len(s) and s[end] != " ":
                end += 1
            # extract the substring
            substr = s[start:end]
            # check the pattern:
            # if pattern in dict, check the word in s is same or not
            # if pattern not in dict, make it
            if i not in mapping:
                mapping[i] = substr
            else:
                if mapping[i] != substr:
                    return False
            # check the reverse mapping:
            if substr not in rmapping:
                rmapping[substr] = i
            else:
                if rmapping[substr] != i:
                    return False
            # Move the start and end to the beginning of next word
            start = end + 1
            end = start
        # I have remaining elements
        if end != len(s) + 1: return False
        return True
                
