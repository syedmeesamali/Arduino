﻿namespace Arduino_Serial
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.Degree_0 = new System.Windows.Forms.Button();
            this.Degree_45 = new System.Windows.Forms.Button();
            this.Degree_90 = new System.Windows.Forms.Button();
            this.Degree_135 = new System.Windows.Forms.Button();
            this.Degree_180 = new System.Windows.Forms.Button();
            this.cmdExit = new System.Windows.Forms.Button();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            this.SuspendLayout();
            // 
            // Degree_0
            // 
            this.Degree_0.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Degree_0.Location = new System.Drawing.Point(28, 180);
            this.Degree_0.Name = "Degree_0";
            this.Degree_0.Size = new System.Drawing.Size(88, 51);
            this.Degree_0.TabIndex = 0;
            this.Degree_0.Text = "0 Deg";
            this.Degree_0.UseVisualStyleBackColor = true;
            this.Degree_0.Click += new System.EventHandler(this.Degree_0_Click);
            // 
            // Degree_45
            // 
            this.Degree_45.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Degree_45.Location = new System.Drawing.Point(75, 84);
            this.Degree_45.Name = "Degree_45";
            this.Degree_45.Size = new System.Drawing.Size(88, 51);
            this.Degree_45.TabIndex = 1;
            this.Degree_45.Text = "45 deg";
            this.Degree_45.UseVisualStyleBackColor = true;
            this.Degree_45.Click += new System.EventHandler(this.Degree_45_Click);
            // 
            // Degree_90
            // 
            this.Degree_90.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Degree_90.Location = new System.Drawing.Point(187, 22);
            this.Degree_90.Name = "Degree_90";
            this.Degree_90.Size = new System.Drawing.Size(88, 51);
            this.Degree_90.TabIndex = 2;
            this.Degree_90.Text = "90 deg";
            this.Degree_90.UseVisualStyleBackColor = true;
            this.Degree_90.Click += new System.EventHandler(this.Degree_90_Click);
            // 
            // Degree_135
            // 
            this.Degree_135.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Degree_135.Location = new System.Drawing.Point(300, 84);
            this.Degree_135.Name = "Degree_135";
            this.Degree_135.Size = new System.Drawing.Size(88, 51);
            this.Degree_135.TabIndex = 3;
            this.Degree_135.Text = "135 deg";
            this.Degree_135.UseVisualStyleBackColor = true;
            this.Degree_135.Click += new System.EventHandler(this.Degree_135_Click);
            // 
            // Degree_180
            // 
            this.Degree_180.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Degree_180.Location = new System.Drawing.Point(374, 180);
            this.Degree_180.Name = "Degree_180";
            this.Degree_180.Size = new System.Drawing.Size(88, 51);
            this.Degree_180.TabIndex = 4;
            this.Degree_180.Text = "180 deg";
            this.Degree_180.UseVisualStyleBackColor = true;
            this.Degree_180.Click += new System.EventHandler(this.Degree_180_Click);
            // 
            // cmdExit
            // 
            this.cmdExit.Location = new System.Drawing.Point(176, 185);
            this.cmdExit.Name = "cmdExit";
            this.cmdExit.Size = new System.Drawing.Size(124, 36);
            this.cmdExit.TabIndex = 5;
            this.cmdExit.Text = "&Exit";
            this.cmdExit.UseVisualStyleBackColor = true;
            this.cmdExit.Click += new System.EventHandler(this.cmdExit_Click);
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(58, 260);
            this.trackBar1.Maximum = 180;
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(368, 45);
            this.trackBar1.TabIndex = 6;
            this.trackBar1.Scroll += new System.EventHandler(this.trackBar1_Scroll);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(141, 308);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Degrees:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(206, 308);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(0, 13);
            this.label2.TabIndex = 8;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(489, 360);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.trackBar1);
            this.Controls.Add(this.cmdExit);
            this.Controls.Add(this.Degree_180);
            this.Controls.Add(this.Degree_135);
            this.Controls.Add(this.Degree_90);
            this.Controls.Add(this.Degree_45);
            this.Controls.Add(this.Degree_0);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Arduino Serial Connection";
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Degree_0;
        private System.Windows.Forms.Button Degree_45;
        private System.Windows.Forms.Button Degree_90;
        private System.Windows.Forms.Button Degree_135;
        private System.Windows.Forms.Button Degree_180;
        private System.Windows.Forms.Button cmdExit;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

