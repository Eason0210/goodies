namespace CompanyNameCsLineScanner
{
    partial class CDlgOptions
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
            this.m_treeView = new System.Windows.Forms.TreeView();
            this.m_propertyGrid = new System.Windows.Forms.PropertyGrid();
            this.m_pbOK = new System.Windows.Forms.Button();
            this.m_pbCancel = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // m_treeView
            // 
            this.m_treeView.Location = new System.Drawing.Point(12, 12);
            this.m_treeView.Name = "m_treeView";
            this.m_treeView.Size = new System.Drawing.Size(184, 329);
            this.m_treeView.TabIndex = 1;
            this.m_treeView.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeViewAfterSelect);
            // 
            // m_propertyGrid
            // 
            this.m_propertyGrid.HelpVisible = false;
            this.m_propertyGrid.LineColor = System.Drawing.SystemColors.Control;
            this.m_propertyGrid.Location = new System.Drawing.Point(208, 12);
            this.m_propertyGrid.Name = "m_propertyGrid";
            this.m_propertyGrid.PropertySort = System.Windows.Forms.PropertySort.Categorized;
            this.m_propertyGrid.Size = new System.Drawing.Size(410, 329);
            this.m_propertyGrid.TabIndex = 2;
            this.m_propertyGrid.ToolbarVisible = false;
            // 
            // m_pbOK
            // 
            this.m_pbOK.Location = new System.Drawing.Point(462, 356);
            this.m_pbOK.Name = "m_pbOK";
            this.m_pbOK.Size = new System.Drawing.Size(75, 23);
            this.m_pbOK.TabIndex = 3;
            this.m_pbOK.Text = "OK";
            this.m_pbOK.UseVisualStyleBackColor = true;
            this.m_pbOK.Click += new System.EventHandler(this.pbOKClick);
            // 
            // m_pbCancel
            // 
            this.m_pbCancel.Location = new System.Drawing.Point(543, 356);
            this.m_pbCancel.Name = "m_pbCancel";
            this.m_pbCancel.Size = new System.Drawing.Size(75, 23);
            this.m_pbCancel.TabIndex = 4;
            this.m_pbCancel.Text = "Cancel";
            this.m_pbCancel.UseVisualStyleBackColor = true;
            this.m_pbCancel.Click += new System.EventHandler(this.pbCancelClick);
            // 
            // CDlgOptions
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(630, 391);
            this.Controls.Add(this.m_pbCancel);
            this.Controls.Add(this.m_pbOK);
            this.Controls.Add(this.m_propertyGrid);
            this.Controls.Add(this.m_treeView);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "CDlgOptions";
            this.ShowIcon = false;
            this.Text = "Line Scan Options";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView m_treeView;
        private System.Windows.Forms.PropertyGrid m_propertyGrid;
        private System.Windows.Forms.Button m_pbOK;
        private System.Windows.Forms.Button m_pbCancel;
    }
}