using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using w_WinForms;

namespace w_WinForms
{
    public partial class Form1 : Form
    {
        private MindMapNodeControl selectedNode;
        private Point? _dragStartPoint = null;



        public Form1()
        {
            InitializeComponent();



            // Add the following lines after InitializeComponent()
            // TransparentDoubleBufferedPanel.Paint += PnlLineOverlay_Paint;不要になった
            // TransparentDoubleBufferedPanel.MouseMove += (sender, e) => TransparentDoubleBufferedPanel.Invalidate();





        }

        private void btnAddNode_Click(object sender, EventArgs e)
        {
            AddNode(null); // Add a new root node
        }

        private void btnRemoveNode_Click(object sender, EventArgs e)
        {
            RemoveSelectedNode();
        }

        private void mnuAddChildNode_Click(object sender, EventArgs e)
        {
            AddNode(selectedNode); // Add a new child node to the selected node
        }

        private void mnuEditNode_Click(object sender, EventArgs e)
        {
            EditSelectedNode();
        }

        private void mnuRemoveNode_Click(object sender, EventArgs e)
        {
            RemoveSelectedNode();
        }




        private void AddNode(MindMapNodeControl parentNode)
        {
            MindMapNodeControl newNode = new MindMapNodeControl();
            newNode.NodeText = "New Node"; // You can prompt the user for a node name here
            newNode.ContextMenuStrip = nodeContextMenuStrip;
            newNode.MouseDown += NodeControl_MouseDown;
            newNode.MouseUp += NodeControl_MouseUp;
            newNode.MouseMove += NodeControl_MouseMove;

            if (parentNode != null)
            {
                newNode.ParentNode = parentNode;

                // Add the new node as a child of the parentNode (positioning and connecting logic goes here)
            }
            else
            {
                newNode.ParentNode = null;

                // Add the new node as a root node (positioning logic goes here)
            }

            pnlCanvas.Controls.Add(newNode);
            newNode.BringToFront();
        }



        private void EditSelectedNode()
        {
            if (selectedNode != null)
            {
                // Prompt the user for a new node name and update the selectedNode's text
            }
        }


        private void RemoveSelectedNode()
        {
            if (selectedNode != null)
            {
                // Remove the selectedNode from the canvas and dispose of it
                pnlCanvas.Controls.Remove(selectedNode);
                selectedNode.Dispose();

                // Set the selectedNode to null since it has been removed
                selectedNode = null;
            }
        }





        private void NodeControl_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                MindMapNodeControl nodeControl = sender as MindMapNodeControl;
                if (nodeControl != null)
                {
                    selectedNode = nodeControl;
                    _dragStartPoint = e.Location;
                }
            }
        }

        private void NodeControl_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                _dragStartPoint = null;
            }
        }



        private void NodeControl_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left && _dragStartPoint.HasValue)
            {
                MindMapNodeControl nodeControl = sender as MindMapNodeControl;
                if (nodeControl != null)
                {
                    int deltaX = e.X - _dragStartPoint.Value.X;
                    int deltaY = e.Y - _dragStartPoint.Value.Y;
                    nodeControl.Location = new Point(nodeControl.Location.X + deltaX, nodeControl.Location.Y + deltaY);

                    // Add this line to force a redraw of the connections
                    // TransparentDoubleBufferedPanel.Invalidate();

                    // Invalidate the entire form
                    this.Invalidate();
                }
            }
        }




        // Form1 クラス内
        private void PnlLineOverlay_Paint(object sender, PaintEventArgs e)
        {
            if (pnlCanvas.Controls != null)
            {
                foreach (MindMapNodeControl node in pnlCanvas.Controls.OfType<MindMapNodeControl>())
                {
                    if (node.ParentNode != null)
                    {
                        Point startPoint = new Point(node.ParentNode.Location.X + node.ParentNode.Width / 2,
                                                      node.ParentNode.Location.Y + node.ParentNode.Height / 2);
                        Point endPoint = new Point(node.Location.X + node.Width / 2,
                                                    node.Location.Y + node.Height / 2);
                        e.Graphics.DrawLine(Pens.Black, startPoint, endPoint);
                    }
                }
            }
        }




        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            if (pnlCanvas.Controls != null)
            {
                foreach (MindMapNodeControl node in pnlCanvas.Controls.OfType<MindMapNodeControl>())
                {
                    if (node.ParentNode != null)
                    {
                        Point startPoint = new Point(node.ParentNode.Location.X + node.ParentNode.Width / 2,
                                                      node.ParentNode.Location.Y + node.ParentNode.Height / 2);
                        Point endPoint = new Point(node.Location.X + node.Width / 2,
                                                    node.Location.Y + node.Height / 2);
                        e.Graphics.DrawLine(Pens.Black, startPoint, endPoint);
                    }
                }
            }
        }

    }



    // Form1 と同じ名前空間
    public class MindMapPanel : Panel
    {
        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            if (Controls != null)
            {
                foreach (MindMapNodeControl node in Controls.OfType<MindMapNodeControl>())
                {
                    if (node.ParentNode != null)
                    {
                        Point startPoint = new Point(node.ParentNode.Location.X + node.ParentNode.Width / 2,
                                                      node.ParentNode.Location.Y + node.ParentNode.Height / 2);
                        Point endPoint = new Point(node.Location.X + node.Width / 2,
                                                    node.Location.Y + node.Height / 2);
                        e.Graphics.DrawLine(Pens.Black, startPoint, endPoint);
                    }
                }
            }
        }
    }




    // Form1 と同じ名前空間
    public class TransparentDoubleBufferedPanel : Panel
    {
        public TransparentDoubleBufferedPanel()
        {
            DoubleBuffered = true;
        }
    }






}





