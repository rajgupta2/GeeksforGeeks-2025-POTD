/*
Minimum Platforms
You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.
At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.
*/
class Solution {
    public:
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          sort(arr.begin(), arr.end());
          sort(dep.begin(), dep.end());
          int j = 0;
          int res = 0;
          int cnt = 0;

      for (int i=0; i<arr.size(); i++) {

          while (j<arr.size() && dep[j]<arr[i]) {
              cnt--;
              j++;
          }

          // one platform for current train
          cnt++;

          res = max(res, cnt);
      }

      return res;
      }
  };