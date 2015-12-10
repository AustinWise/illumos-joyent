// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <sys/avl.h>

#define OFFSETOF(s, m)          (size_t)(&(((s *)0)->m))

typedef struct myStruct
{
	int firstData;
	avl_node node;
};

int myComparer(const void* a, const void* b)
{
	return reinterpret_cast<const myStruct*>(a)->firstData - reinterpret_cast<const myStruct*>(b)->firstData;
}

int main()
{
	avl_tree_t tree;
	avl_create(&tree, nullptr, sizeof(myStruct), OFFSETOF(myStruct, node));

	myStruct* s = new myStruct();
	s->firstData = 1;
	avl_add(&tree, s);

	s = new myStruct();
	s->firstData = 2;
	avl_add(&tree, s);

	s = reinterpret_cast<myStruct*>(avl_first(&tree));

	printf("struct: %d\n", s->firstData);

    return 0;
}

