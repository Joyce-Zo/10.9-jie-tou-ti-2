#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#pragma pack(4)	// ����Ĭ�϶�����
struct s1
{
	char a;	 // 1
	double b;// 4-12  ��12
};
#pragma pack()	// ȡ�����õ�Ĭ�϶�����

 ����Ĭ�϶�����Ϊ1
#pragma pack(1)	// ����Ĭ�϶�����
struct s1
{
	char a;	 // 1
	double b;// 1-9  ��9
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
	tmp->b = 666;	// ��ַ����������Ҫ��->����Ԫ�أ�������.
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
	Init1(s); // ��Ϊ��ֵ�������ı���tmp��ֵ���������ı�ṹ��S������
	Init2(&s);  // ��ַ�������ı�ԭ�ṹ��S
	Print1(s);	// ����ȥ����������󣬿��ܻ�ѹջ�������ܣ���ȫ���ᱻ�޸�
	Print2(&s); // ���۴�ʲô�ṹ�壬��ֻ��4/8�ֽڣ��������ȫ�������ڽṹ��ǰ��const
	s.a = (char)"Joyce";
	s.b = 666;
	s.c = 6.88;
	printf("%d", s.b);
	
	return 0;
}