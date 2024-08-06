// MeetingScheduler.cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Timings {
public: 
    int start;
    int end;
    int pos;
    Timings(int s, int e, int p)
    : start(s), end(e), pos(p) {}
};

class Person {
    vector<Timings> t;
public:
    static bool compare(const Timings &a, const Timings &b) {
        return a.end < b.end;
    }

    void res(int start[], int end[], int n) {
        for(int i = 0; i < n; i++) {
           t.push_back(Timings(start[i], end[i], i + 1));
        }

        sort(t.begin(), t.end(), compare);

        int free = t[0].end;
        int c = 1;
        vector<int> results;
        results.push_back(t[0].pos);

        for(int i = 1; i < t.size(); i++) {
            if(t[i].start >= free) {
                results.push_back(t[i].pos);
                c++;
                free = t[i].end;
            }
        }

        for(int i = 0; i < results.size(); i++) {
            cout << results[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int start[] = {1, 3, 0, 5, 8, 5}; 
    int end[] =  {2, 4, 6, 7, 9, 9};

    Person p;
    int n = sizeof(start) / sizeof(start[0]);
    p.res(start, end, n);

    return 0;
}
