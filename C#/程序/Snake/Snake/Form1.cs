using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Snake
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
    }

    class Node
    {
        #region 字段
        private int x;
        private int y;
        private int width = 10;
        private bool isFood = false;
        private bool isPass = true;//是否可通过
        private Color bgColor = Color.FromArgb(224, 224, 224);
        private Color foodColor = Color.Green;
        private Color hinderColor = Color.Black;
        private Color thisColor;
        private Color serpentColor = Color.Chocolate;

        #endregion
        /// <summary>
        /// 设置食物参数
        /// </summary>
        /// <param name="_isFood"></param>
        public void SetFood(bool _isFood)
        {
            IsFood = _isFood;
            if (_isFood)
            {
                ThisColor = FoodColor;

            }
            else
            {
                ThisColor = BgColor;
            }
        }

        /// <summary>
        /// 设置障碍物参数
        /// </summary>
        /// <param name="_isHinder">是否为障碍物</param>
        public void SetHinder(bool _isHinder)
        {
            IsPass = !_isHinder;
            if (_isHinder)
            {
                ThisColor = HinderColor;
            }
            else
            {
                ThisColor = BgColor;
            }
        }

        /// <summary>
        /// 设置蛇颜色
        /// </summary>
        /// <param name="_isSerpent"></param>
        public void SetSerpent(bool _isSerpent)
        {
            IsPass = !_isSerpent;
            if (_isSerpent)
            {
                ThisColor = SerpentColor;
            }
            else
            {
                ThisColor = BgColor;
            }
        }
        #region 构造函数
        public Node()
        {
            thisColor = bgColor;
        }

        /// <summary>
        /// 有参构造方法
        /// </summary>
        /// <param name="_x">相对x坐标</param>
        /// <param name="_y">相对y坐标</param>
        /// <param name="_width">边长</param>
        /// <param name="_isFood">是否是食物</param>
        /// <param name="_isPass">是否可通过</param>
        public Node(int _x, int _y, int _width, bool _isFood, bool _isPass)
        {
            thisColor = bgColor;
            X = _x;
            Y = _y;
            Width = _width;
            IsFood = _isFood;
            IsPass = _isPass;
        }

        /// <summary>
        /// 有参构造方法
        /// </summary>
        /// <param name="_x">相对x坐标</param>
        /// <param name="_y">相对y坐标</param>
        /// <param name="_width">边长</param>
        public Node(int _x, int _y, int _width)
        {
            X = _x;
            Y = _y;
            Width = _width;
        }

        /// <summary>
        /// 有参构造方法
        /// </summary>
        /// <param name="_x">相对x坐标</param>
        /// <param name="_y">相对y坐标</param>
        public Node(int _x, int _y)
        {
            X = _x;
            Y = _y;
        }
        #endregion

        #region 属性
        /// <summary>
        /// 蛇颜色
        /// </summary>
        public Color SerpentColor
        {
            get { return serpentColor; }
        }

        /// <summary>
        /// 背景色
        /// </summary>
        public Color BgColor
        {
            get { return bgColor; }
        }

        /// <summary>
        /// 食物颜色
        /// </summary>
        public Color FoodColor
        {
            get { return foodColor; }
        }

        /// <summary>
        /// 障碍物颜色
        /// </summary>
        public Color HinderColor
        {
            get { return hinderColor; }
        }

        /// <summary>
        /// 当前颜色
        /// </summary>
        public Color ThisColor
        {
            get { return thisColor; }
            set { thisColor = value; }
        }

        /// <summary>
        /// 获取或设置相对横坐标
        /// </summary>
        public int X
        {
            get { return x; }
            set { x = value; }
        }

        /// <summary>
        /// 获取或设置相对纵坐标
        /// </summary>
        public int Y
        {
            get { return y; }
            set { y = value; }
        }

        /// <summary>
        /// 获取或设置节点边长
        /// </summary>
        public int Width
        {
            get { return width; }
            set { width = value; }
        }

        /// <summary>
        /// 获取或设置是否为食物
        /// </summary>
        public bool IsFood
        {
            get { return isFood; }
            set { isFood = value; }
        }

        /// <summary>
        /// 获取或设置是否可以通过
        /// </summary>
        public bool IsPass
        {
            get { return isPass; }
            set { isPass = value; }
        }
        #endregion
    }
    class Map
    {
        /// <summary>
        /// 节点数组
        /// </summary>
        private List<List<Node>> _nodes;
        private int RowCount;
        private int ComsCount;
        private Color bgColor = Color.FromArgb(224, 224, 224);
        private System.Windows.Forms.Control MapPanel;
        Graphics g;
        /// <summary>
        /// 地图背景色 和node中背景色一致
        /// </summary>
        public Color BgColor
        {
            get { return bgColor; }
        }
        /// <summary>
        /// 构造方法
        /// </summary>
        /// <param name="rows">行数</param>
        /// <param name="coms">列数</param>
        public Map(int rows, int coms, System.Windows.Forms.Control c)
        {
            RowCount = rows;
            ComsCount = coms;
            MapPanel = c;
            g = c.CreateGraphics();
            _nodes = new List<List<Node>>();
            for (int i = 0; i < rows; i++)//行
            {
                List<Node> index = new List<Node>();
                for (int j = 0; j < coms; j++)
                {
                    Node node = new Node(j, i);
                    index.Add(node);
                }
                _nodes.Add(index);
            }
        }

        /// <summary>
        /// 
    }
}
