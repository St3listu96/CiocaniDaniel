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

namespace DaniCiocani
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public string ByteArrayToString(byte[] ba)
        {
            StringBuilder hex = new StringBuilder(ba.Length * 2);
            foreach (byte b in ba)
                hex.AppendFormat("{0:x2}", b);
            return hex.ToString();
        }

        SymmetricAlgorithm mySymmetricAlg;
        ConversionHandler myConverter = new ConversionHandler();

        public void GenerateKey_2(string cipher)
        {
            switch (cipher)
            {
                case "DES":
                    mySymmetricAlg = DES.Create();
                    break;
                case "3DES":
                    mySymmetricAlg = TripleDES.Create();
                    break;
                case "Rijndael":
                    mySymmetricAlg = Rijndael.Create();
                    break;
                case "RC2":
                    mySymmetricAlg = RC2.Create();
                    break;
                case "AES":
                    mySymmetricAlg = Aes.Create();
                    break;
            }
            mySymmetricAlg.GenerateKey();
        }

        public void GenerateIV_2(string cipher)
        {
            switch (cipher)
            {
                case "DES":
                    mySymmetricAlg = DES.Create();
                    break;
                case "3DES":
                    mySymmetricAlg = TripleDES.Create();
                    break;
                case "Rijndael":
                    mySymmetricAlg = Rijndael.Create();
                    break;
                case "RC2":
                    mySymmetricAlg = RC2.Create();
                    break;
                case "AES":
                    mySymmetricAlg = Aes.Create();
                    break;
            }
            mySymmetricAlg.GenerateIV();
        }

        public byte[] Encrypt(byte[] mess, byte[] key, byte[] iv)
         {
         mySymmetricAlg.Key = key;
         mySymmetricAlg.IV = iv;
         MemoryStream ms = new MemoryStream();
         CryptoStream cs = new CryptoStream(ms,mySymmetricAlg.CreateEncryptor(),CryptoStreamMode.Write);
         cs.Write(mess, 0, mess.Length);
         cs.Close();
         return ms.ToArray();
         }

        public byte[] Decrypt(byte[] mess, byte[] key, byte[] iv)
         {
         byte[] plaintext = new byte[mess.Length];
         mySymmetricAlg.Key = key;
         mySymmetricAlg.IV = iv;
         MemoryStream ms = new MemoryStream(mess);
         CryptoStream cs = new CryptoStream(ms,mySymmetricAlg.CreateDecryptor(),CryptoStreamMode.Read);
         cs.Read(plaintext, 0, mess.Length);
         cs.Close();
         return plaintext;
         }

       

        private void button1_Click(object sender, EventArgs e)
        {
            GenerateKey_2(comboBox1.Text);
            textBoxKey.Text = ByteArrayToString(mySymmetricAlg.Key);
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            GenerateIV_2(comboBox1.Text);
            textBoxIV.Text = ByteArrayToString(mySymmetricAlg.IV);
        }

        private void btn_Encrypt(object sender, EventArgs e)
        {
            byte[] ciphertext = Encrypt(myConverter.StringToByteArray(textBox1.Text),myConverter.HexStringToByteArray(textBoxKey.Text),myConverter.HexStringToByteArray(textBoxIV.Text));
            textBox2.Text = myConverter.ByteArrayToHexString(ciphertext);
           
        }

        private void btn_Decrypt(object sender, EventArgs e)
        {
            byte[] plaintext =Decrypt(myConverter.HexStringToByteArray(textBox2.Text),myConverter.HexStringToByteArray(textBoxKey.Text),myConverter.HexStringToByteArray(textBoxIV.Text));
            textBox1.Text = myConverter.ByteArrayToString(plaintext);
            
        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {

        }
    }
}
