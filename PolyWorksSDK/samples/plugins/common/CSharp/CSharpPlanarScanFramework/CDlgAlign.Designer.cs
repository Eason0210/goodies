using System;

namespace CompanyNameCsPlanarScanner
{
    partial class CDlgAlign
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
            this.m_mainDlgSection = new System.Windows.Forms.TableLayoutPanel();
            this.m_lblName = new System.Windows.Forms.Label();
            this.m_txtScanName = new System.Windows.Forms.TextBox();
            this.m_lblNbPts = new System.Windows.Forms.Label();
            this.m_txtlNbPts = new System.Windows.Forms.TextBox();
            this.m_btnOption = new System.Windows.Forms.Button();
            this.m_mainDlgSection.SuspendLayout();
            this.SuspendLayout();
            this.m_internalLayout.Controls.Add(this.m_mainDlgSection, 0, 0);
            // 
            // m_mainDlgSection
            // 
            this.m_mainDlgSection.AutoSize = true;
            this.m_mainDlgSection.ColumnCount = 2;
            this.m_mainDlgSection.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.m_mainDlgSection.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.m_mainDlgSection.Controls.Add(this.m_lblName, 0, 0);
            this.m_mainDlgSection.Controls.Add(this.m_txtScanName, 1, 0);
            this.m_mainDlgSection.Controls.Add(this.m_lblNbPts, 0, 1);
            this.m_mainDlgSection.Controls.Add(this.m_txtlNbPts, 1, 1);
            this.m_mainDlgSection.Controls.Add(this.m_btnOption, 1, 2);
            this.m_mainDlgSection.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_mainDlgSection.Location = new System.Drawing.Point(3, 3);
            this.m_mainDlgSection.Name = "m_mainDlgSection";
            this.m_mainDlgSection.RowCount = 3;
            this.m_mainDlgSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_mainDlgSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_mainDlgSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_mainDlgSection.Size = new System.Drawing.Size(237, 81);
            this.m_mainDlgSection.TabIndex = 0;
            // 
            // m_lblName
            // 
            this.m_lblName.AutoSize = true;
            this.m_lblName.Dock = System.Windows.Forms.DockStyle.Left;
            this.m_lblName.Location = new System.Drawing.Point(3, 0);
            this.m_lblName.Name = "m_lblName";
            this.m_lblName.Size = new System.Drawing.Size(64, 26);
            this.m_lblName.TabIndex = 0;
            this.m_lblName.Text = "Scan name:";
            // 
            // m_txtScanName
            // 
            this.m_txtScanName.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_txtScanName.Location = new System.Drawing.Point(99, 3);
            this.m_txtScanName.Name = "m_txtScanName";
            this.m_txtScanName.Size = new System.Drawing.Size(135, 20);
            this.m_txtScanName.TabIndex = 0;
            this.m_txtScanName.Leave += new System.EventHandler(this.txtScanName_Leave);
            // 
            // m_lblNbPts
            // 
            this.m_lblNbPts.AutoSize = true;
            this.m_lblNbPts.Dock = System.Windows.Forms.DockStyle.Left;
            this.m_lblNbPts.Location = new System.Drawing.Point(3, 26);
            this.m_lblNbPts.Name = "m_lblNbPts";
            this.m_lblNbPts.Size = new System.Drawing.Size(90, 26);
            this.m_lblNbPts.TabIndex = 1;
            this.m_lblNbPts.Text = "Number of points:";
            // 
            // m_txtlNbPts
            // 
            this.m_txtlNbPts.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_txtlNbPts.Enabled = false;
            this.m_txtlNbPts.Location = new System.Drawing.Point(99, 29);
            this.m_txtlNbPts.Name = "m_txtlNbPts";
            this.m_txtlNbPts.Size = new System.Drawing.Size(135, 20);
            this.m_txtlNbPts.TabIndex = 0;
            // 
            // m_btnOption
            // 
            this.m_btnOption.Dock = System.Windows.Forms.DockStyle.Right;
            this.m_btnOption.Location = new System.Drawing.Point(159, 55);
            this.m_btnOption.Name = "m_btnOption";
            this.m_btnOption.Size = new System.Drawing.Size(75, 23);
            this.m_btnOption.TabIndex = 1;
            this.m_btnOption.Text = "Options";
            this.m_btnOption.UseVisualStyleBackColor = true;
            this.m_btnOption.Click += new System.EventHandler(this.m_btnOption_Click);
            // 
            // CDlgAlign
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(271, 148);
            this.Name = "CDlgAlign";
            this.m_mainDlgSection.ResumeLayout(false);
            this.m_mainDlgSection.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel m_mainDlgSection;
        private System.Windows.Forms.Label m_lblName;
        private System.Windows.Forms.Label m_lblNbPts;
        private System.Windows.Forms.TextBox m_txtScanName;
        private System.Windows.Forms.TextBox m_txtlNbPts;
        private System.Windows.Forms.Button m_btnOption;
    }
}
