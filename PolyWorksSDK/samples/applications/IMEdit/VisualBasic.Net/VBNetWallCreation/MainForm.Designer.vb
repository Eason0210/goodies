<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class MainForm
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.TextLog = New System.Windows.Forms.TextBox
        Me.ButtonStart = New System.Windows.Forms.Button
        Me.TextSource = New System.Windows.Forms.TextBox
        Me.LabelLog = New System.Windows.Forms.Label
        Me.LabelSource = New System.Windows.Forms.Label
        Me.SuspendLayout()
        '
        'TextLog
        '
        Me.TextLog.AcceptsReturn = True
        Me.TextLog.BackColor = System.Drawing.SystemColors.Window
        Me.TextLog.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextLog.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextLog.ForeColor = System.Drawing.SystemColors.WindowText
        Me.TextLog.Location = New System.Drawing.Point(5, 59)
        Me.TextLog.MaxLength = 0
        Me.TextLog.Multiline = True
        Me.TextLog.Name = "TextLog"
        Me.TextLog.ReadOnly = True
        Me.TextLog.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextLog.Size = New System.Drawing.Size(417, 193)
        Me.TextLog.TabIndex = 9
        '
        'ButtonStart
        '
        Me.ButtonStart.BackColor = System.Drawing.SystemColors.Control
        Me.ButtonStart.Cursor = System.Windows.Forms.Cursors.Default
        Me.ButtonStart.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.ButtonStart.ForeColor = System.Drawing.SystemColors.ControlText
        Me.ButtonStart.Location = New System.Drawing.Point(357, 16)
        Me.ButtonStart.Name = "ButtonStart"
        Me.ButtonStart.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.ButtonStart.Size = New System.Drawing.Size(65, 25)
        Me.ButtonStart.TabIndex = 7
        Me.ButtonStart.Text = "Start"
        Me.ButtonStart.UseVisualStyleBackColor = False
        '
        'TextSource
        '
        Me.TextSource.AcceptsReturn = True
        Me.TextSource.BackColor = System.Drawing.SystemColors.Window
        Me.TextSource.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextSource.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextSource.ForeColor = System.Drawing.SystemColors.WindowText
        Me.TextSource.Location = New System.Drawing.Point(5, 19)
        Me.TextSource.MaxLength = 0
        Me.TextSource.Name = "TextSource"
        Me.TextSource.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextSource.Size = New System.Drawing.Size(345, 20)
        Me.TextSource.TabIndex = 6
        '
        'LabelLog
        '
        Me.LabelLog.BackColor = System.Drawing.Color.Transparent
        Me.LabelLog.Cursor = System.Windows.Forms.Cursors.Default
        Me.LabelLog.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.LabelLog.ForeColor = System.Drawing.SystemColors.ControlText
        Me.LabelLog.Location = New System.Drawing.Point(5, 43)
        Me.LabelLog.Name = "LabelLog"
        Me.LabelLog.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.LabelLog.Size = New System.Drawing.Size(41, 17)
        Me.LabelLog.TabIndex = 8
        Me.LabelLog.Text = "Log:"
        '
        'LabelSource
        '
        Me.LabelSource.BackColor = System.Drawing.Color.Transparent
        Me.LabelSource.Cursor = System.Windows.Forms.Cursors.Default
        Me.LabelSource.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.LabelSource.ForeColor = System.Drawing.SystemColors.ControlText
        Me.LabelSource.Location = New System.Drawing.Point(5, 3)
        Me.LabelSource.Name = "LabelSource"
        Me.LabelSource.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.LabelSource.Size = New System.Drawing.Size(89, 17)
        Me.LabelSource.TabIndex = 5
        Me.LabelSource.Text = "Source pol file:"
        '
        'MainForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(426, 254)
        Me.Controls.Add(Me.TextLog)
        Me.Controls.Add(Me.ButtonStart)
        Me.Controls.Add(Me.TextSource)
        Me.Controls.Add(Me.LabelLog)
        Me.Controls.Add(Me.LabelSource)
        Me.Name = "MainForm"
        Me.Text = "PolyWorks|Modeler Wall Creation Sample"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Public WithEvents TextLog As System.Windows.Forms.TextBox
    Public WithEvents ButtonStart As System.Windows.Forms.Button
    Public WithEvents TextSource As System.Windows.Forms.TextBox
    Public WithEvents LabelLog As System.Windows.Forms.Label
    Public WithEvents LabelSource As System.Windows.Forms.Label

End Class
