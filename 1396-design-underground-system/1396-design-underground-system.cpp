#include <bits/stdc++.h>
using namespace std;

struct Data{
    string start, end;
    int inTime, outTime;
};

class UndergroundSystem {
  //  {{start, end}, []}
    map<pair<string, string>, vector<int>> locations;
    
    // {{id} : {FromStation, inTime, outTime}}
    map<int, Data> customers;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        Data data;
        data.inTime = t;
        data.start = stationName;
        
        customers[id] = data;
    }
    
    void checkOut(int id, string stationName, int t) {
        Data data = customers[id];
        data.outTime = t;
        data.end = stationName;
        
        locations[{data.start, data.end}].push_back(data.outTime - data.inTime);
      
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto times = locations[{startStation, endStation}];
        double sum = accumulate(times.begin(), times.end(), 0);
        return sum / times.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */