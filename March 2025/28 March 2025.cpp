/*
You are given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. A single person can perform only one activity at a time, meaning no two activities can overlap. Your task is to determine the maximum number of activities that a person can complete in a day.
*/
class Solution {
    public:
      int activitySelection(vector<int> &start, vector<int> &finish)
  {

      // to store results.
      int ans = 0;

      // to store the activities
      vector<vector<int>> arr;

      for (int i = 0; i < start.size(); i++)
      {
          arr.push_back({finish[i], start[i]});
      }

      // sort the activities based on finish time
      sort(arr.begin(), arr.end());

      // to store the end time of last activity
      int finishtime = -1;

      for (int i = 0; i < arr.size(); i++)
      {
          vector<int> activity = arr[i];
          if (activity[1] > finishtime)
          {
              finishtime = activity[0];
              ans++;
          }
      }
      return ans;
  }
  };