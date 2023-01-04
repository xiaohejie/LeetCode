#include<iostream>
#include<vector>
using namespace std;
/*
	816. 模糊坐标
*/
class Solution {
    vector<string> getPos(string s) {
        vector<string> pos;
        //当子字符串的第0个字符不为0或者该子字符串为“0”，则可以将该子字符串直接放入pos中
        if (s[0] != '0' || s == "0") {
            pos.push_back(s);
        }
        //从子字符客串的第1个字符开始遍历，进行小数点划分
        for (int p = 1; p < s.size(); p++) {
            //如果下标不为1并且子字符串的第0个下边为0，就需要跳过（因为不能让0作为开头）
            //或者最后一个字符是“0”，也需要跳过（小数点后不能是0）
            if ((p != 1 && s[0] == '0') || s.back() == '0') {
                continue;
            }
            pos.push_back(s.substr(0, p) + "." + s.substr(p));
        }
        return pos;
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size() - 2;
        vector<string> res;
        s = s.substr(1, s.size() - 2);
        for (int l = 1; l < n; l++) {
            vector<string> lt = getPos(s.substr(0, l));
            if (lt.empty()) continue;
            vector<string> rt = getPos(s.substr(l));
            if (rt.empty()) continue;
            //循环组合遍历
            for (auto& i : lt) {
                for (auto& j : rt) {
                    res.push_back("(" + i + "," + j + ")");
                }
            }
        }
        return res;
    }
};