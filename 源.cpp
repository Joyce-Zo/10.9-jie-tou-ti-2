#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#pragma pack(4)	// 设置默认对齐数
struct s1
{
	char a;	 // 1
	double b;// 4-12  共12
};
#pragma pack()	// 取消设置的默认对齐数

 设置默认对齐数为1
#pragma pack(1)	// 设置默认对齐数
struct s1
{
	char a;	 // 1
	double b;// 1-9  共9
};
int main()
{
	struct s1 s;
	printf("%d ", sizeof(s));
	return 0;
}
#include<stddef.h>
struct s
{
	char a;
	int b;
	double c;
};
int main()
{
	printf("%d ", offsetof(struct s, a));	//0
	printf("%d ", offsetof(struct s, b));	//4
	printf("%d ", offsetof(struct s, c));	//8
	return 0;
}

struct S
{
	char a;
	int b;
	double c;
};
void Init1(struct S tmp)
{
	tmp.a = (char)"Joyce";
	tmp.b = 666;
	tmp.c = 6.88;
}
void Init2(struct S* tmp)
{
	tmp->a ='E';
	tmp->b = 666;	// 传址操作，不过要用->访问元素，不能是.
	tmp->c = 6.88;
}
void Print1(struct S tmp)
{
	printf("%c\n%d\n%lf\n", tmp.a, tmp.b, tmp.c);
}
void Print2(const struct S* tmp)
{
	printf("%c\n%d\n%lf\n", tmp->a, tmp->b, tmp->c);
}
int main()
{
	struct S s={0};
	Init1(s); // 此为传值操作，改变了tmp的值，不过不改变结构体S的内容
	Init2(&s);  // 传址操作，改变原结构体S
	Print1(s);	// 传过去内容如果过大，可能会压栈降低性能，安全不会被修改
	Print2(&s); // 无论传什么结构体，都只有4/8字节，如果不安全，可以在结构体前加const
	s.a = (char)"Joyce";
	s.b = 666;
	s.c = 6.88;
	printf("%d", s.b);
	
	return 0;
}