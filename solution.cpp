#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Solution {
public:
    vector<vector<int> > intervals;

    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > now;
        
        sort(intervals.begin(), intervals.end());
        
        now.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= now[now.size()-1][1]) {
                now[now.size()-1][1] = max(intervals[i][1], now[now.size()-1][1]);
            } else {
                now.push_back(intervals[i]);
            }
        }
        
        return now;
    }
};

int main() {
    vector<vector<int> > intervals;
    ifstream in;
    in.open("input.txt", ios::in);

    vector<int> val;

    int count = 0;
    int a;
    while (in >> a){
        count++;
        val.push_back(a);
        if(count % 2 ==0 ) {
            intervals.push_back(val);
            val.pop_back();
            val.pop_back();
        }
    }
    Solution A;
    A.intervals = intervals;
    intervals = A.merge(intervals);

    cout << "[";
    for(int i = 0; i < intervals.size(); i++) {
        cout << "[";
        cout << intervals[i][0] << ", " << intervals[i][1] << "]";
    }
    cout << "]";
    return 0;
}