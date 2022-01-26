using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            treeView1.ContextMenuStrip = contextMenuStrip1;
            TreeNode TopNode = treeView1.Nodes.Add("公司");
            TreeNode ParentNode1 = new TreeNode("人事部");
            TreeNode ParentNode2 = new TreeNode("财务部");
            TreeNode ParentNode3 = new TreeNode("基础部");
            TreeNode ParentNode4 = new TreeNode("软件开发部");
            TopNode.Nodes.Add(ParentNode1);
            TopNode.Nodes.Add(ParentNode2);
            TopNode.Nodes.Add(ParentNode3);
            TopNode.Nodes.Add(ParentNode4);
            TreeNode ChildNode1 = new TreeNode("C#部门");
            TreeNode ChildNode2 = new TreeNode("ASP.NET部门");
            TreeNode ChildNode3 = new TreeNode("VB部门");
            TreeNode ChildNode4 = new TreeNode("VC部门");
            TreeNode ChildNode5 = new TreeNode("Java 部门");
            TreeNode ChildNode6 = new TreeNode("PHP部门");
            ParentNode4.Nodes.Add(ChildNode1);
            ParentNode4.Nodes.Add(ChildNode2);
            ParentNode4.Nodes.Add(ChildNode3);
            ParentNode4.Nodes.Add(ChildNode4);
            ParentNode4.Nodes.Add(ChildNode5);
            ParentNode4.Nodes.Add(ChildNode6);
            //imageList1.Images.Add(Image.FromFile("1,png"));
            //imageList1.Images.Add(Image.FromFile("2,png"));
            treeView1.ImageList = imageList1;
            imageList1.ImageSize = new Size(16, 16);
            treeView1.ImageIndex = 0;
            treeView1.SelectedImageIndex = 1;
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            Label label1 = new Label();
            label1.Text = "选择的部门：" + e.Node.Text;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
