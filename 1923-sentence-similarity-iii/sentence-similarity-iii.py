class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2):
        """
        :type sentence1: str
        :type sentence2: str
        :rtype: bool
        """
        # Split the sentences into lists of words
        words1 = sentence1.split()
        words2 = sentence2.split()
        
        # Ensure that words1 is the longer one (if not, swap them)
        if len(words1) < len(words2):
            words1, words2 = words2, words1
        
        # Initialize two pointers for checking prefix and suffix matches
        i, j = 0, 0
        
        # Match words from the start (prefix)
        while i < len(words2) and words1[i] == words2[i]:
            i += 1
        
        # Match words from the end (suffix)
        while j < len(words2) and words1[-(j+1)] == words2[-(j+1)]:
            j += 1
        
        # Check if the non-matching middle part is valid
        return i + j >= len(words2)