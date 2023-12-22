class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
          int i, j, min_idx,n=heights.size();
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (heights[j] < heights[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(heights[min_idx], heights[i]);
            swap(names[min_idx],names[i]);
    }
    reverse(names.begin(),names.end());
    return names;
    }
};