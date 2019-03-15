class A
{
private:
	int x;
public:
	virtual void fun1()
	{
	}

	void fun2()
	{
	}
};

class B : public A
{

	int y;
public:
	virtual void fun1()
	{
	}

	void fun3()
	{
	}

	virtual void fun4()
	{
	}
};

class C : public B
{

};