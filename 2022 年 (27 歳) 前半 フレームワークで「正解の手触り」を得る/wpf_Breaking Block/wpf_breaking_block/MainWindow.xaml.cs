// MainWindow.xaml.cs
using System.Windows;

namespace WPF
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }



        private void Play_Click(object sender, RoutedEventArgs e)
        {
            MainSceneControl.Start();
        }
    }
}
