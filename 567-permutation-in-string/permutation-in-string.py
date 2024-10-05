class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        n1 = len(s1)
        n2 = len(s2)
        
        # If s1 is longer than s2, s2 cannot contain a permutation of s1
        if n1 > n2:
            return False
        
        # Frequency maps for characters in s1 and the current window in s2
        freq_s1 = [0] * 26
        window_freq = [0] * 26
        
        # Fill the frequency map for s1
        for ch in s1:
            freq_s1[ord(ch) - ord('a')] += 1
        
        # Now, we need to maintain a sliding window of size n1 on s2
        for i in range(n2):
            # Add the current character to the window
            window_freq[ord(s2[i]) - ord('a')] += 1
            
            # If the window size exceeds n1, remove the leftmost character
            if i >= n1:
                window_freq[ord(s2[i - n1]) - ord('a')] -= 1
            
            # If the window matches the frequency of s1, return True
            if window_freq == freq_s1:
                return True
        
        return False
