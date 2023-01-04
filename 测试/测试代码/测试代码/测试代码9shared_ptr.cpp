//#include<iostream>
//#include<thread>
//#include<mutex>
//using namespace std;
//namespace cl
//{
//	template<class T>
//	class shared_ptr
//	{
//	private:
//		//++引用计数
//		void AddRef()
//		{
//			_pmutex->lock();
//			(*_pcount)++;
//			_pmutex->unlock();
//		}
//		//--引用计数
//		void ReleaseRef()
//		{
//			_pmutex->lock();
//			bool flag = false;
//			if (--(*_pcount) == 0) //将管理的资源对应的引用计数--
//			{
//				if (_ptr != nullptr)
//				{
//					cout << "delete: " << _ptr << endl;
//					delete _ptr;
//					_ptr = nullptr;
//				}
//				delete _pcount;
//				_pcount = nullptr;
//				flag = true;
//			}
//			_pmutex->unlock();
//			if (flag == true)
//			{
//				delete _pmutex;
//			}
//		}
//	public:
//		//RAII
//		shared_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//			, _pcount(new int(1))
//			, _pmutex(new mutex)
//		{}
//		~shared_ptr()
//		{
//			ReleaseRef();
//		}
//		shared_ptr(shared_ptr<T>& sp)
//			:_ptr(sp._ptr)
//			, _pcount(sp._pcount)
//			, _pmutex(sp._pmutex)
//		{
//			AddRef();
//		}
//		shared_ptr& operator=(shared_ptr<T>& sp)
//		{
//			if (_ptr != sp._ptr) //管理同一块空间的对象之间无需进行赋值操作
//			{
//				ReleaseRef();         //将管理的资源对应的引用计数--
//				_ptr = sp._ptr;       //与sp对象一同管理它的资源
//				_pcount = sp._pcount; //获取sp对象管理的资源对应的引用计数
//				_pmutex = sp._pmutex; //获取sp对象管理的资源对应的互斥锁
//				AddRef();             //新增一个对象来管理该资源，引用计数++
//			}
//			return *this;
//		}
//		//获取引用计数
//		int use_count()
//		{
//			return *_pcount;
//		}
//		//可以像指针一样使用
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;        //管理的资源
//		int* _pcount;   //管理的资源对应的引用计数
//		mutex* _pmutex; //管理的资源对应的互斥锁
//	};
//}
//void func(cl::shared_ptr<int>& sp, size_t n)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		cl::shared_ptr<int> copy(sp);
//	}
//}
//int main()
//{
//	cl::shared_ptr<int> p(new int(0));
//
//	const size_t n = 1000;
//	thread t1(func, p, n);
//	thread t2(func, p, n);
//
//	t1.join();
//	t2.join();
//
//	cout << p.use_count() << endl; //预期：1
//
//	return 0;
//}