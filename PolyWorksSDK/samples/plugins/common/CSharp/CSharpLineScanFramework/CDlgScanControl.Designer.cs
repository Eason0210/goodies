namespace CompanyNameCsLineScanner
{
    partial class CDlgScanControl
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
            this.components = new System.ComponentModel.Container();
            this.m_pbPass = new System.Windows.Forms.Button();
            this.m_pbEnd = new System.Windows.Forms.Button();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.SuspendLayout();
            // 
            // m_pbPass
            // 
            this.m_pbPass.Location = new System.Drawing.Point(12, 12);
            this.m_pbPass.Name = "m_pbPass";
            this.m_pbPass.Size = new System.Drawing.Size(75, 23);
            this.m_pbPass.TabIndex = 0;
            this.m_pbPass.Text = "Start Pass";
            this.toolTip1.SetToolTip(this.m_pbPass, "This button simulates a button on your device that starts and ends generation of " +
        "scan lines");
            this.m_pbPass.UseVisualStyleBackColor = true;
            this.m_pbPass.Click += new System.EventHandler(this.pbPassClick);
            // 
            // m_pbEnd
            // 
            this.m_pbEnd.Location = new System.Drawing.Point(103, 12);
            this.m_pbEnd.Name = "m_pbEnd";
            this.m_pbEnd.Size = new System.Drawing.Size(75, 23);
            this.m_pbEnd.TabIndex = 1;
            this.m_pbEnd.Text = "End Scan";
            this.toolTip1.SetToolTip(this.m_pbEnd, "This button simulates a button on your device that requests ending the scan.");
            this.m_pbEnd.UseVisualStyleBackColor = true;
            this.m_pbEnd.Click += new System.EventHandler(this.pbEndClick);
            // 
            // CDlgScanControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(190, 48);
            this.ControlBox = false;
            this.Controls.Add(this.m_pbEnd);
            this.Controls.Add(this.m_pbPass);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "CDlgScanControl";
            this.ShowIcon = false;
            this.Text = "Scan Control";
            this.VisibleChanged += new System.EventHandler(this.FormVisibleChanged);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button m_pbPass;
        private System.Windows.Forms.Button m_pbEnd;
        private System.Windows.Forms.ToolTip toolTip1;
    }
}