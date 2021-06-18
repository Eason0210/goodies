namespace CSharpWallCreation
{
    partial class MainForm
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
            this.TextLog = new System.Windows.Forms.TextBox();
            this.ButtonStart = new System.Windows.Forms.Button();
            this.TextSource = new System.Windows.Forms.TextBox();
            this.LabelLog = new System.Windows.Forms.Label();
            this.LabelSource = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // TextLog
            // 
            this.TextLog.AcceptsReturn = true;
            this.TextLog.BackColor = System.Drawing.SystemColors.Window;
            this.TextLog.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.TextLog.Font = new System.Drawing.Font("Arial", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextLog.ForeColor = System.Drawing.SystemColors.WindowText;
            this.TextLog.Location = new System.Drawing.Point(5, 59);
            this.TextLog.MaxLength = 0;
            this.TextLog.Multiline = true;
            this.TextLog.Name = "TextLog";
            this.TextLog.ReadOnly = true;
            this.TextLog.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.TextLog.Size = new System.Drawing.Size(417, 193);
            this.TextLog.TabIndex = 14;
            // 
            // ButtonStart
            // 
            this.ButtonStart.BackColor = System.Drawing.SystemColors.Control;
            this.ButtonStart.Cursor = System.Windows.Forms.Cursors.Default;
            this.ButtonStart.Font = new System.Drawing.Font("Arial", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ButtonStart.ForeColor = System.Drawing.SystemColors.ControlText;
            this.ButtonStart.Location = new System.Drawing.Point(357, 16);
            this.ButtonStart.Name = "ButtonStart";
            this.ButtonStart.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.ButtonStart.Size = new System.Drawing.Size(65, 25);
            this.ButtonStart.TabIndex = 12;
            this.ButtonStart.Text = "Start";
            this.ButtonStart.UseVisualStyleBackColor = false;
            this.ButtonStart.Click += new System.EventHandler(this.ButtonStart_Click);
            // 
            // TextSource
            // 
            this.TextSource.AcceptsReturn = true;
            this.TextSource.BackColor = System.Drawing.SystemColors.Window;
            this.TextSource.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.TextSource.Font = new System.Drawing.Font("Arial", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextSource.ForeColor = System.Drawing.SystemColors.WindowText;
            this.TextSource.Location = new System.Drawing.Point(5, 19);
            this.TextSource.MaxLength = 0;
            this.TextSource.Name = "TextSource";
            this.TextSource.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.TextSource.Size = new System.Drawing.Size(345, 20);
            this.TextSource.TabIndex = 11;
            // 
            // LabelLog
            // 
            this.LabelLog.BackColor = System.Drawing.Color.Transparent;
            this.LabelLog.Cursor = System.Windows.Forms.Cursors.Default;
            this.LabelLog.Font = new System.Drawing.Font("Arial", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelLog.ForeColor = System.Drawing.SystemColors.ControlText;
            this.LabelLog.Location = new System.Drawing.Point(5, 43);
            this.LabelLog.Name = "LabelLog";
            this.LabelLog.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.LabelLog.Size = new System.Drawing.Size(41, 17);
            this.LabelLog.TabIndex = 13;
            this.LabelLog.Text = "Log:";
            // 
            // LabelSource
            // 
            this.LabelSource.BackColor = System.Drawing.Color.Transparent;
            this.LabelSource.Cursor = System.Windows.Forms.Cursors.Default;
            this.LabelSource.Font = new System.Drawing.Font("Arial", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelSource.ForeColor = System.Drawing.SystemColors.ControlText;
            this.LabelSource.Location = new System.Drawing.Point(5, 3);
            this.LabelSource.Name = "LabelSource";
            this.LabelSource.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.LabelSource.Size = new System.Drawing.Size(89, 17);
            this.LabelSource.TabIndex = 10;
            this.LabelSource.Text = "Source pol file:";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(426, 254);
            this.Controls.Add(this.TextLog);
            this.Controls.Add(this.ButtonStart);
            this.Controls.Add(this.TextSource);
            this.Controls.Add(this.LabelLog);
            this.Controls.Add(this.LabelSource);
            this.Name = "MainForm";
            this.Text = "PolyWorks|Modeler Wall Creation Sample";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.TextBox TextLog;
        public System.Windows.Forms.Button ButtonStart;
        public System.Windows.Forms.TextBox TextSource;
        public System.Windows.Forms.Label LabelLog;
        public System.Windows.Forms.Label LabelSource;
    }
}

