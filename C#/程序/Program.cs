using System;

namespace MineClearance
{
    class Program
    {
        static void Main(string[] args)
        {
            string copyright = "SimpleMine v1.0 by Arliy ArliyCoder@gmail.com";
            MineGame game = null;
            try
            {
                game = new MineGame(copyright, int.Parse(args[0]), int.Parse(args[1]), int.Parse(args[2]));
            }
            catch
            {
                game = new MineGame(copyright);
            }
            game.Run();
        }
    }

    /*
     * /
     * Program : MineGame.cs   
     * Resume  : 游戏控制类，提供键盘操作:
     *           方向键控制光标位置;
     *           Z/z键扫描雷;
     *           X/x键标记雷;
     *           Y/y键重新游戏;
     *           N/y键退出游戏;
     * 
     * /
     * Modifiy History
     * 
     * Date    :
     * Resume  :
     * 
     */
    public class MineGame
    {
        #region fields

        private Mine mine;//扫雷类

        #endregion

        #region constructors

        public MineGame(string title)
        {
            mine = new Mine();
            Console.Title = title;
        }

        public MineGame(string title, int width, int height, int mineCount)
        {
            mine = new Mine(width, height, mineCount);
            Console.Title = title;
        }

        #endregion

        #region public functions

        /// <summary>
        /// 启动扫雷游戏
        /// </summary>
        public void Run()
        {
            int x, y;
        Start:
            x = y = 0;
            mine.Render();
            Console.SetCursorPosition(0, 0);
            while (!mine.IsGameOver && !mine.IsSucceed())
            {
                ConsoleKeyInfo key = Console.ReadKey(true);
                switch (key.Key)
                {
                    case ConsoleKey.LeftArrow:
                        x = x > 0 ? x - 1 : x;
                        break;
                    case ConsoleKey.RightArrow:
                        x = x < mine.Height - 1 ? x + 1 : x;
                        break;
                    case ConsoleKey.UpArrow:
                        y = y > 0 ? y - 1 : y;
                        break;
                    case ConsoleKey.DownArrow:
                        y = y < mine.Width - 1 ? y + 1 : y;
                        break;
                    case ConsoleKey.Z:
                        mine.ScanMine(y, x);
                        mine.Render();
                        break;
                    case ConsoleKey.X:
                        mine.MarkMine(y, x);
                        mine.Render();
                        break;
                    default:
                        break;
                }
                Console.SetCursorPosition(x * 2, y);
            }

            Console.ForegroundColor = ConsoleColor.Gray;
            Console.SetCursorPosition(30, 21);
            if (mine.IsGameOver)
                Console.WriteLine("You lose the fucking game!");
            else
                Console.WriteLine("Well done!");

            Console.SetCursorPosition(33, 22);
            Console.WriteLine("\tRetry the game? (Y/y) or (N/n)...");

            Console.SetCursorPosition(33, 23);
            if (Console.ReadLine().ToUpper() == "Y")
            {
                mine.Reset();
                goto Start;
            }
        }

        #endregion
    }

    /*
     * /
     * Program : Mine.cs   
     * Resume  : 扫雷类,用二维byte类型数组表示，其中每个byte元素存储雷区区域信息：
     *           高4位存储区域数据，当值为9时表示该区域为地雷；
     *           低4位存储区域标记，包括空标记0000(0x00)、已扫描标记0001(0x01)与雷标记0010(0x02)；
     * /
     * Modifiy History
     * 
     * Date    :
     * Resume  :
     * 
     */
    public class Mine
    {
        #region fields

        private const byte MINE_FLAG_NULL = 0x00;//空标记
        private const byte MINE_FLAG_SCAN = 0x01;//已扫描标记
        private const byte MINE_FLAG_MARK = 0x02;//雷标记
        private const byte MINE_DATA_NULL = 0x00;//空值
        private const byte MINE_DATA_MINE = 0x90;//雷值

        private byte[,] mines;//雷区数据
        private bool isGameOver;//是否游戏结束
        private int initCount;//初始雷数
        private int mineCount;//当前雷数
        private int markCount;//可标记雷数
        private int width;//雷区宽度
        private int height;//雷区高度

        #endregion

        #region properties

        public int Width
        {
            get { return width; }
        }

        public int Height
        {
            get { return height; }
        }

        public bool IsGameOver
        {
            get { return isGameOver; }
        }

        #endregion

        #region constructors

        public Mine()
        {
            InitMineArea(9, 9, 10);
        }

        public Mine(int width, int height, int mineCount)
        {
            //取值范围
            width = width <= 0 ? 9 : width;
            width = width > 20 ? 20 : width;
            height = height <= 0 ? 9 : height;
            height = height > 39 ? 39 : height;
            mineCount = (mineCount > width * height) ? width * height : mineCount;
            InitMineArea(width, height, mineCount);
        }

        #endregion

        #region public functions

        /// <summary>
        /// 在指定位置扫描雷区
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        public void ScanMine(int x, int y)
        {
            //当前位置已经扫描过
            if ((mines[x, y] & 0x0f) != MINE_FLAG_NULL)
                return;
            //当前位置是地雷，游戏结束
            if ((mines[x, y] & 0xf0) == MINE_DATA_MINE)
            {
                isGameOver = true;
                return;
            }
            //置空
            mines[x, y] = MINE_DATA_NULL;
            //递归进行扫描
            RecursiveScanMine(x, y);
        }

        /// <summary>
        /// 在指定位置设置雷标记
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        public void MarkMine(int x, int y)
        {
            byte data = (byte)(mines[x, y] & 0xf0);
            switch ((byte)(mines[x, y] & 0x0f))
            {
                case MINE_FLAG_NULL:
                    if (markCount > 0)
                    {
                        //置雷标记
                        mines[x, y] |= MINE_FLAG_MARK;
                        //如果当前位置是雷，减少雷数
                        mineCount = data == MINE_DATA_MINE ? mineCount - 1 : mineCount;
                        //减少雷标记数量
                        markCount--;
                    }
                    break;
                case MINE_FLAG_MARK:
                    {
                        //取消雷标记
                        mines[x, y] ^= MINE_FLAG_MARK;
                        //如果当前位置是雷，增加雷数
                        mineCount = data == MINE_DATA_MINE ? mineCount + 1 : mineCount;
                        //增加雷标记数量
                        markCount++;
                    }
                    break;
                default:
                    break;
            }
        }

        /// <summary>
        /// 绘制雷区
        /// </summary>
        public void Render()
        {
            Console.Clear();
            for (int i = 0; i < mines.GetLength(0); i++)
            {
                for (int j = 0; j < mines.GetLength(1); j++)
                {
                    Console.ForegroundColor = ConsoleColor.Gray;
                    byte data = (byte)((mines[i, j] >> 4) & 0x0f);
                    if (isGameOver && data == 0x09)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write("¤");
                        continue;
                    }
                    switch ((byte)(mines[i, j] & 0x0f))
                    {
                        case MINE_FLAG_NULL:
                            Console.Write("■");
                            break;
                        case MINE_FLAG_SCAN:
                            Console.ForegroundColor = ConsoleColor.DarkGray;
                            if (data == MINE_DATA_NULL)
                                Console.Write("□");
                            else
                                ColourNumber(data);
                            break;
                        case MINE_FLAG_MARK:
                            Console.ForegroundColor = ConsoleColor.Yellow;
                            Console.Write("♀");
                            break;
                        default:
                            break;
                    }
                }
                Console.WriteLine();
            }
            Console.ForegroundColor = ConsoleColor.Gray;
            for (int i = 0; i < height; i++) Console.Write("--");
            Console.WriteLine();
            Console.WriteLine(string.Format("Size:{0}*{1}", mines.GetLength(0), mines.GetLength(1)));
            Console.WriteLine(string.Format("Mine:{0}", initCount));
            Console.WriteLine(string.Format("Mark:{0}", markCount));
        }

        /// <summary>
        /// 是否扫雷成功
        /// </summary>
        /// <returns></returns>
        public bool IsSucceed()
        {
            int count = 0;
            for (int i = 0; i < mines.GetLength(0); i++)
            {
                for (int j = 0; j < mines.GetLength(1); j++)
                {
                    if ((mines[i, j] & 0x0f) != MINE_FLAG_SCAN)
                        count++;
                }
            }
            //未扫描过的雷区数量为雷数则扫雷成功，否则继续扫雷
            return count == initCount ? true : false;
        }

        /// <summary>
        /// 重置
        /// </summary>
        public void Reset()
        {
            for (int i = 0; i < mines.GetLength(0); i++)
            {
                for (int j = 0; j < mines.GetLength(1); j++)
                    mines[i, j] = MINE_DATA_NULL;
            }

            this.mineCount = initCount;
            this.markCount = initCount;
            this.isGameOver = false;

            SetRandomMine(initCount);
            StatistikMineCount();
        }

        #endregion

        #region private functions

        /// <summary>
        /// 初始化雷区
        /// </summary>
        /// <param name="width">雷区宽度</param>
        /// <param name="height">雷区高度</param>
        /// <param name="mineCount">雷数</param>
        private void InitMineArea(int width, int height, int mineCount)
        {
            //初始化雷区
            mines = new byte[width, height];
            for (int i = 0; i < mines.GetLength(0); i++)
            {
                for (int j = 0; j < mines.GetLength(1); j++)
                    mines[i, j] = MINE_DATA_NULL;
            }
            //随机分布雷
            SetRandomMine(mineCount);
            //统计雷区数据
            StatistikMineCount();

            this.width = width;
            this.height = height;
            this.mineCount = mineCount;
            this.initCount = mineCount;
            this.markCount = mineCount;
            this.isGameOver = false;
        }

        /// <summary>
        /// 随机分布雷
        /// </summary>
        /// <param name="minecount">雷数</param>
        private void SetRandomMine(int minecount)
        {
            Random random = new Random(Environment.TickCount);
            int x;
            int y;
            int temp = minecount;
            while (minecount > 0)
            {
                x = random.Next(0, mines.GetLength(0));
                y = random.Next(0, mines.GetLength(1));
                if (mines[x, y] == MINE_DATA_NULL)
                {
                    mines[x, y] = MINE_DATA_MINE;
                    minecount--;
                }
            }
        }

        /// <summary>
        /// 统计雷区数据
        /// </summary>
        private void StatistikMineCount()
        {
            for (int i = 0; i < mines.GetLength(0); i++)
            {
                for (int j = 0; j < mines.GetLength(1); j++)
                {
                    if (mines[i, j] != MINE_DATA_MINE)
                    {
                        mines[i, j] = (byte)(StatistikMineCountAt(i, j) << 4);
                    }
                }
            }
        }

        /// <summary>
        /// 计算指定位置周围雷数
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        private int StatistikMineCountAt(int x, int y)
        {
            int minecount = 0;
            for (int i = x - 1; i <= x + 1; i++)
            {
                if (i <= -1 || i >= mines.GetLength(0)) continue;
                for (int j = y - 1; j <= y + 1; j++)
                {
                    if (((j <= -1) || (j >= mines.GetLength(1))) || (i == x && j == y))
                        continue;
                    if (mines[i, j] == MINE_DATA_MINE)
                    {
                        minecount++;
                    }
                }
            }
            return minecount;
        }

        /// <summary>
        /// 递归方式扫描无雷区域
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        private void RecursiveScanMine(int x, int y)
        {
            //边界检测
            if ((x < 0 || x >= mines.GetLength(0)) ||
                (y < 0 || y >= mines.GetLength(1)))
            {
                return;
            }
            //排除已扫描的区域或是有雷区域
            if (((mines[x, y] & 0x0f) != MINE_FLAG_NULL) || ((mines[x, y] & 0xf0) == MINE_DATA_MINE))
            {
                return;
            }
            if ((mines[x, y] & 0xf0) != MINE_DATA_NULL)
            {
                mines[x, y] |= MINE_FLAG_SCAN;
                return;
            }
            //置已扫描标记
            mines[x, y] |= MINE_FLAG_SCAN;
            //目标区域八方向递归扫描
            RecursiveScanMine(x - 1, y - 1);
            RecursiveScanMine(x - 1, y);
            RecursiveScanMine(x - 1, y + 1);
            RecursiveScanMine(x, y - 1);
            RecursiveScanMine(x, y + 1);
            RecursiveScanMine(x + 1, y - 1);
            RecursiveScanMine(x + 1, y);
            RecursiveScanMine(x + 1, y + 1);
        }

        /// <summary>
        /// 格式化/着色数字
        /// </summary>
        /// <param name="value"></param>
        private void ColourNumber(int value)
        {
            Console.ForegroundColor = MineData.ColorTable[value];
            Console.Write(MineData.FormatNumbers[value]);
        }

        #endregion
    }

    /*
     * /
     * Program : MineData.cs
     * Author  : Arliy (ArliyCoder#gmail.com) 
     * Date    : 2013/7/15     
     * Resume  : 格式化数据
     * 
     * /
     * Modifiy History
     * 
     * Date    :
     * Resume  :
     * 
     */
    public class MineData
    {
        public static string[] FormatNumbers = { "", "①", "②", "③", "④", "⑤", "⑥", "⑦", "⑧" };
        public static ConsoleColor[] ColorTable =
        {
            ConsoleColor.Gray,
            ConsoleColor.White,
            ConsoleColor.DarkGreen,
            ConsoleColor.Green,
            ConsoleColor.DarkYellow,
            ConsoleColor.Magenta,
            ConsoleColor.Blue,
            ConsoleColor.Cyan
        };
    }
}
