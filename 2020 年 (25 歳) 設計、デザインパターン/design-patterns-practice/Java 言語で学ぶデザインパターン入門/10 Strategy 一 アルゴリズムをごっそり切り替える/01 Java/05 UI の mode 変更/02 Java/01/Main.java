public class Main
{
    public static void main(String[] args)
    {
        Theme darkTheme = new DarkTheme();
        Theme lightTheme = new LightTheme();
        
        UIContext uiContext = new UIContext(darkTheme);
        uiContext.applyTheme();         // ダークテーマを適用

        uiContext.setTheme(lightTheme);
        uiContext.applyTheme();         // ライトテーマに切り替え
    }
}
