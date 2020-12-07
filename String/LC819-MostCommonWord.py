class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        # avoid repeating in banned
        banned_word = set(banned)
        # ans
        ans = ""
        # track the largest count
        max_count = 0
        # store the word counts
        word_count = defaultdict(int)
        # a buffer for each word
        word_buffer = []
        
        # loop through this paragraph
        for i, char in enumerate(paragraph):
            # extract each word
            if char.isalnum():
                word_buffer.append(char.lower())
                if i != len(paragraph) - 1:
                    continue
            # at the end of each word or the end of the paragraph
            if len(word_buffer) > 0:
                word = "".join(word_buffer)
                if word not in banned_word:
                    word_count[word] += 1
                    if word_count[word] > max_count:
                        max_count = word_count[word]
                        ans = word
                # reset the buffer for next word
                word_buffer = []
        
        return ans
            
