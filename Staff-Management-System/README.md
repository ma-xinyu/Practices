# 职工管理系统技术文档
# 2021.1.21 Maxinyu

## c++语言 引入iostream和string and fstream库
### this指针的作用：
	其作用就是指向成员函数所作用的对象， 所以非静态成员函数中可以直接使用 this 来代表指向该函数作用的对象的指针。


## 一、需求分析：
	添加员工、编号、姓名、岗位等
	能进行添加、删除、显示、修改、查找、排序、清空等操作

## 二、写类：
	worker类：员工大类（因为会被各类岗位多态继承，函数写成虚函数），有编号、姓名、岗位属性
	各类岗位：boss manager employee
	workmanager类：调用各函数

## 三、main函数
	一个workmanager类的对象，switch调用不同函数进行操作

## 四、workmanager类中的函数
	1.构造函数：文件存在？是否为空？
		开辟空间，将文件中数据加载到数组中
	2.退出程序：exit(0)
	3.添加成员：
		//添加 计算添加的新空间大小
		int newsize = this->m_num+addnum;
		//开辟新空间
		Worker ** newspace = new Worker * [newsize];
		//将原来的数据拷贝到新空间下
		if (this->m_num!=NULL)
		{
			for (int i=0;i<m_num;i++)//i<this->m_num
			{
				newspace[i]=this->m_Array[i];
			}
		}
		//批量添加新数据

		//释放原来的堆区空间
		delete[]this->m_Array;
		//替换新空间的指向
		this->m_Array=newspace;
		//更新人数
		this->m_num=newsize;
		//更新文件不为空标志
		this->m_fileEmpty=false;

		Worker ** m_Array;//父类指针的指针

		保存

	4.显示全部员工：
		多态
	5.查找
	6.删除：
		数据前移
	7.修改数据
	8.排序
	9.清空
		if(this->m_Array!=NULL)
		{
			//删除堆区的每个职工对象
			for(int i=0;i<this->m_num;i++)
			{
				delete this->m_Array[i];
				this->m_Array[i]=NULL;
			}
			delete[]this->m_Array;
			this->m_Array=NULL;
			this->m_num=0;
			this->m_fileEmpty=true;
		}
		cout<<"清空成功！"<<endl;

	10.析构函数：
		WorkManager::~WorkManager()
		{
			//释放
			if(this->m_Array!=NULL)
			{
				for(int i=0;i<this->m_num;i++)
				{
					if(this->m_Array[i]!=NULL)
					{
						delete this->m_Array[i];
					}
				}//每个元素释放
				delete[]this->m_Array;
				this->m_Array=NULL;
			}
		}