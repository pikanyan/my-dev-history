using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace w_WinForms
{
    public partial class MindMapNodeControl : UserControl
    {
        public string NodeText
        {
            get { return lblNodeText.Text; }
            set { lblNodeText.Text = value; }
        }

        public MindMapNodeControl ParentNode { get; set; }


        public MindMapNodeControl()
        {
            InitializeComponent();

            lblNodeText.MouseDown += (sender, e) => OnMouseDown(e);
            lblNodeText.MouseUp += (sender, e) => OnMouseUp(e);
            lblNodeText.MouseMove += (sender, e) => OnMouseMove(e);
        }
    }
}
