class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        # One single index mapping
        map_index = {}
        # Split the word
        words = s.split()
        
        # The must have the same length to be matched
        if len(pattern) != len(words):
            return False
        
        # Built the index mapping and check the validity
        for i in range(len(words)):
            c = pattern[i]
            w = words[i]
            
            # Transfer the keys to two different formats to separate them
            char_key = 'char_{}'.format(c)
            char_word = 'word_{}'.format(w)
            
            # if not in, then create them
            if char_key not in map_index:
                map_index[char_key] = i
            
            if char_word not in map_index:
                map_index[char_word] = i
            
            # check the index matching or not
            if map_index[char_key] != map_index[char_word]:
                return False
        
        return True
        
                
