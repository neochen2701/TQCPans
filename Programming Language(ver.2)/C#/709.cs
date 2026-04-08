using System;
using System.Collections.Generic;

public class TQC709
{
    public class Circle {
        private double x, y;
        private double radius;

        public double X => x;
        public double Y => y;
        public double Radius => radius;

        public Circle(double _x, double _y, double _r) {
            this.x = _x;
            this.y = _y;
            this.radius = _r;
        }

        public double GetArea() {
            return radius * radius * 3.14159;
        }
        
        public string GetPointInfo() {
            return "x: " + x.ToString() + ", y: " + y.ToString();
        }

        public string GetRadiusInfo() {
            return "radius: " + radius.ToString();
        }
    }

    public static void Main(string[] args)
    {
        List<Circle> circleList = new List<Circle>();
        int n;
        n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++) {
            string[] inp = Console.ReadLine().Split(' ');
            circleList.Add(new Circle(Convert.ToDouble(inp[0]), Convert.ToDouble(inp[1]), Convert.ToDouble(inp[2])));
        }

        Circle maxCir = new Circle(0, 0, 0);
        double totalArea = 0.00;
        foreach (Circle cir in circleList) {
            totalArea += cir.GetArea();
            if (cir.GetArea() > maxCir.GetArea()) {
                maxCir = cir;
            }
        }

        Console.WriteLine("Sum = " + totalArea.ToString("F2"));
        Console.WriteLine(maxCir.GetPointInfo());
        Console.Write(maxCir.GetRadiusInfo());
    }
}