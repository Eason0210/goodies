namespace CompanyNameCsPlanarScanner
{
    partial class CDlgInspect
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
            this.m_dataObjectSection = new System.Windows.Forms.TableLayoutPanel();
            this.m_dataObjectSubSection = new System.Windows.Forms.TableLayoutPanel();
            this.m_structureSubSection = new System.Windows.Forms.TableLayoutPanel();
            this.m_lblName = new System.Windows.Forms.Label();
            this.m_txtScanName = new System.Windows.Forms.TextBox();
            this.m_lblDataObject = new System.Windows.Forms.Label();
            this.m_lblStructure = new System.Windows.Forms.Label();
            this.m_rdBtnPointcloud = new System.Windows.Forms.RadioButton();
            this.m_rdBtnPolygonalModel = new System.Windows.Forms.RadioButton();
            this.m_parametersSection = new System.Windows.Forms.TableLayoutPanel();
            this.m_lblParameters = new System.Windows.Forms.Label();
            this.m_chkBoxAutomaticViewpoint = new System.Windows.Forms.CheckBox();
		    this.m_chkBoxCreateNewDevicePosition = new System.Windows.Forms.CheckBox();
            this.m_dataObjectDivider = new CDivider();
            this.m_parametersDivider = new CDivider();
            this.cDivider1 = new CDivider();
            this.m_internalLayout.SuspendLayout();
            this.m_dataObjectSection.SuspendLayout();
            this.m_dataObjectSubSection.SuspendLayout();
            this.m_structureSubSection.SuspendLayout();
            this.m_parametersSection.SuspendLayout();
            this.SuspendLayout();
            this.m_internalLayout.RowCount = 2;
            this.m_internalLayout.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_internalLayout.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_internalLayout.Controls.Add(this.m_dataObjectSection, 0, 0);
            this.m_internalLayout.Controls.Add(this.m_parametersSection, 0, 1);

            // 
            // m_dataObjectSection
            // 
            this.m_dataObjectSection.AutoSize = true;
            this.m_dataObjectSection.ColumnCount = 1;
            this.m_dataObjectSection.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.m_dataObjectSection.Controls.Add(this.m_lblDataObject, 0, 0);
            this.m_dataObjectSection.Controls.Add(this.m_dataObjectDivider, 0, 1);
            this.m_dataObjectSection.Controls.Add(this.m_dataObjectSubSection, 0, 2);
            this.m_dataObjectSection.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_dataObjectSection.Location = new System.Drawing.Point(3, 3);
            this.m_dataObjectSection.Name = "m_dataObjectSection";
            this.m_dataObjectSection.RowCount = 3;
            this.m_dataObjectSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_dataObjectSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_dataObjectSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_dataObjectSection.Size = new System.Drawing.Size(206, 116);
            this.m_dataObjectSection.TabIndex = 0;
            // 
            // m_lblDataObject
            // 
            this.m_lblDataObject.AutoSize = true;
            this.m_lblDataObject.Dock = System.Windows.Forms.DockStyle.Left;
            this.m_lblDataObject.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.m_lblDataObject.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.m_lblDataObject.Location = new System.Drawing.Point(3, 0);
            this.m_lblDataObject.Name = "m_lblDataObject";
            this.m_lblDataObject.Padding = new System.Windows.Forms.Padding(0, 0, 0, 5);
            this.m_lblDataObject.Size = new System.Drawing.Size(75, 18);
            this.m_lblDataObject.TabIndex = 0;
            this.m_lblDataObject.Text = "Data Object";
            // 
            // m_dataObjectDivider
            // 
            this.m_dataObjectDivider.AutoSize = true;
            this.m_dataObjectDivider.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.m_dataObjectDivider.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.m_dataObjectDivider.Dock = System.Windows.Forms.DockStyle.Top;
            this.m_dataObjectDivider.Location = new System.Drawing.Point(3, 18);
            this.m_dataObjectDivider.MaximumSize = new System.Drawing.Size(225, 1);
            this.m_dataObjectDivider.MinimumSize = new System.Drawing.Size(200, 1);
            this.m_dataObjectDivider.Name = "m_dataObjectDivider";
            this.m_dataObjectDivider.Size = new System.Drawing.Size(200, 1);
            this.m_dataObjectDivider.TabIndex = 1;
            // 
            // m_dataObjectSubSection
            // 
            this.m_dataObjectSubSection.AutoSize = true;
            this.m_dataObjectSubSection.ColumnCount = 2;
            this.m_dataObjectSubSection.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.m_dataObjectSubSection.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.m_dataObjectSubSection.Controls.Add(this.m_lblName, 0, 0);
            this.m_dataObjectSubSection.Controls.Add(this.m_txtScanName, 1, 0);
            this.m_dataObjectSubSection.Controls.Add(this.m_lblStructure, 0, 1);
            this.m_dataObjectSubSection.Controls.Add(this.m_structureSubSection, 1, 2);
            this.m_dataObjectSubSection.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_dataObjectSubSection.Location = new System.Drawing.Point(3, 22);
            this.m_dataObjectSubSection.Name = "m_dataObjectSubSection";
            this.m_dataObjectSubSection.RowCount = 3;
            this.m_dataObjectSubSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_dataObjectSubSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_dataObjectSubSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_dataObjectSubSection.Size = new System.Drawing.Size(200, 91);
            this.m_dataObjectSubSection.TabIndex = 2;
            // 
            // m_lblName
            // 
            this.m_lblName.AutoSize = true;
            this.m_lblName.Dock = System.Windows.Forms.DockStyle.Left;
            this.m_lblName.Location = new System.Drawing.Point(3, 0);
            this.m_lblName.Name = "m_lblName";
            this.m_lblName.Size = new System.Drawing.Size(38, 26);
            this.m_lblName.TabIndex = 0;
            this.m_lblName.Text = "Name:";
            // 
            // m_txtScanName
            // 
            this.m_txtScanName.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_txtScanName.Location = new System.Drawing.Point(62, 3);
            this.m_txtScanName.Name = "m_txtScanName";
            this.m_txtScanName.Size = new System.Drawing.Size(135, 20);
            this.m_txtScanName.TabIndex = 0;
            this.m_txtScanName.Leave += new System.EventHandler(this.txtScanName_Leave);
            // 
            // m_lblStructure
            // 
            this.m_lblStructure.AutoSize = true;
            this.m_lblStructure.Dock = System.Windows.Forms.DockStyle.Left;
            this.m_lblStructure.Location = new System.Drawing.Point(3, 26);
            this.m_lblStructure.Name = "m_lblStructure";
            this.m_lblStructure.Size = new System.Drawing.Size(53, 13);
            this.m_lblStructure.TabIndex = 1;
            this.m_lblStructure.Text = "Structure:";
            // 
            // m_structureSubSection
            // 
            this.m_structureSubSection.AutoSize = true;
            this.m_structureSubSection.ColumnCount = 1;
            this.m_structureSubSection.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.m_structureSubSection.Controls.Add(this.m_rdBtnPointcloud, 1, 0);
            this.m_structureSubSection.Controls.Add(this.m_rdBtnPolygonalModel, 1, 1);
            this.m_structureSubSection.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_structureSubSection.Location = new System.Drawing.Point(62, 42);
            this.m_structureSubSection.Name = "m_structureSubSection";
            this.m_structureSubSection.RowCount = 2;
            this.m_structureSubSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_structureSubSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_structureSubSection.Size = new System.Drawing.Size(135, 46);
            this.m_structureSubSection.TabIndex = 2;
            // 
            // m_rdBtnPointcloud
            // 
            this.m_rdBtnPointcloud.AutoSize = true;
            this.m_rdBtnPointcloud.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_rdBtnPointcloud.Location = new System.Drawing.Point(3, 3);
            this.m_rdBtnPointcloud.Name = "m_rdBtnPointcloud";
            this.m_rdBtnPointcloud.Size = new System.Drawing.Size(129, 17);
            this.m_rdBtnPointcloud.TabIndex = 0;
            this.m_rdBtnPointcloud.TabStop = true;
            this.m_rdBtnPointcloud.Text = "Point Cloud";
            this.m_rdBtnPointcloud.UseVisualStyleBackColor = true;
            this.m_rdBtnPointcloud.CheckedChanged += new System.EventHandler(this.rdBtnPointcloud_CheckedChanged);
            // 
            // m_rdBtnPolygonalModel
            // 
            this.m_rdBtnPolygonalModel.Location = new System.Drawing.Point(3, 26);
            this.m_rdBtnPolygonalModel.Name = "m_rdBtnPolygonalModel";
            this.m_rdBtnPolygonalModel.Size = new System.Drawing.Size(103, 17);
            this.m_rdBtnPolygonalModel.TabIndex = 1;
            this.m_rdBtnPolygonalModel.TabStop = true;
            this.m_rdBtnPolygonalModel.Text = "Polygonal Model";
            this.m_rdBtnPolygonalModel.UseVisualStyleBackColor = true;
            this.m_rdBtnPolygonalModel.CheckedChanged += new System.EventHandler(this.rdBtnPolygonalModel_CheckedChanged);
            // 
            // m_parametersSection
            // 
            this.m_parametersSection.AutoSize = true;
            this.m_parametersSection.ColumnCount = 1;
            this.m_parametersSection.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.m_parametersSection.Controls.Add(this.m_lblParameters, 0, 0);
            this.m_parametersSection.Controls.Add(this.m_parametersDivider, 0, 1);
            this.m_parametersSection.Controls.Add(this.m_chkBoxAutomaticViewpoint, 0, 2);
            this.m_parametersSection.Controls.Add(this.m_chkBoxCreateNewDevicePosition, 0, 3);
            this.m_parametersSection.Dock = System.Windows.Forms.DockStyle.Fill;
            this.m_parametersSection.Location = new System.Drawing.Point(3, 125);
            this.m_parametersSection.Name = "m_parametersSection";
            this.m_parametersSection.RowCount = 4;
            this.m_parametersSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_parametersSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_parametersSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_parametersSection.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.m_parametersSection.Size = new System.Drawing.Size(206, 70);
            this.m_parametersSection.TabIndex = 1;
            // 
            // m_lblParameters
            // 
            this.m_lblParameters.Dock = System.Windows.Forms.DockStyle.Left;
            this.m_lblParameters.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.m_lblParameters.Location = new System.Drawing.Point(3, 0);
            this.m_lblParameters.Name = "m_lblParameters";
            this.m_lblParameters.Size = new System.Drawing.Size(100, 23);
            this.m_lblParameters.TabIndex = 0;
            this.m_lblParameters.Text = "Parameters";
            // 
            // m_parametersDivider
            // 
            this.m_parametersDivider.AutoSize = true;
            this.m_parametersDivider.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.m_parametersDivider.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.m_parametersDivider.Dock = System.Windows.Forms.DockStyle.Top;
            this.m_parametersDivider.Location = new System.Drawing.Point(3, 23);
            this.m_parametersDivider.MaximumSize = new System.Drawing.Size(225, 1);
            this.m_parametersDivider.MinimumSize = new System.Drawing.Size(0, 1);
            this.m_parametersDivider.Name = "m_parametersDivider";
            this.m_parametersDivider.Padding = new System.Windows.Forms.Padding(2, 0, 0, 2);
            this.m_parametersDivider.Size = new System.Drawing.Size(200, 1);
            this.m_parametersDivider.TabIndex = 0;
            // 
            // m_chkBoxAutomaticViewpoint
            // 
            this.m_chkBoxAutomaticViewpoint.AutoSize = true;
            this.m_chkBoxAutomaticViewpoint.Dock = System.Windows.Forms.DockStyle.Left;
            this.m_chkBoxAutomaticViewpoint.Location = new System.Drawing.Point(3, 27);
            this.m_chkBoxAutomaticViewpoint.Name = "m_chkBoxAutomaticViewpoint";
            this.m_chkBoxAutomaticViewpoint.Size = new System.Drawing.Size(121, 17);
            this.m_chkBoxAutomaticViewpoint.TabIndex = 0;
            this.m_chkBoxAutomaticViewpoint.Text = "Automatic viewpoint";
            this.m_chkBoxAutomaticViewpoint.CheckedChanged += new System.EventHandler(this.chkBoxAutomaticViewpoint_CheckedChanged);
            // 
            // m_chkBoxCreateNewDevicePosition
            // 
            this.m_chkBoxCreateNewDevicePosition.AutoSize = true;
            this.m_chkBoxCreateNewDevicePosition.Dock = System.Windows.Forms.DockStyle.Left;
            this.m_chkBoxCreateNewDevicePosition.Location = new System.Drawing.Point(3, 50);
            this.m_chkBoxCreateNewDevicePosition.Name = "m_chkBoxCreateNewDevicePosition";
            this.m_chkBoxCreateNewDevicePosition.Size = new System.Drawing.Size(195, 17);
            this.m_chkBoxCreateNewDevicePosition.TabIndex = 1;
            this.m_chkBoxCreateNewDevicePosition.Text = "Create new device position on scan";
            this.m_chkBoxCreateNewDevicePosition.UseVisualStyleBackColor = true;
            this.m_chkBoxCreateNewDevicePosition.CheckedChanged += new System.EventHandler(this.m_chkBoxCreateNewDevicePosition_CheckedChanged);
            // 
            // cDivider1
            // 
            this.cDivider1.AutoSize = true;
            this.cDivider1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.cDivider1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.cDivider1.Dock = System.Windows.Forms.DockStyle.Top;
            this.cDivider1.Location = new System.Drawing.Point(13, 191);
            this.cDivider1.MaximumSize = new System.Drawing.Size(225, 1);
            this.cDivider1.MinimumSize = new System.Drawing.Size(0, 1);
            this.cDivider1.Name = "cDivider1";
            this.cDivider1.Padding = new System.Windows.Forms.Padding(2, 0, 0, 2);
            this.cDivider1.Size = new System.Drawing.Size(212, 1);
            this.cDivider1.TabIndex = 5;
            // 
            // CDlgInspect
            // 
            this.AccessibleRole = System.Windows.Forms.AccessibleRole.Dialog;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(240, 259);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "CDlgInspect";
            this.ShowIcon = false;
            this.Text = "Scan";
            this.Shown += new System.EventHandler(this.Showned);
            this.Move += new System.EventHandler(this.Moved);
            this.m_internalLayout.ResumeLayout(false);
            this.m_internalLayout.PerformLayout();
            this.m_dataObjectSection.ResumeLayout(false);
            this.m_dataObjectSection.PerformLayout();
            this.m_dataObjectSubSection.ResumeLayout(false);
            this.m_dataObjectSubSection.PerformLayout();
            this.m_structureSubSection.ResumeLayout(false);
            this.m_structureSubSection.PerformLayout();
            this.m_parametersSection.ResumeLayout(false);
            this.m_parametersSection.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private CDivider cDivider1;
        private System.Windows.Forms.TableLayoutPanel m_dataObjectSection;
        private System.Windows.Forms.TableLayoutPanel m_dataObjectSubSection;
        private System.Windows.Forms.TableLayoutPanel m_parametersSection;
        private System.Windows.Forms.TableLayoutPanel m_structureSubSection;
        private System.Windows.Forms.Label m_lblDataObject;
        private System.Windows.Forms.Label m_lblParameters;
        private System.Windows.Forms.Label m_lblName;
        private System.Windows.Forms.Label m_lblStructure;
        private CDivider m_dataObjectDivider;
        private CDivider m_parametersDivider;
        private System.Windows.Forms.RadioButton m_rdBtnPointcloud;
        private System.Windows.Forms.TextBox m_txtScanName;
        private System.Windows.Forms.CheckBox m_chkBoxAutomaticViewpoint;
        private System.Windows.Forms.RadioButton m_rdBtnPolygonalModel;
        private System.Windows.Forms.CheckBox m_chkBoxCreateNewDevicePosition;
    }
}
