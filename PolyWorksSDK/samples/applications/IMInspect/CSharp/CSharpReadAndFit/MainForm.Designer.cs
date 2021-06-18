namespace CSharpReadAndFit
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
            this.ButtonSend = new System.Windows.Forms.Button();
            this.TextFileName = new System.Windows.Forms.TextBox();
            this.LabelResult = new System.Windows.Forms.Label();
            this.LabelInformation = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // ButtonSend
            // 
            this.ButtonSend.BackColor = System.Drawing.SystemColors.Control;
            this.ButtonSend.Cursor = System.Windows.Forms.Cursors.Default;
            this.ButtonSend.Font = new System.Drawing.Font("Arial", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ButtonSend.ForeColor = System.Drawing.SystemColors.ControlText;
            this.ButtonSend.Location = new System.Drawing.Point(122, 97);
            this.ButtonSend.Name = "ButtonSend";
            this.ButtonSend.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.ButtonSend.Size = new System.Drawing.Size(81, 33);
            this.ButtonSend.TabIndex = 9;
            this.ButtonSend.Text = "Send";
            this.ButtonSend.UseVisualStyleBackColor = false;
            this.ButtonSend.Click += new System.EventHandler(this.ButtonSend_Click);
            // 
            // TextFileName
            // 
            this.TextFileName.AcceptsReturn = true;
            this.TextFileName.BackColor = System.Drawing.SystemColors.Window;
            this.TextFileName.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.TextFileName.Font = new System.Drawing.Font("Arial", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextFileName.ForeColor = System.Drawing.SystemColors.WindowText;
            this.TextFileName.Location = new System.Drawing.Point(15, 66);
            this.TextFileName.MaxLength = 0;
            this.TextFileName.Name = "TextFileName";
            this.TextFileName.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.TextFileName.Size = new System.Drawing.Size(297, 20);
            this.TextFileName.TabIndex = 8;
            // 
            // LabelResult
            // 
            this.LabelResult.BackColor = System.Drawing.Color.Transparent;
            this.LabelResult.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.LabelResult.Cursor = System.Windows.Forms.Cursors.Default;
            this.LabelResult.Font = new System.Drawing.Font("Arial", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelResult.ForeColor = System.Drawing.SystemColors.ControlText;
            this.LabelResult.Location = new System.Drawing.Point(0, 143);
            this.LabelResult.Name = "LabelResult";
            this.LabelResult.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.LabelResult.Size = new System.Drawing.Size(324, 20);
            this.LabelResult.TabIndex = 10;
            this.LabelResult.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // LabelInformation
            // 
            this.LabelInformation.BackColor = System.Drawing.SystemColors.Control;
            this.LabelInformation.Cursor = System.Windows.Forms.Cursors.Default;
            this.LabelInformation.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LabelInformation.ForeColor = System.Drawing.SystemColors.ControlText;
            this.LabelInformation.Location = new System.Drawing.Point(12, 4);
            this.LabelInformation.Name = "LabelInformation";
            this.LabelInformation.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.LabelInformation.Size = new System.Drawing.Size(300, 49);
            this.LabelInformation.TabIndex = 7;
            this.LabelInformation.Text = "Please enter the name of an ASCII point cloud file with points and normals in the" +
                " edit box below, then press the Send button or the Enter key.";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(324, 166);
            this.Controls.Add(this.ButtonSend);
            this.Controls.Add(this.TextFileName);
            this.Controls.Add(this.LabelResult);
            this.Controls.Add(this.LabelInformation);
            this.Name = "MainForm";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.MainForm_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.Button ButtonSend;
        public System.Windows.Forms.TextBox TextFileName;
        public System.Windows.Forms.Label LabelResult;
        public System.Windows.Forms.Label LabelInformation;
    }
}

