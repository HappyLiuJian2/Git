#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
using namespace std;

//Test : no iostream, can use STL? YES

//当声明的时候不需要初始化，申请内存等
//vector 作为其它数据结构的基础，一般不用来直接实现。
//可以作为一个长度动态的数组，不用申请内存
//like : class Vec; Vec g_vector
vector<int> g_vector;
//Iterator 是一个类，可以定义为全局变量，每次都使用，也可以使用的时候定义
vector<int>::iterator vec_iter;

//stack 不能用iter遍历
//stack 一般用来作为：
//1、括号匹配
//2、中缀计算
//3、后缀转中缀
stack<int> g_stack;

//queue 不能用iter遍历
queue<int> g_queue;

//Prepare : STL vector
//vector is a RB Tree
//insert is slow
//read is fast
int vector_prepare(vector<int> s_vector)
{
	//vector 插入
	g_vector.push_back(10);
	g_vector.push_back(20);
	g_vector.push_back(30);

	//vector 遍历
	for (vec_iter = g_vector.begin(); vec_iter != g_vector.end(); ++vec_iter)
	{
		printf("The vector content is %d\n", *vec_iter);
	}

	//vector 删除
	g_vector.erase(g_vector.begin());

	for (vec_iter = g_vector.begin(); vec_iter != g_vector.end(); ++vec_iter)
	{
		printf("The vector content is %d\n", *vec_iter);
	}

	//判断是否为空
	printf("The g_vec is empty ? %d\n",g_vector.empty());

	//清空
	g_vector.clear();
	printf("The g_vec is empty ? %d\n", g_vector.empty());
	return 0;
}

int stack_prepare(stack<int> s_stack)
{
	//入栈
	s_stack.push(3);
	s_stack.push(6);

	//出栈，返回的void
	s_stack.pop();

	//返回栈顶元素
	cout << "Top of the stack is " << s_stack.top() << endl;

	//栈判空
	cout << "The stack is empty? " << s_stack.empty() << endl;
	return 0;
}

int string_prepare()
{
	string test_string = "Test string ok.";
	unsigned int index = 0;

	cout << "The string is " << test_string << endl;

	//string 遍历也可以用iter,或者用string.at(index)
	for (index = 0; index < test_string.size(); index++)
	{
		cout << "The str in "<< index << "is " << test_string.at(index) << endl;
	}

	//todo string 
	return 0;
}

int queue_prepare(queue<int> s_queue)
{
	//入队
	g_queue.push(1);
	g_queue.push(3);
	g_queue.push(4);

	//队首元素
	cout << "The first ele of the queue is " << g_queue.front() << endl;

	//出队
	g_queue.pop();

	cout << "The first ele of the queue is " << g_queue.front() << " after poo." << endl;
	return 0;
}

int main()
{
	vector_prepare(g_vector);
	stack_prepare(g_stack);
	string_prepare();
	queue_prepare(g_queue);

	system("pause");
	return 0;
}
