using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Security.Cryptography;
using WindowsFormsApplication3;

namespace RSA
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        RSACryptoServiceProvider myRSA = new RSACryptoServiceProvider(2048);
        ConversionHandler myConversion = new ConversionHandler();
        public string privateKey;
        public string publicKey;
        SHA256Managed myHash = new SHA256Managed();
        bool verificare;
        byte[] semnatura;

        private void button1_Click(object sender, EventArgs e)
        {

            privateKey = myRSA.ToXmlString(true);
            publicKey = myRSA.ToXmlString(false);

            textBoxPrivate.Text = privateKey;
            textBoxPublic.Text = publicKey;
        }

        private void button2_Click(object sender, EventArgs e)
        {
          
            textBoxHash.Text = myConversion.ByteArrayToHexString(myRSA.Encrypt(myConversion.StringToByteArray(textBoxPlain.Text), true));
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBoxPlain.Text = myConversion.ByteArrayToString(myRSA.Decrypt(myConversion.HexStringToByteArray(textBoxHash.Text), true));
        }

        private void button4_Click(object sender, EventArgs e)
        {
            semnatura = myRSA.SignData(myConversion.StringToByteArray(textBoxSign.Text), myHash);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            verificare = myRSA.VerifyData(myConversion.StringToByteArray(textBoxSign.Text), myHash, semnatura);
            if (verificare == true)
                label1.Text = "OK";
            else
                label1.Text = "NOK";
        }



        



    }
}
