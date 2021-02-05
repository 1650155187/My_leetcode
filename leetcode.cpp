#include <iostream>
#include <vector>
using namespace std;

class TenderSystem {
public:
    TenderSystem() {}
    vector<vector<int>> vec;
    
    void AddTender(int userId, int projectId, int price)
    {
        for (auto &element : vec) {
            if (element[0] == userId && element[1] == projectId) {
                return;
            }
        }
        vector<int> temp;
        temp.push_back(userId);
        temp.push_back(projectId);
        temp.push_back(price);
        vec.push_back(temp);
    }

    int UpdateTender(int userId, int projectId, int price)
    {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i][0] == userId && vec[i][1] == projectId) {
                vec.erase(vec.begin() + i);
                vector<int> temp;
                temp.push_back(userId);
                temp.push_back(projectId);
                temp.push_back(price);
                vec.push_back(temp);
                return vec[i][2];
            }
        }
        return -1;
    }

    int RemoveTender(int userId, int projectId)
    {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i][0] == userId && vec[i][1] == projectId) {
                vec.erase(vec.begin() + i);
                return vec[i][2];
            }
        }
        return -1;
    }

    int QueryTender(int projectId, int price)
    {
        int minPrice = INT_MAX;
        int ret;
        for (auto &element : vec) {
            if (element[1] == projectId && element[2] > price) {
                if (element[2] < minPrice) {
                    minPrice = element[2];
                    ret = element[0];
                }
            }
        }
        return ret;
    }
};

int main(int argc, const char *argv[])
{
    std::cout << "Hello World" << std::endl;
    return 0;
}
