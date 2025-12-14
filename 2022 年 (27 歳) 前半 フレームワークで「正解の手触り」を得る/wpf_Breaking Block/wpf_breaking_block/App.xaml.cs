// App.xaml.cs
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;



namespace WPF
{
    /// <summary>
    /// App.xaml の相互作用ロジック
    /// </summary>
    public partial class App : Application
    {
        /*
        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);

            var mainWindowDirector = new MainWindowDirector();
            var mainWindow = mainWindowDirector.Construct();
        }
        */
    }
}



/*
ToDo

App.xaml
StartupUri="MainWindow.xaml" を廃止

App.xaml.cs
Director に Builder を渡す

壁の幅の統一は後回し
*/



/*
MainScene

<Grid>
    <Grid.ColumnDefinitions>
        <ColumnDefinition Width="*"/>
        <ColumnDefinition Width="10*"/>
        <ColumnDefinition Width="*"/>
    </Grid.ColumnDefinitions>
        
    <Grid.RowDefinitions>
        <RowDefinition Height="*"/>
        <RowDefinition Height="3*"/>
        <RowDefinition Height="6*"/>
        <RowDefinition Height="38*"/>
    </Grid.RowDefinitions>

    <Rectangle Fill="Chocolate" Grid.Column="0" Grid.Row="0" Grid.ColumnSpan="12"/>
    <Rectangle Fill="Aqua" Grid.Column="0" Grid.Row="1" Grid.RowSpan="47"/>
    <Rectangle Fill="BlanchedAlmond" Grid.Column="11" Grid.Row="1" Grid.RowSpan="47"/>
</Grid>
*/

