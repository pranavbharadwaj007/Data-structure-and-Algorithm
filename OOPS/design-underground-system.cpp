
// Link : https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {
public:
    map<double,pair<string,double>> customer;
    map<pair<string, string>, pair<double, double>> total;
    UndergroundSystem() {
        customer.clear();
        total.clear();
    }
    void checkIn(int id, string stationName, int t) {
        customer[id]={stationName, t};
    }
    void checkOut(int id, string stationName, int t) {
        total[{customer[id].first, stationName}]={total[{customer[id].first, stationName}].first+(t-customer[id].second),total[{customer[id].first, stationName}].second+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return total[{startStation,endStation}].first/total[{startStation,endStation}].second;
    }
};
