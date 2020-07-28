using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace backpropagation
{
    class Program
    {
        static void Main(string[] args)
        {
            
        }
    }
    class activate
    {
        private double y;

        public double sigmoid(int x)
        {
            y = 1 / (1 + Math.Exp(-x));
            return y;
        }
    }
    class ver
    {
        Random r = new Random();
        private int[,,,] x;
        private double[] w1;
        private double[] w2;
        private int b;
        public v(int[,,,] x)
        {
            for (int i = 0; i < x.Length; i++)
            {
                for (int j = 0; j < x.Length; j++)
                {
                    for (int r = 0; r < x.Length; r++)
                    {
                        for (int s = 0; s < x.Length; s++)
                        {
                            this.x[i, j, r, s] = x[i, j, r, s];
                        }
                    }
                }
            }
            for(int q=0; q<4;q++)
            {
                w1[q] = 2 * r.NextDouble() - 1;
                w2[q] = 2 * r.NextDouble() - 1;
            }
        }
        public double v()
        {
            
        }
    }
}

