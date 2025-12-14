namespace w_WinForms
{
    partial class Form1
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージド リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.toolStrip = new System.Windows.Forms.ToolStrip();
            this.btnAddNode = new System.Windows.Forms.ToolStripButton();
            this.btnRemoveNode = new System.Windows.Forms.ToolStripButton();
            this.btnZoomIn = new System.Windows.Forms.ToolStripButton();
            this.btnZoomOut = new System.Windows.Forms.ToolStripButton();
            this.nodeContextMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.mnuAddChildNode = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuEditNode = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuRemoveNode = new System.Windows.Forms.ToolStripMenuItem();
            this.pnlCanvas = new w_WinForms.MindMapPanel();
            this.toolStrip.SuspendLayout();
            this.nodeContextMenuStrip.SuspendLayout();
            this.SuspendLayout();
            // 
            // toolStrip
            // 
            this.toolStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnAddNode,
            this.btnRemoveNode,
            this.btnZoomIn,
            this.btnZoomOut});
            this.toolStrip.Location = new System.Drawing.Point(0, 0);
            this.toolStrip.Name = "toolStrip";
            this.toolStrip.Size = new System.Drawing.Size(800, 25);
            this.toolStrip.TabIndex = 0;
            this.toolStrip.Text = "toolStrip1";
            // 
            // btnAddNode
            // 
            this.btnAddNode.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnAddNode.Image = ((System.Drawing.Image)(resources.GetObject("btnAddNode.Image")));
            this.btnAddNode.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnAddNode.Name = "btnAddNode";
            this.btnAddNode.Size = new System.Drawing.Size(23, 22);
            this.btnAddNode.Text = "AddNode";
            this.btnAddNode.Click += new System.EventHandler(this.btnAddNode_Click);
            // 
            // btnRemoveNode
            // 
            this.btnRemoveNode.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnRemoveNode.Image = ((System.Drawing.Image)(resources.GetObject("btnRemoveNode.Image")));
            this.btnRemoveNode.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnRemoveNode.Name = "btnRemoveNode";
            this.btnRemoveNode.Size = new System.Drawing.Size(23, 22);
            this.btnRemoveNode.Text = "Remove Node";
            this.btnRemoveNode.Click += new System.EventHandler(this.btnRemoveNode_Click);
            // 
            // btnZoomIn
            // 
            this.btnZoomIn.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnZoomIn.Image = ((System.Drawing.Image)(resources.GetObject("btnZoomIn.Image")));
            this.btnZoomIn.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnZoomIn.Name = "btnZoomIn";
            this.btnZoomIn.Size = new System.Drawing.Size(23, 22);
            this.btnZoomIn.Text = "Zoom In";
            // 
            // btnZoomOut
            // 
            this.btnZoomOut.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.btnZoomOut.Image = ((System.Drawing.Image)(resources.GetObject("btnZoomOut.Image")));
            this.btnZoomOut.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnZoomOut.Name = "btnZoomOut";
            this.btnZoomOut.Size = new System.Drawing.Size(23, 22);
            this.btnZoomOut.Text = "Zoom Out";
            // 
            // nodeContextMenuStrip
            // 
            this.nodeContextMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuAddChildNode,
            this.mnuEditNode,
            this.mnuRemoveNode});
            this.nodeContextMenuStrip.Name = "nodeContextMenuStrip";
            this.nodeContextMenuStrip.Size = new System.Drawing.Size(159, 70);
            // 
            // mnuAddChildNode
            // 
            this.mnuAddChildNode.Name = "mnuAddChildNode";
            this.mnuAddChildNode.Size = new System.Drawing.Size(158, 22);
            this.mnuAddChildNode.Text = "Add Child Node";
            this.mnuAddChildNode.Click += new System.EventHandler(this.mnuAddChildNode_Click);
            // 
            // mnuEditNode
            // 
            this.mnuEditNode.Name = "mnuEditNode";
            this.mnuEditNode.Size = new System.Drawing.Size(158, 22);
            this.mnuEditNode.Text = "Edit Node";
            this.mnuEditNode.Click += new System.EventHandler(this.mnuEditNode_Click);
            // 
            // mnuRemoveNode
            // 
            this.mnuRemoveNode.Name = "mnuRemoveNode";
            this.mnuRemoveNode.Size = new System.Drawing.Size(158, 22);
            this.mnuRemoveNode.Text = "Remove Node";
            this.mnuRemoveNode.Click += new System.EventHandler(this.mnuRemoveNode_Click);
            // 
            // pnlCanvas
            // 
            this.pnlCanvas.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlCanvas.Location = new System.Drawing.Point(0, 25);
            this.pnlCanvas.Name = "pnlCanvas";
            this.pnlCanvas.Size = new System.Drawing.Size(800, 425);
            this.pnlCanvas.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.pnlCanvas);
            this.Controls.Add(this.toolStrip);
            this.Name = "Form1";
            this.Text = "Form1";
            this.toolStrip.ResumeLayout(false);
            this.toolStrip.PerformLayout();
            this.nodeContextMenuStrip.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolStrip toolStrip;
        private MindMapPanel pnlCanvas;
        private System.Windows.Forms.ContextMenuStrip nodeContextMenuStrip;
        private System.Windows.Forms.ToolStripButton btnAddNode;
        private System.Windows.Forms.ToolStripButton btnRemoveNode;
        private System.Windows.Forms.ToolStripButton btnZoomIn;
        private System.Windows.Forms.ToolStripButton btnZoomOut;
        private System.Windows.Forms.ToolStripMenuItem mnuAddChildNode;
        private System.Windows.Forms.ToolStripMenuItem mnuEditNode;
        private System.Windows.Forms.ToolStripMenuItem mnuRemoveNode;
    }
}

