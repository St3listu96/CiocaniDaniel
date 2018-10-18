using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Security.Cryptography;
using System.IO;

namespace CiocaniDaniel
{
    public partial class Form1 : Form
    {

        ConversionHandler myConverter = new ConversionHandler();
        SymmetricAlgorithm mySymmetricAlg;

        public Form1()
        {
            InitializeComponent();
        }

        static string Hash(string input)
        {
            using (SHA1Managed sha1 = new SHA1Managed())
            {
                var hash = sha1.ComputeHash(Encoding.UTF8.GetBytes(input));
                var sb = new StringBuilder(hash.Length * 2);

                foreach (byte b in hash)
                {
                    sb.Append(b.ToString("X2"));
                }

                return sb.ToString();
            }
        }

        public void Generate()
        {
            mySymmetricAlg = DES.Create();
            mySymmetricAlg.IV = myConverter.StringToByteArray("12345678");
            mySymmetricAlg.GenerateKey();
        }        public byte[] Encrypt(byte[] mess, byte[] key) {
            mySymmetricAlg.Key = key;
            mySymmetricAlg.IV = myConverter.StringToByteArray("12345678");
            MemoryStream ms = new MemoryStream();
            CryptoStream cs = new CryptoStream(ms,mySymmetricAlg.CreateEncryptor(),CryptoStreamMode.Write);
            cs.Write(mess, 0, mess.Length);
            cs.Close();
            return ms.ToArray();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Generate();
            byte[] ciphertext = Encrypt(myConverter.StringToByteArray(Hash(textBox.Text)),mySymmetricAlg.Key);
            textBoxHash.Text = myConverter.ByteArrayToHexString(ciphertext);
            textBoxLength.Text = textBoxHash.Text.Length.ToString();
            

        }
    }
}
