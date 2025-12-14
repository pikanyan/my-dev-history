// Wall.xaml.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WPF
{
    /// <summary>
    /// Wall.xaml の相互作用ロジック
    /// </summary>
    public partial class Wall : UserControl
    {
        // プロパティ
        public int TopWall_left { get; } = 0;
        public int TopWall_top { get; } = 0;
        public int TopWall_width { get; } = 10 + 300 + 10;
        public int TopWall_height => 10;

        public int LeftWall_left { get; } = 0;
        public int LeftWall_top { get; } = 10;
        public int LeftWall_width { get; } = 10;
        public int LeftWall_height => 10 * 48;

        public int RightWall_left { get; } = 10 + 300;
        public int RightWall_top { get; } = 10;
        public int RightWall_width { get; } = 10;
        public int RightWall_height => 10 * 48;



        public Wall()
        {
            InitializeComponent();

            DataContext = this;
        }
    }
}


/*
height_ が 480 になる理由

10 x 1
10 x 3
10 x 6
10 x 38

48 と決め打ちするか
このように分けるか
3, 6 に関して
定数はここではない場所に置くべきか
*/
