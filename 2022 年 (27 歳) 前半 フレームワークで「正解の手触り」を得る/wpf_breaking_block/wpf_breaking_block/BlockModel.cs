using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace WPF
{
    public class BlockModel
    {
        public double Left { get; set; }
        public double Top { get; set; }
        public double Width { get; } = 30;
        public double Height { get; } = 10;
    }
}

