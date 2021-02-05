# My_leetcode

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

    int main()
    {
        Solution obj;
        vector<Package> records = {{9, 1, 1, 5, "world"}, {9, 0, 0, 5, "hello"}};
        int packageType = 9;
        cout << obj.ReassembleData(records, packageType) << endl;
        return 0;
    }
