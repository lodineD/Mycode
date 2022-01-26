using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp16
{
    class Program
    {
        public void Table(string[,] table)
        {
            Console.Clear();
            Console.WriteLine("———————————————售票显示台————————————————");
            Console.ForegroundColor = ConsoleColor.Green;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (table[i, j] == "【无座】")
                    {
                        Console.ResetColor();
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write(table[i, j] + "\t");
                        Console.ResetColor();
                        Console.ForegroundColor = ConsoleColor.Green;
                    }
                    else
                    {
                        Console.Write(table[i, j] + "\t");
                    }
                }
                Console.WriteLine();
            }
            Console.ResetColor();
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.WriteLine("请输入购票的位置(如2,4为第二行，第四列),输入Q/q退出");
        }

        public void Gettable(string[,] table)
        {

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    table[i, j] = "【有票】";
                }
            }
        }
        static void Main(string[] args)
        {
            Console.Title = "简单的售票机";
            Program pro = new Program();
            string[,] table = new string[5, 5];
            pro.Gettable(table);
            pro.Table(table);
            while (true)
            {
                string str1 = Console.ReadLine();
                string[] a = str1.Split(',');
                if (str1 == "q" || str1 == "Q")
                {
                    break;
                }
                pro.Changetable(a, table);
                pro.Table(table);
                
            }
            Console.WriteLine("购票结束");
        }

        private void Changetable(string[] a, string[,] table)
        {
            int num1 = int.Parse(a[0]);
            int num2 = int.Parse(a[1]);
            table[num1-1, num2-1] = "【无座】";
        }
    }
}   