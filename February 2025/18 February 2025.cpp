/*
K Closest Points to Origin
Given an array of points where each point is represented as points[i] = [xi, yi] on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance, defined as:
sqrt( (x2 - x1)2 + (y2 - y1)2 )
Note: You can return the k closest points in any order, driver code will sort them before printing.
*/
class Solution {
    public:
      static bool cmp(vector<int> p1,vector<int> p2)
      {
          int distanceOfP1=p1[0]*p1[0]+p1[1]*p1[1];
          int distanceOfP2=p2[0]*p2[0]+p2[1]*p2[1];
          return distanceOfP1<distanceOfP2;
      }
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          // Your code here
          sort(points.begin(),points.end(),cmp);
          vector<vector<int>> ans(points.begin(),points.begin()+k);
          return ans;
      }
  };