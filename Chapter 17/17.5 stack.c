#include <stdio.h>
#include <stdlib.h>
#include "17.5 stack.h"

static void CopyToStack(Item item, Stack * ps);
static void CopyToItem(Stack * ps, Item * item);

void InitializeStack(Stack * ps)
{
	ps->top = 0;
}

bool FullStack(const Stack * ps)
{
	return ps->top == MAXSTACK;
}

bool EmptyStack(const Stack *ps)
{
	return ps->top == 0;
}

bool Push(Item item, Stack * ps)
{
	if (ps->top == MAXSTACK)
		return false;
	else
	{
		CopyToStack(item, ps);
		return true;
	}
}

bool Pop(Item *pitem, Stack * ps)
{
	if (ps->top == 0)
		return false;
	else
	{
		ps->top--;
		CopyToItem(ps, pitem);
		return true;
	}
}

static void CopyToStack(Item item, Stack * ps)
{
	ps->items[ps->top] = item;
	ps->top++;
}

static void CopyToItem(Stack * ps, Item * item)
{
	*item = ps->items[ps->top];
}