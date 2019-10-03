﻿// STL_4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

int main()
{
	//一 分配器概述：和容器紧密关联，一起使用
	//确切的说：内存分配器，扮演内存池的角色，通过大量减少对malloc()调用，来节省内存，甚至还有一定的分配效率的提高
	//经过测试，allocator这个c++标准库提供的缺省的内存分配器压根没有使用内存池的工作机制，可能只是用了malloc()


	//二：分配器的使用
	//allocator分配器，是个类模板，外贸写代码时极少会直接用到这个allocator这种容器的分配器
	//但从语法上来讲，allocator分配器是能够被直接编码使用的

	std::allocator<int> aalloc; //定义一个aalloc对象，为类型为int的对象分配内存
	int *p = aalloc.allocate(3);  //用来分配一段原始的未构造的内存，这段内存能保存3个类型为int的对象(12字节)
	int *q = p;
	*q = 1; q++;
	*q = 2; q++;
	*q = 3;
	aalloc.deallocate(p, 3); //用于释放内存，要记住分配了几个对象，释放时要释放正确个数

	//三 其他的分配器及原理

	//四 自定义分配器

    std::cout << "Hello World!\n"; 
}