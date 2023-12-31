#define  _CRT_SECURE_NO_WARNINGS
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;
//检查容量
void CheckCapacity(Stack* ps)
{
	if (ps->_capacity == ps->_top)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
	}
}

//初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType*)calloc(4, sizeof(STDataType));
	ps->_top = 0;
	ps->_capacity = 4;
}

//入栈
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_a[ps->_top] = x;
	ps->_top++;
}
//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;
	}
	ps->_top--;
}

//获取栈顶数据
STDataType StackTop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		printf("stack no data!\n");
		return (STDataType)0;
	}
	return ps->_a[ps->_top - 1];
}

//获取栈中元素有效个数
STDataType StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
//检测栈是否为空，空为1，非空为0
STDataType StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//销毁栈
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a)
	{
		free(ps->_a);
		ps->_capacity = 0;
		ps->_top = 0;
	}
}
bool isValid(char* s) {
	Stack S;
	StackInit(&S);
	bool match = true;
	while (*s != '\0')
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&S, *s);
			s++;
		}
		else
		{
			if (StackEmpty(&S))
			{
				match = false;
				break;
			}
			else
			{
				char ch = StackTop(&S);
				if ((ch == '(' && *s == ')')
					|| (ch == '{' && *s == '}')
					|| (ch == '[' && *s == ']'))
				{
					StackPop(&S);
					s++;
				}
				else
				{
					match = false;
					break;
				}
			}
		}
	}
	if (match == true)
	{
		match = StackEmpty(&S);
	}
	StackDestory(&S);
	return match;
}