using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace K_means_영상처리_프로젝트
{
    public partial class Form1 : Form
    {
        Bitmap _bmp;
        int height, width;
        Random _rand = new Random();
        int k;
        Point[] centroids;
        Color colorData;
        double R, G, B,X,Y,Z , CR,CB,CG,CX,CY,CZ;
        double[,,] lab;
        double[,,] Clab;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                pictureBox1.Image = new Bitmap(dialog.FileName);
                _bmp = new Bitmap(pictureBox1.Image, pictureBox1.Image.Width, pictureBox1.Image.Height);

                height = _bmp.Height;
                width = _bmp.Width;
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            lab = new double[width, height, 3];
            Clab = new double[width, height, 3];
            k = int.Parse(textBoxCluster.Text);

            centroids = new Point[k];
            for (int i = 0; i < k; i++)
            centroids[i] = new Point(_rand.Next(width), _rand.Next(height));

            int[] distance = new int[k];
            RGBtansLab();

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    for (int i = 0; i < k; i++)
                    {
                        int l = Math.Abs((int)lab[x,y,0] - (int)Clab[centroids[i].X, centroids[i].Y, 0]);    // 데이터에서 중심점 까지의 거리 계산
                        int a = Math.Abs((int)lab[x,y,1] - (int)Clab[centroids[i].X, centroids[i].Y, 1]);
                        int b = Math.Abs((int)lab[x,y,2] - (int)Clab[centroids[i].X, centroids[i].Y, 2]);
                        distance[i] = (int)(Math.Sqrt(l * l + a * a) + Math.Sqrt(a * a + b * b) + Math.Sqrt(l * l + b * b));  // 유클리드 거리법    
                    }

                    int nearest = FindMinDistance(distance, k);  // 최단거리의 기준점
                    Color clr = _bmp.GetPixel(centroids[nearest].X, centroids[nearest].Y);  // 기준점 색깔   
                    _bmp.SetPixel(x, y, clr);     
                }
            }
            pictureBox2.Image = _bmp;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            _bmp = null;
            pictureBox1.Image = null;
            pictureBox2.Image = null;
        }

        private int FindMinDistance(int[] distance, int k)
        {
            int min = distance[0];
            int minIndex = 0;
            for (int i = 0; i < k; i++)
                if (distance[i] < min)
                {
                    min = distance[i];
                    minIndex = i;
                }
            return minIndex;
        }
        private void RGBtansLab()
        {
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < height; j++)
                {
                    colorData = _bmp.GetPixel(i, j);

                    R = colorData.R; G = colorData.G; B = colorData.B;
                    X = (0.490 * R) + (0.310 * G) + (0.200 * B);
                    Y = (0.177 * R) + (0.813 * G) + (0.011 * B);
                    Z = (0.0000 * R) + (0.0010 * G) + (0.990 * B);

                    double x0, y0, z0;

                    x0 = 0.95047;
                    y0 = 1.00000;
                    z0 = 1.08883;

                    if ((X / x0) > 0.008856) X = Math.Pow((X / x0), (1.0 / 3.0));
                    else
                        X = (7.787 * (X / x0)) + (16.0 / 116.0);
                    if ((Y / y0) > 0.008856) Y = Math.Pow((Y / y0), (1.0 / 3.0));
                    else
                        X = (7.787 * (Y / y0)) + (16.0 / 116.0);
                    if ((Z / z0) > 0.008856) X = Math.Pow((Z / z0), (1.0 / 3.0));
                    else
                        X = (7.787 * (Z / z0)) + (16.0 / 116.0);
                    lab[i, j, 0] = Math.Abs((116.0 * Y) - 16.0);
                    lab[i, j, 1] = Math.Abs(500 * (X - Y));
                    lab[i, j, 2] = Math.Abs(200 * (Y - Z));
                }
            }

                    for (int z = 0; z < k; z++)
                    {
                        CR = _bmp.GetPixel(centroids[z].X, centroids[z].Y).R;
                        CG = _bmp.GetPixel(centroids[z].X, centroids[z].Y).G;
                        CB = _bmp.GetPixel(centroids[z].X, centroids[z].Y).B;
                        CX = (0.490 * CR) + (0.310 * CG) + (0.200 * CB);
                        CY = (0.177 * CR) + (0.813 * CG) + (0.011 * CB);
                        CZ = (0.0000 * CR) + (0.0010 * CG) + (0.990 * CB);
                        double x1, y1, z1;

                        x1 = 0.95047;
                        y1 = 1.00000;
                        z1 = 1.08883;
                        if ((CX / x1) > 0.008856) CX = Math.Pow((CX / x1), (1.0 / 3.0));
                        else
                            CX = (7.787 * (CX / x1)) + (16.0 / 116.0);
                        if ((CY / y1) > 0.008856) CY = Math.Pow((CY / y1), (1.0 / 3.0));
                        else
                            CX = (7.787 * (CY / y1)) + (16.0 / 116.0);
                        if ((CZ / z1) > 0.008856) X = Math.Pow((CZ / z1), (1.0 / 3.0));
                        else
                            CX = (7.787 * (CZ / z1)) + (16.0 / 116.0);
                        Clab[centroids[z].X, centroids[z].Y, 0] = (116.0 * CY) - 16.0;
                        Clab[centroids[z].X, centroids[z].Y, 1] = 500 * (CX - CY);
                        Clab[centroids[z].X, centroids[z].Y, 2] = 200 * (CY - CZ);
                    }

        }


    }
}
