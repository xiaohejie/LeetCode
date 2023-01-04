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
//		//++���ü���
//		void AddRef()
//		{
//			_pmutex->lock();
//			(*_pcount)++;
//			_pmutex->unlock();
//		}
//		//--���ü���
//		void ReleaseRef()
//		{
//			_pmutex->lock();
//			bool flag = false;
//			if (--(*_pcount) == 0) //���������Դ��Ӧ�����ü���--
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
//			if (_ptr != sp._ptr) //����ͬһ��ռ�Ķ���֮��������и�ֵ����
//			{
//				ReleaseRef();         //���������Դ��Ӧ�����ü���--
//				_ptr = sp._ptr;       //��sp����һͬ����������Դ
//				_pcount = sp._pcount; //��ȡsp����������Դ��Ӧ�����ü���
//				_pmutex = sp._pmutex; //��ȡsp����������Դ��Ӧ�Ļ�����
//				AddRef();             //����һ���������������Դ�����ü���++
//			}
//			return *this;
//		}
//		//��ȡ���ü���
//		int use_count()
//		{
//			return *_pcount;
//		}
//		//������ָ��һ��ʹ��
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;        //�������Դ
//		int* _pcount;   //�������Դ��Ӧ�����ü���
//		mutex* _pmutex; //�������Դ��Ӧ�Ļ�����
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
//	cout << p.use_count() << endl; //Ԥ�ڣ�1
//
//	return 0;
//}