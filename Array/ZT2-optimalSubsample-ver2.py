import numpy as np

def emd1D(w, v):
    """
    This code calculates the 1D emd
    under the assumption that w and v are sorted increasingly.

    Assuming we have a series of data:
    x = (X, w), and y = (Y, v) in 1D, 
    where X, Y are the index and w, v are the value.
    emd1D is calculated based on equation:
    emd1D = sum(E_k, k = 1, 2, ..., m + n - 1) / wsum,
    where E_k is calculated over the interval (r_k, r_k+1),
    E_k = dist(r_k, r_k+1) * dist(W(r_k), V(r_k)),
    m, n are the length of w, v, respectively.

    This implementation choose groud distance equal to the L1 distance.
    """
    m, n = len(w), len(v)
    # work is used to represent the sum of E_k
    # first increment of work will be 0
    work = wsum = vsum = r = 0
    # i, j is the index and xnext, ynext is the coordinate
    i = j = 0
    xnext, ynext = 1, 1
    # loop until we finished all lists
    while (i < m or j < n):
        if xnext <= ynext:
            # if xnext is smaller, we increment x
            work += abs(wsum - vsum) * (xnext - r)
            wsum += w[i]
            r = xnext
            i += 1
            if i < m:
                xnext += 1
            else:
                xnext = float('inf')
        else:
            # and if ynext is smaller, we increment y
            work += abs(wsum - vsum) * (ynext - r)
            vsum += v[j]
            r = ynext
            j += 1
            if j < n:
                ynext += 1
            else:
                ynext = float('inf')
    return work / vsum

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

    # the output subset
    res = []
    # we must include two extremes, so we need to pick n-2 points within
    # pick is the index of these points
    pick = [i * (k - 2) // (n - 2) for i in range(1, n - 1)]
    # initialize the min_dist
    min_dist = emd1D([all_samples[i] for i in pick], all_samples)
    # this flag is used to find out whether we got the set that minimize the dist or not
    flag = True
    while flag:
        next_pick = pick
        for i in range(len(pick)):
        # for each location in our current pick, we try to move it one step left and right
        # till we meet a location that is new to our current pick and within the two extremes
        # and we found the moving direction that minimize the min_dist over all moves of locations.
            curr_index = pick[i]

            # search left
            curr_left = curr_index - 1
            while curr_left > 0 and curr_left in pick:
                curr_left -= 1
            if curr_left > 0:
                # if we found a valid location to the left, check the dist using new locations
                curr_pick = pick
                curr_pick[i] = curr_left
                curr_dist = emd1D([all_samples[int(i)] for i in curr_pick], all_samples)
                if curr_dist < min_dist:
                    next_pick = curr_pick
                    min_dist = curr_dist

            # search right
            curr_right = curr_index + 1
            while curr_right < k - 1 and curr_right in pick:
                curr_right += 1
            if curr_right < k - 1:
                # if we found a valid location to the left, check the dist using new locations
                curr_pick = pick
                curr_pick[i] = curr_right
                curr_dist = emd1D([all_samples[int(i)] for i in curr_pick], all_samples)
                if curr_dist < min_dist:
                    next_pick = curr_pick
                    min_dist = curr_dist
        
        if next_pick == pick:
            # if next_pick does not change, means we found the minimum
            flag = False
    
    return [all_samples[0]] + [all_samples[int(i)] for i in sorted(next_pick)] + [all_samples[-1]]


