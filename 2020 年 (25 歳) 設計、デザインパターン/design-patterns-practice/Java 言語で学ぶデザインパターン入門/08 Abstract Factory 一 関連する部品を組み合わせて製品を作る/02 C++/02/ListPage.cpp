#include "ListPage.h"



ListPage::ListPage(const std::string& title, const std::string& author) :
    Page(title, author)
{
}

std::string ListPage::makeHTML()
{
    std::stringstream buffer;

    // ここまではページが持っていた title を使って StringBuffer を作っただけ
    buffer << "<html><head><title>" << title << "</title></head><body><h1>" << title << "</h1 >< ul>";


    // ここからはページが持っていた 新聞トレイ、サーチエンジントレイを使って、StringBuffer を作る
    // <ul> から </ul> の間が、出力結果
    // <ul> と </ul> の間に for 文を書く、ボルトとナットのように繋げる
    for (const auto& item : content)
        buffer << item->makeHTML();
    // まず、新聞トレイの makeHTML を呼び出す
    // リンクだろうが、トレイだろうが、関係なく、item.makeHTML と呼び出せば良い
    // if 文や、switch 文で、item の具体的なクラスを知ってはいけない
    // それはオブジェクト思考らしくない、ページクラスは、無知であるべき



    buffer << "</ul><hr><address>" << author << "</address></body></html>";

    return buffer.str();
}
