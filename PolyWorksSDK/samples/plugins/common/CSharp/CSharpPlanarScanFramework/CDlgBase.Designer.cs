namespace CompanyNameCsPlanarScanner
{
    partial class CDlgBase
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.m_basicLayout = new System.Windows.Forms.TableLayoutPanel();
            this.m_footerLayout = new System.Windows.Forms.TableLayoutPanel();
            this.m_btnScan = new System.Windows.Forms.Button();
            this.m_btnClose = new System.Windows.Forms.Button();
            this.m_internalLayout = new System.Windows.Forms.TableLayoutPanel();
            this.cDivider1 = new CDivider();
            this.m_basicLayout.SuspendLayout();
            this.m_footerLayout.SuspendLayout();
            this.SuspendLayout();
            // 
            // m_basicLayout
            // 
            this.m_basicLayout.AutoSize = true;
            this.m_basicLayout.ColumnCount = 3;
            this.m_basicLayout.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 10F));
            this.m_basicLayout.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.m_basicLayout.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 12F));
            this.m_basicLayout.Controls.Add(this.m_footerLayout, 1, 3);
            this.m_basicLayout.Controls.Add(this.m_internalLayout, 1, 1);
            this.m_basicLayout.Controls.Add(this.cDivider1, 1, 2);
            this.m_basicLayout.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_basicLayout.Location = new System.Drawing.Point(0, 0);
            this.m_basicLayout.Name = "m_basicLayout";
            this.m_basicLayout.RowCount = 4;
            this.m_basicLayout.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 10F));
            this.m_basicLayout.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_basicLayout.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 10F));
            this.m_basicLayout.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_basicLayout.Size = new System.Drawing.Size(190, 61);
            this.m_basicLayout.TabIndex = 0;
            // 
            // m_footerLayout
            // 
            this.m_footerLayout.AutoSize = true;
            this.m_footerLayout.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.m_footerLayout.ColumnCount = 2;
            this.m_footerLayout.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.m_footerLayout.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.m_footerLayout.Controls.Add(this.m_btnScan, 0, 0);
            this.m_footerLayout.Controls.Add(this.m_btnClose, 1, 0);
            this.m_footerLayout.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_footerLayout.GrowStyle = System.Windows.Forms.TableLayoutPanelGrowStyle.FixedSize;
            this.m_footerLayout.Location = new System.Drawing.Point(13, 29);
            this.m_footerLayout.Name = "m_footerLayout";
            this.m_footerLayout.RowCount = 1;
            this.m_footerLayout.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_footerLayout.Size = new System.Drawing.Size(162, 29);
            this.m_footerLayout.TabIndex = 4;
            // 
            // m_btnScan
            // 
            this.m_btnScan.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.m_btnScan.Dock = System.Windows.Forms.DockStyle.Left;
            this.m_btnScan.Location = new System.Drawing.Point(3, 3);
            this.m_btnScan.Name = "m_btnScan";
            this.m_btnScan.Size = new System.Drawing.Size(75, 23);
            this.m_btnScan.TabIndex = 0;
            this.m_btnScan.Text = "Start Scan";
            this.m_btnScan.UseVisualStyleBackColor = true;
            this.m_btnScan.Click += new System.EventHandler(this.m_btnScan_Click);
            // 
            // m_btnClose
            // 
            this.m_btnClose.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.m_btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.m_btnClose.Dock = System.Windows.Forms.DockStyle.Right;
            this.m_btnClose.Location = new System.Drawing.Point(84, 3);
            this.m_btnClose.Name = "m_btnClose";
            this.m_btnClose.Size = new System.Drawing.Size(75, 23);
            this.m_btnClose.TabIndex = 1;
            this.m_btnClose.Text = "Close";
            this.m_btnClose.UseVisualStyleBackColor = true;
            this.m_btnClose.Click += new System.EventHandler(this.m_btnClose_Click);
            // 
            // m_internalLayout
            // 
            this.m_internalLayout.AutoSize = true;
            this.m_internalLayout.ColumnCount = 1;
            this.m_internalLayout.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.m_internalLayout.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_internalLayout.Location = new System.Drawing.Point(13, 13);
            this.m_internalLayout.Name = "m_internalLayout";
            this.m_internalLayout.RowCount = 1;
            this.m_internalLayout.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_internalLayout.Size = new System.Drawing.Size(162, 1);
            this.m_internalLayout.TabIndex = 2;
            // 
            // cDivider1
            // 
            this.cDivider1.AutoSize = true;
            this.cDivider1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.cDivider1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cDivider1.Dock = System.Windows.Forms.DockStyle.Top;
            this.cDivider1.Location = new System.Drawing.Point(13, 16);
            this.cDivider1.MaximumSize = new System.Drawing.Size(225, 1);
            this.cDivider1.MinimumSize = new System.Drawing.Size(0, 1);
            this.cDivider1.Name = "cDivider1";
            this.cDivider1.Padding = new System.Windows.Forms.Padding(2, 0, 0, 2);
            this.cDivider1.Size = new System.Drawing.Size(162, 1);
            this.cDivider1.TabIndex = 5;
            // 
            // CDlgBase
            // 
            this.AcceptButton = this.m_btnScan;
            this.AccessibleRole = System.Windows.Forms.AccessibleRole.Dialog;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.CancelButton = this.m_btnClose;
            this.ClientSize = new System.Drawing.Size(190, 61);
            this.Controls.Add(this.m_basicLayout);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "CDlgBase";
            this.ShowIcon = false;
            this.Text = "Scan";
            this.Shown += new System.EventHandler(this.Showned);
            this.Move += new System.EventHandler(this.Moved);
            this.m_basicLayout.ResumeLayout(false);
            this.m_basicLayout.PerformLayout();
            this.m_footerLayout.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel m_basicLayout;
        private System.Windows.Forms.TableLayoutPanel m_footerLayout;
        private System.Windows.Forms.Button m_btnScan;
        private System.Windows.Forms.Button m_btnClose;

        protected System.Windows.Forms.TableLayoutPanel m_internalLayout;
        private CDivider cDivider1;
    }
}