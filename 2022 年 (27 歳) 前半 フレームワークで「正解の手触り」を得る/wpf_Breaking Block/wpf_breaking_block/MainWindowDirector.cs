// MainWindowDirector.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WPF
{
    internal class MainWindowDirector
    {
        private MainWindowConstructor mainWindowConstructor_;

        public MainWindow Construct()
        {
            mainWindowConstructor_ = new MainWindowConstructor();
            mainWindowConstructor_.New_MainWindow();

            mainWindowConstructor_.Show_MainWindow();
            return mainWindowConstructor_.Return_MainWindow();
        }
    }
}
