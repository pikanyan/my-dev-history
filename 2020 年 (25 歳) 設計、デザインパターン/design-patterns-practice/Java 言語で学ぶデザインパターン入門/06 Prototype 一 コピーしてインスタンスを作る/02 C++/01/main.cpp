#include "main.h"

#include "Manager.h"
#include "UnderlinePen.h"
#include "MessageBox.h"



int main()
{
	Manager manager;



	auto upen = std::make_unique<UnderlinePen>('~');
	auto mbox = std::make_unique<MessageBox>('*');
	auto sbox = std::make_unique<MessageBox>('/');

	manager.register_product("strong message", std::move(upen));
	manager.register_product("warning box", std::move(mbox));
	manager.register_product("slash box", std::move(sbox));




	auto p1 = manager.create_product("strong message");
	if (p1)
		p1->use("Hello, world");

	auto p2 = manager.create_product("warning box");
	if (p2)
		p2->use("Hello, world");

	auto p3 = manager.create_product("slash box");
	if (p3)
		p3->use("Hello, world");



	return 0;
}
