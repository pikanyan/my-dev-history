namespace w_WinForms
{
    partial class MindMapNodeControl
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

        #region コンポーネント デザイナーで生成されたコード

        /// <summary> 
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を 
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.lblNodeText = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblNodeText
            // 
            this.lblNodeText.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblNodeText.Location = new System.Drawing.Point(0, 0);
            this.lblNodeText.Name = "lblNodeText";
            this.lblNodeText.Size = new System.Drawing.Size(100, 50);
            this.lblNodeText.TabIndex = 0;
            this.lblNodeText.Text = "label1";
            this.lblNodeText.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // MindMapNodeControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.lblNodeText);
            this.Name = "MindMapNodeControl";
            this.Size = new System.Drawing.Size(100, 50);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label lblNodeText;
    }
}
