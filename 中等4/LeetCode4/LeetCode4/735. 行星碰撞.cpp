#include<iostream>
#include<vector>
using namespace std;
/*
	735. ������ײ
        ģ��ջ
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int len = asteroids.size();
        //ʹ��ģ��ջ����
        /*������ʻ�����Ƿ���ջ��������ʻ����վ�����Ԫ�ؽ��бȽ�*/
        for (int i = 0; i < len; i++) {
            bool isBoom = 1;        //��¼�����Ƿ�ը
            while (asteroids[i] < 0 && isBoom && !ans.empty() && ans.back() > 0) {
                isBoom = (asteroids[i] + ans.back() < 0);       //�ж���ȵ�ʱ��(�������Ƕ�Ҫ��ȥ)
                if (asteroids[i] + ans.back() <= 0) {
                    ans.pop_back();
                }
            }
            if (isBoom) {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }










    //��δ���������
    /*
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int len = asteroids.size();
        vector<int> isBoom(len, 1);
        for (int i = 0; i < len; i++) {
            if (asteroids[i] > 0 && isBoom[i]) {
                //�����ƶ�
                for (int j = i+1; j < len; j++) {
                    //����0���߸������Ѿ�������
                    if (asteroids[j] > 0 || isBoom[j] == 0) {
                        continue;
                    }
                    else {
                        //С��0��Ҫ������ײ
                        if (asteroids[i] > abs(asteroids[j])) {
                            isBoom[j] = 0;
                        }
                        else if (asteroids[i] < abs(asteroids[j])) {
                            isBoom[i] = 0;
                            //��������ѭ��
                            break;
                        }
                        else{
                            isBoom[i] = 0;
                            isBoom[j] = 0;
                            break;
                        }
                    }
                }
            }
            else if (asteroids[i] < 0 && isBoom[i]) {
                for (int j = i - 1; j >= 0; j--) {
                    //С��0���߸������Ѿ�������
                    if (asteroids[j] < 0 || isBoom[j] == 0) {
                        continue;
                    }
                    else {
                        //����0��Ҫ������ײ
                        if (abs(asteroids[i]) > abs(asteroids[j])) {
                            isBoom[j] = 0;
                        }
                        else if (abs(asteroids[i]) < abs(asteroids[j])) {
                            isBoom[i] = 0;
                            //��������ѭ��
                            break;
                        }
                        else {
                            isBoom[i] = 0;
                            isBoom[j] = 0;
                            break;
                        }
                    }
                }
            }
        }
        //�ж�
        for (int i = 0; i < len; i++) {
            if (isBoom[i]) {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }*/
};