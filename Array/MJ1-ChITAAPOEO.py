# Python3 code to find one array is permutation of another array or not
from collections import defaultdict

# Return true if arr1 and arr2 are permutations of each other
def arePermutations(arr1, arr2):
    # First, they should have same length
    if (len(arr1) != len(arr2)):
        return False
    
    # Creates an empty hashMap hM
    hM = defaultdict(int)
    
    # Traverse through the first array and add elements to hashmap
    for i in range(len(arr1)):
        x = arr1[i]
        hM[x] += 1
    
    # Traverse through the second array and check every element's existence in hM
    for i in range(len(arr2)):
        x = arr2[i]
        if x not in hM or hM[x] == 0:
            return False
        hM[x] -= 1
    
    return True
