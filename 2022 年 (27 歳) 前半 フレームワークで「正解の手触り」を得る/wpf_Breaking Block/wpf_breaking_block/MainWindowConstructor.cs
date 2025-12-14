// MainWindowConstructor.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WPF
{
    internal class MainWindowConstructor
    {
        private MainWindow mainWindow_;

        public void New_MainWindow()
        {
            mainWindow_ = new MainWindow();
        }

        public void Show_MainWindow()
        {
            mainWindow_.Show();
        }

        public MainWindow Return_MainWindow()
        {
            return mainWindow_;
        }
    }
}
