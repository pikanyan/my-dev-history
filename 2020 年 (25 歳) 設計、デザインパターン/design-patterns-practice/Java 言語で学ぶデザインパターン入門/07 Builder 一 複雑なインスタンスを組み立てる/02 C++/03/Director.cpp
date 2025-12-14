#include "Director.h"



Director::Director(Builder* builder) :
    builder(builder)
{
}

void Director::construct()                       // 文書構築
{
    builder->makeTitle("Greeting");              // タイトル



    builder->makeString("朝から昼にかけて");     // 文字列
    builder->makeItems(std::vector<std::string>  // 箇条書き
    {
        "おはようございます",
        "こんにちは"
    });



    builder->makeString("夜に");                  // 別の文字列
    builder->makeItems(std::vector<std::string>   // 別の箇条書き
    {
        "こんばんは",
        "おやすみなさい",
        "さようなら"
    });



    builder->close();                             // 文書を完成させる
}
