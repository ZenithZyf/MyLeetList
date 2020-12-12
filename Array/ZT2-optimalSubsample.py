import numpy as np
from scipy.stats import wasserstein_distance
from itertools import combinations

def optimalSubsample(all_samples, n):
    """
    The purpose of this code is to find "most evenly distributed"
    sample locations given a set of randomly located samples.
    Since the locations are Random and our data is Discrete,
    I will use classical probability to treat the probability each
    sample location is selected in all_samples.
    That said, if there are 5 samples in all_samples, the propability
    of choosing each sample is 1/5.

    Then I will define the "evenly distributed" as the distance between
    the subset and all_samples. Here, I use wasserstein's distance as the
    metric. Using wasserstein's distance, I can measure how close is the
    subset distribution and the all_samples distribution.

    And if we want to select more than two sample locations (n >= 2),
    we will always include two extreme ends.

    Inputs:
    all_samples: a python list
    n: int
    Output:
    res: a python list
    """

    k = len(all_samples)
    # if input is empty or we do not select subset
    if k == 0 or n == 0:
        return []
    # if the sample we want is more than we have
    if n >= k:
        return all_samples
    # if we only need one sample, I choose to return the element in the middle
    if n == 1:
        return [all_samples[k // 2]]
    # if we need to select two samples, then we choose the two extreme ends
    if n == 2:
        return [all_samples[0]] + [all_samples[-1]]

    # all possible combinations except two extreme ends
    comb = combinations(all_samples[1:-1], n - 2)
    # initial min_dist as inf
    min_dist = float("inf")
    # the output subset
    res = []
    # check all combinations and find the minimum one
    for i in list(comb):
        # always have two extreme points
        temp_list = [all_samples[0]] + list(i) + [all_samples[-1]]
        temp_dist = wasserstein_distance(all_samples, temp_list)
        # if the distance is smaller
        if temp_dist < min_dist:
            min_dist = temp_dist
            res = temp_list

    return res
