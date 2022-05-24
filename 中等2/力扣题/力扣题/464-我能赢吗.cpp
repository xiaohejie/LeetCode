#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
    
*/
class Solution {
public:
    //����¼����¼number��û���жϹ�
    unordered_map<int, bool> memo;
    //maxChoosableInteger����ѡ����������desiredTotal��˭�ȴﵽ��ֵ��usedNumbers���Ѿ�ʹ�ù�������currentTotal��Ŀǰ�ĺ�
    bool backTrack(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal) {
   //����usedNumbers�Ƚ�����⣬��Ϊʹ�õĶ����Ʊ�ʾ����ΪmaxChoosableInteger���ֻ��20λ
      //usedNumbers | (1 << i)
        //���memo��û�и�usedNumbers
        if (!memo.count(usedNumbers)) {
            bool res = false;           //ʹ��usedNumber�Ľ��
            //����
            for (int i = 0; i < maxChoosableInteger; i++) {
                if (((usedNumbers >> i) & 1) == 0) {        //�жϸ�����û�б�ʹ�ù�
                    //�����ǰ������i+1����desiredTotal����Ϊtrue��
                    if (i + 1 + currentTotal >= desiredTotal) {
                        res = true;
                        break;
                    }
                    //����һ��ѡ��
                    if (!backTrack(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i + 1)) {
                        res = true;
                        break;
                    }
                }
            }
            memo[usedNumbers] = res;
        }
        //�еĻ���ֱ�ӷ���memo[usedNumber]
        return memo[usedNumbers];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        //��������Ӷ�С��desiredTotal�� ֱ�ӷ���false��
        if ((maxChoosableInteger * (maxChoosableInteger+1)) / 2 < desiredTotal) {
            return false;  
        }
        //����ʹ�õݹ�
        return backTrack(maxChoosableInteger, 0, desiredTotal, 0);
    }
};