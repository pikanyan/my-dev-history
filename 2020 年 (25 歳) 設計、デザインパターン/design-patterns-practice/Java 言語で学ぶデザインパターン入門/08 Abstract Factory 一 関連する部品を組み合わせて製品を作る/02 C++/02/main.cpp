#include "main.h"

#include "TableFactory.h"
#include "Link.h"
#include "Tray.h"
#include "Page.h"




int main(int argc, char* argv[])
{
	// コマンドライン引数が1つであることを確認（argv[0] はプログラム名）
	// コマンドライン引数を TableFactory とする
	if (argc != 2)
	{
		std::cout << "Usage : ./main [Table/List]Factory" << std::endl;
		std::cout << "Example 1 : ./main ListFactory" << std::endl;
		std::cout << "Example 2 : ./main TableFactory" << std::endl;

		exit(0);
	}



	// TableFactory factory
	Factory* factory = Factory::getFactory(argv[1]);



	// TableLink asahi("朝日新聞", "https://www.asahi.com/")
	Link* asahi = factory->createLink("朝日新聞", "https://www.asahi.com/");
	Link* yomiuri = factory->createLink("読売新聞", "https://www.yomiuri.co.jp/");
	Link* yahoo = factory->createLink("Yahoo!", "https://www.yahoo.co.jp/");
	Link* google = factory->createLink("Google", "https://www.google.com/");



	// TableTray("新聞");
	Tray* traynews = factory->createTray("新聞");
	traynews->add(asahi);
	traynews->add(yomiuri);

	Tray* trayyahoo = factory->createTray("Yahoo!");
	trayyahoo->add(yahoo);

	Tray* traysearch = factory->createTray("サーチエンジン");
	traysearch->add(trayyahoo);
	traysearch->add(google);

	Page* page = factory->createPage("FileName", "著者");
	page->add(traynews);
	page->add(traysearch);

	page->output();



	delete factory;

	delete asahi;
	delete yomiuri;
	delete yahoo;
	delete google;

	delete traynews;
	delete trayyahoo;
	delete traysearch;

	delete page;



	return 0;
}