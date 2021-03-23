#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    void InitMap() {
        int len = enNum.size();
        for (int i = 0; i < len; i++) {
            enMap[enNum[i]] = cnNum[i];
            cnMap[cnNum[i]] = enNum[i];
        }
    }

    bool IsUpChar (char inChar) {                             // isupper(A);
        return inChar >= 'A' && inChar <= 'Z';
    }

    string DoubleStr(string s)
    {
        int len = s.size();
        int i = 1;
        while (i < len) {
            while (!IsUpChar(s[i]) && s[i] != '\0') {       // 找出大写字母的位置，关键点是在以大写字母为分割，然后分三种情况转换
                i++;
            }
            return s.substr(0, i);
        }
        return "ERROR";
    }


    string Translate(const string &input)
    {
        InitMap();
        string ret;
        int len = input.size();
        int i = 0;
        int j = 1;
        while (i < len && j < len) {
            while (!IsUpChar(input[j]) && input[j] != '\0') {   // 找出大写字母的位置
                j++;
            }
            string tempStr = input.substr(i, j - i);
            
            if (enMap[tempStr] != "") {
                string add = enMap[tempStr];
                ret += add;
                i = j;
                j = i + 1; 
            } else if (cnMap[tempStr] != "") {
                string add = cnMap[tempStr];
                ret += add;
                i = j;
                j = i + 1; 
            } else if (tempStr == "Double") {
                i = j;
                j = i + 1;
                string doubleChar = DoubleStr(input.substr(i));
                ret += enMap[doubleChar] + enMap[doubleChar];
                i += doubleChar.size();
                j += doubleChar.size();
            } else {
                return "ERROR";
            }
        }
        return ret;
    }

private:
    unordered_map<string, string> enMap;
    unordered_map<string, string> cnMap;
    vector<string> enNum = {"One","Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Zero"};
    vector<string> cnNum = {"Yi","Er", "San", "Si", "Wu", "Liu", "Qi", "Ba", "Jiu", "Ling"};
};

int main(int argc, const char *argv[])
{
    Solution test;
    string testOne = "SixOneThreeOneDoubleZero";
    string testTwo = "YiLingSanSanJiu";
    string ret = test.Translate(testTwo);
    std::cout << "ret = " << ret << std::endl;
    return 0;
}
