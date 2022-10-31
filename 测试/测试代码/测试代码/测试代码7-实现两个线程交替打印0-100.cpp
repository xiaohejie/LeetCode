#include<iostream>
#include<thread>
#include <condition_variable>
using namespace std;
/*例题：实现两个线程交替打印1-100*/
int main7()
{
	int n = 100;
	mutex mtx;
	condition_variable cv;
	bool flag = true;
	//奇数
	thread t1([&] {
		int i = 1;
		while (i <= 100)
		{
			unique_lock<mutex> ul(mtx);
			cv.wait(ul, [&flag]()->bool {return flag; }); //等待条件变量满足
			cout << this_thread::get_id() << ":" << i << endl;
			i += 2;
			flag = false;
			cv.notify_one(); //唤醒条件变量下等待的一个线程
		}
		});
	//偶数
	thread t2([&] {
		int j = 2;
		while (j <= 100)
		{
			unique_lock<mutex> ul(mtx);
			cv.wait(ul, [&flag]()->bool {return !flag; }); //等待条件变量满足
			cout << this_thread::get_id() << ":" << j << endl;
			j += 2;
			flag = true;
			cv.notify_one(); //唤醒条件变量下等待的一个线程
		}
		});

	t1.join();
	t2.join();
	return 0;
}