// Implementation of observer design pattern in C++

#include <iostream>
#include <vector>

using namespace std;

class observer;

class subject
{
	int value;		// State of subject will be observed if value is changed.
	vector<observer*> registered_observer_list;		// Contains list of observers
public:
	void register_observer(observer* obs)
	{
		registered_observer_list.push_back(obs);	// Observer will register
	}

	int get_value()
	{
		return value;
	}

	void set_value(int new_value)
	{
		value = new_value;

		// If subject state changes (value changes) then notify to all observer
		notify_all();
	}

	void notify_all();

};

class observer
{
	int val;
	subject* sub;
public:
	observer(int va, subject* su)
	{
		val = va;
		sub = su;

		sub->register_observer(this);
	}

	subject* get_subject()
	{
		return sub;
	}

	int get_observer_value()
	{
		return val;
	}

	virtual void update() = 0;
};

void subject::notify_all()
{
	for (int i = 0; i < registered_observer_list.size(); ++i)
	{
		registered_observer_list[i]->update();
		/*observer* baseptr = registered_observer_list[i];
		baseptr->update();*/
	}
}

class mod_observer : public observer
{
public:
	mod_observer(int va, subject* su) :observer(va, su)
	{

	}

	void update()
	{
		subject* sub = get_subject();
		int v = sub->get_value();
		int mod = this->get_observer_value();

		cout << "value: " << v << "modular: " << mod << " modulus : " << v % mod;
	}
};

class div_observer : public observer
{
public:
	div_observer(int va, subject* su) :observer(va, su)
	{

	}
	void update()
	{
		subject* sub = get_subject();
		int v = sub->get_value();
		int div = this->get_observer_value();

		cout << "value: " << v << "divisior: " << div << " division : " << v / div;
	}
};



int main()
{
	subject sub;
	mod_observer mod_obs1(3, &sub);
	mod_observer mod_obs2(4, &sub);
	div_observer div_obs(5, &sub);

	sub.get_value();
	sub.set_value(10);

	return 0;
}