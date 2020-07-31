

#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<iostream>
#pragma warning(disable:4996)

#define debug1 SB
using namespace std;

int i = 0, j = 0,k=1;


char temp[10];//临时存数字字符的 
stack <char> operand;
stack<long int> num;
void push(char *a);
int prio(char temp);//东东写的优先级，去掉了（）
void judopd(char *a,int i);//判断什么时候该计算了 determine when to calculate
void cal();//计算
long int calrule();//计算规则

int main()
{

	char s[100];
	while (1)
	{   
		gets_s(s, sizeof(s));
		push(s);//push是把操作符和操作数分别入栈的函数
#if undef debug1
		while (!num.empty())
		{
			printf("%ld\n", num.top());
			num.pop();

		}
# endif
		printf("%ld\n", num.top());
	}
		system("pause");
		return 0;
}




void push(char *a)
{
	
	long int real;//转成真的数字  Transfer the string into the real numbers

	while (a[i] != '\0')
	{
		if (a[i] <= '9'&& a[i] >= '0')
		{
			temp[j++] = a[i];


		}
		else
		{
			if (temp[0] != '\0')
			{
				real = strtoul(temp, 0, 10);
				num.push(real);
				j = 0;
				memset(temp, '\0', 10);
			}//清空数组
		
				judopd(a,i);
			


		}
		i++;
	}
}


void judopd(char *a,int i)
{ 
	if ( i != 1 && prio(a[i]) == 1 && prio(operand.top()) == 2 )
	{	
		cal(); 
		operand.push(a[i]);
	}
	else if (a[i] == ')')
	{
		while (operand.top() != '(')
		{
			cal();	

		}		operand.pop();
	}
	else if (a[i] == '=')
	{

		while (!operand.empty())
			cal();

	}
	else
		operand.push(a[i]);
}

long int calrule(char a,long int x,long int y)
{
	if (a == '*')
		return x * y;
	else if (a == '+')
		return x + y;

	else if (a == '-')
		return x - y;

	else if (a == '/')
		return x / y;

}

void cal()
{
	long int x, y;
	char c;

	c = operand.top();
	operand.pop();
	y = num.top();
	num.pop();
	x = num.top();
	num.pop();

	num.push(calrule(c, x, y));

}

int prio(char temp)
{
	int n;
	switch (temp)
	{
	case '+':n = 1; break;
	case '-':n = 1; break;
	case '*':n = 2; break;
	case '/':n = 2; break;

	default:n = 0; break;
	}
	return n;
}

//3*(4+2*(5+5))+2*(4-3)*(2+1)= 78 for test1
//250*(377-77*(7-6))= 75000 for test2

