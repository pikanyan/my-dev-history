#include "ListTray.h"

ListTray::ListTray(const std::string& caption) :
    Tray(caption)
{
}

std::string ListTray::makeHTML()
{
    std::stringstream buffer;

    // 新聞トレイは、新聞というキャプションを持つ
    buffer << "<li>" << caption_ << "<ul>";


    // main を順番に見ていくと、HTML ファイルの結果を上から完成させていくと分かる
    // ボルトとナットのように、ListPage, ListTray, ListLink が生成する文字列を上手く組み合わせる必要がある
    for (const auto& item : tray_)
        buffer << item->makeHTML();


    buffer << "</ul></li>";

    return buffer.str();
}
