namespace RSA
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
            this.textBoxPublic = new System.Windows.Forms.TextBox();
            this.textBoxPrivate = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.textBoxPlain = new System.Windows.Forms.TextBox();
            this.textBoxHash = new System.Windows.Forms.TextBox();
            this.button4 = new System.Windows.Forms.Button();
            this.textBoxSign = new System.Windows.Forms.TextBox();
            this.button5 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // textBoxPublic
            // 
            this.textBoxPublic.Location = new System.Drawing.Point(181, 27);
            this.textBoxPublic.Name = "textBoxPublic";
            this.textBoxPublic.Size = new System.Drawing.Size(248, 20);
            this.textBoxPublic.TabIndex = 0;
            // 
            // textBoxPrivate
            // 
            this.textBoxPrivate.Location = new System.Drawing.Point(181, 72);
            this.textBoxPrivate.Name = "textBoxPrivate";
            this.textBoxPrivate.Size = new System.Drawing.Size(248, 20);
            this.textBoxPrivate.TabIndex = 1;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 29);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(147, 62);
            this.button1.TabIndex = 2;
            this.button1.Text = "Generate";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(12, 123);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(146, 41);
            this.button2.TabIndex = 3;
            this.button2.Text = "Encrypt";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(12, 186);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(147, 40);
            this.button3.TabIndex = 4;
            this.button3.Text = "Decrypt";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // textBoxPlain
            // 
            this.textBoxPlain.Location = new System.Drawing.Point(181, 134);
            this.textBoxPlain.Name = "textBoxPlain";
            this.textBoxPlain.Size = new System.Drawing.Size(248, 20);
            this.textBoxPlain.TabIndex = 5;
            // 
            // textBoxHash
            // 
            this.textBoxHash.Location = new System.Drawing.Point(181, 198);
            this.textBoxHash.Name = "textBoxHash";
            this.textBoxHash.Size = new System.Drawing.Size(247, 20);
            this.textBoxHash.TabIndex = 6;
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(12, 251);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(145, 33);
            this.button4.TabIndex = 7;
            this.button4.Text = "Sign";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // textBoxSign
            // 
            this.textBoxSign.Location = new System.Drawing.Point(181, 259);
            this.textBoxSign.Name = "textBoxSign";
            this.textBoxSign.Size = new System.Drawing.Size(246, 20);
            this.textBoxSign.TabIndex = 8;
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(12, 301);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(147, 27);
            this.button5.TabIndex = 9;
            this.button5.Text = "Verify";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(316, 308);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 13);
            this.label1.TabIndex = 10;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(476, 346);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.textBoxSign);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.textBoxHash);
            this.Controls.Add(this.textBoxPlain);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBoxPrivate);
            this.Controls.Add(this.textBoxPublic);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxPublic;
        private System.Windows.Forms.TextBox textBoxPrivate;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.TextBox textBoxPlain;
        private System.Windows.Forms.TextBox textBoxHash;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.TextBox textBoxSign;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Label label1;
    }
}

