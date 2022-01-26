using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.Text = openFileDialog1.FileName;
                FileInfo finfo = new FileInfo(textBox1.Text);
                string strCTime = finfo.CreationTime.ToShortDateString();
                string strLATime = finfo.LastAccessTime.ToShortDateString();
                string strLWTime = finfo.LastWriteTime.ToShortDateString();
                string strName = finfo.Name;
                string strFName = finfo.FullName;
                string strDName = finfo.DirectoryName;
                string strISRead = finfo.IsReadOnly.ToString();
                long lgLength = finfo.Length;
                MessageBox.Show("文件信息：\n创建时间：" + strCTime + " 上次访问时间：" + strLATime + "\n上次写入时间：" + strLWTime + " 文件名称：" +
                    strName + "\n完整目录：" + strFName + "\n完整路径：" + strDName + "\n是否只读：" + strISRead + " 文件长度：" + lgLength);
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void 文件处理_Click(object sender, EventArgs e)
        {
            FileStream fs1 = new FileStream("D:\\小丑竟是你自己.txt", FileMode.Create, FileAccess.Write);
            File.SetAttributes(@"D:\\小丑竟是你自己.txt", FileAttributes.Hidden);
            string newTxtPath = "D:\\小丑竟是你自己.txt";
            StreamWriter sw = new StreamWriter(fs1);
            sw.WriteLine("哈哈哈哈，被你发现了！");
            sw.Flush();
        }
    }
    
    
}
