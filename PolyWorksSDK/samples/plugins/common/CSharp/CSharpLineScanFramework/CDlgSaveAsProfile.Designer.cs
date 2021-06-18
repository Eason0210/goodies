namespace CompanyNameCsLineScanner
{
    partial class CDlgSaveAsProfile
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
            System.Windows.Forms.Label label4;
            this.label1 = new System.Windows.Forms.Label();
            this.m_cbUserProfile = new System.Windows.Forms.ComboBox();
            this.m_pbOK = new System.Windows.Forms.Button();
            this.m_pbCancel = new System.Windows.Forms.Button();
            label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(10, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Name:";
            // 
            // m_cbUserProfile
            // 
            this.m_cbUserProfile.FormattingEnabled = true;
            this.m_cbUserProfile.Location = new System.Drawing.Point(60, 12);
            this.m_cbUserProfile.Name = "m_cbUserProfile";
            this.m_cbUserProfile.Size = new System.Drawing.Size(200, 21);
            this.m_cbUserProfile.TabIndex = 1;
            // 
            // m_pbOK
            // 
            this.m_pbOK.Location = new System.Drawing.Point(100, 51);
            this.m_pbOK.Name = "m_pbOK";
            this.m_pbOK.Size = new System.Drawing.Size(75, 23);
            this.m_pbOK.TabIndex = 2;
            this.m_pbOK.Text = "OK";
            this.m_pbOK.UseVisualStyleBackColor = true;
            this.m_pbOK.Click += new System.EventHandler(this.pbOKClick);
            // 
            // m_pbCancel
            // 
            this.m_pbCancel.Location = new System.Drawing.Point(181, 51);
            this.m_pbCancel.Name = "m_pbCancel";
            this.m_pbCancel.Size = new System.Drawing.Size(75, 23);
            this.m_pbCancel.TabIndex = 3;
            this.m_pbCancel.Text = "Cancel";
            this.m_pbCancel.UseVisualStyleBackColor = true;
            this.m_pbCancel.Click += new System.EventHandler(this.pbCancelClick);
            // 
            // label4
            // 
            label4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            label4.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            label4.Location = new System.Drawing.Point(12, 40);
            label4.Margin = new System.Windows.Forms.Padding(0);
            label4.Name = "label4";
            label4.Size = new System.Drawing.Size(244, 1);
            label4.TabIndex = 8;
            // 
            // CDlgSaveAsProfile
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(272, 85);
            this.Controls.Add(label4);
            this.Controls.Add(this.m_pbCancel);
            this.Controls.Add(this.m_pbOK);
            this.Controls.Add(this.m_cbUserProfile);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "CDlgSaveAsProfile";
            this.ShowIcon = false;
            this.Text = "Save Profile As";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox m_cbUserProfile;
        private System.Windows.Forms.Button m_pbOK;
        private System.Windows.Forms.Button m_pbCancel;
    }
}