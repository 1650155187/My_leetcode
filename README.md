# My_leetcode
#include <bits/c++config.h>
#include <corecrt.h>
#include <ios>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;

struct Package {
    int fragType; // 数据类型
    int fragOffset; // 分段序号
    int finish; //  结束标志
    int length; // 长度
    string data; // 数据
};



class Comp {
public:
    bool operator()(const Package& a, const Package& b)
    {
        return a.fragOffset < b.fragOffset;
    }
};

class Solution {
public:
    // 待实现函数,在此函数中填入答题代码;
    static bool cmp(const Package& a, const Package& b)
    {
        return a.fragOffset < b.fragOffset;
    }
    
    string ReassembleData(const vector<Package> &records, int packageType)
    {
        set<Package, Comp> setPackages;
        for (int i = 0; i < records.size(); i++) {
            if (records[i].fragType == packageType) {
                if (records[i].data.length() == records[i].length) {
                    setPackages.insert(records[i]);
                }
            }
        }

        auto first = setPackages.begin();
        auto last = setPackages.rbegin();
        if ((setPackages.empty()) || (!last->finish) || (first->fragOffset + setPackages.size() - 1 != last->fragOffset)) {
            return "NA";
        }
        string result;
        for (auto ptr = setPackages.begin(); ptr != setPackages.end(); ptr++) {
            result += ptr->data;
        }
        
        return result;
    }
};

    

int main()
{
    Solution obj;
    vector<Package> records = {{9, 1, 1, 5, "world"}, {9, 0, 0, 5, "hello"}};
    int packageType = 9;
    cout << obj.ReassembleData(records, packageType) << endl;
    return 0;
}
