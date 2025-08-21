#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> adjacency[numCourses];
        vector<int> prereqRemain(numCourses, 0);
        vector<int> output;
        queue<int> q;

        for (vector<int> prereq : prerequisites) {
            prereqRemain[prereq[0]]++;
            adjacency[prereq[1]].push_back(prereq[0]);
        }

        for (int i = 0; i < prereqRemain.size(); i++) {
            if (prereqRemain[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            output.push_back(course);
            for (int depCourse : adjacency[course]) {
                prereqRemain[depCourse]--;
                if (prereqRemain[depCourse] == 0) {
                    q.push(depCourse);
                }
            }
        }

        if (output.size() < numCourses) {
            return false;
        }

        return true;
    }
};