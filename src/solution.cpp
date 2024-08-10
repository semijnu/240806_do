#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> aggregate(vector<int>& v) {
    vector<int> agg(v.size(), 0);
    agg[0] = v[0];
    for(int i=1; i<v.size(); i++)
        agg[i]=agg[i-1]+v[i];
    return agg;
}

double standard_deviation(vector<int>& v1, vector<int>& v2) {
    double mean1=0, mean2=0, stddev=0;
    for(int i=0; i<v1.size(); i++)
        mean1 += v1[i];
    for(int i=0; i<v2.size(); i++)
        mean2 += v2[i];
    mean1 /= v1.size();
    mean2 /= v2.size();
    for(int i=0; i<v1.size(); i++)
        stddev += pow(v1[i]-mean1, 2);
    for(int i=0; i<v2.size(); i++)
        stddev += pow(v2[i]-mean2, 2);
    return sqrt(stddev/(v1.size()+v2.size()-2));
}

int main() {
    int size1, size2;
    cout << "Enter the sizes of two vectors: ";
    cin >> size1 >> size2;
    vector<int> v1(size1);
    vector<int> v2(size2);

    cout << "Enter elements of the vectors: ";
    for(int i=0; i<size1; i++)
        cin >> v1[i];
    for(int i=0; i<size2; i++)
        cin >> v2[i];

    v1 = aggregate(v1);
    v2 = aggregate(v2);

    cout << "The standard deviation of the aggregation of two vectors is: " << standard_deviation(v1, v2) << endl;
    return 0;
}