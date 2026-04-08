using System;
using System.Collections.Generic;

public class TQC710
{
    public class FIFO {
        private int[] memorySpace;
        private int size;
        private int fifoIter = 0;
        private int FIFOIter {
            get { return fifoIter; }
            set {
                if (value >= size) {
                    value = 0;
                }
                fifoIter = value;
            }
        }
        public int Size => size;

        private bool IsPageInMemory(int page) {
            for (int i = 0; i < size; i++) {
                if (memorySpace[i] == page)
                    return true;
            }
            return false;
        }

        public FIFO(int size) {
            this.size = size;
            memorySpace = new int[size];
            for (int i = 0; i < size; i++) // init
                memorySpace[i] = 0;
        }

        public void AddPage(int page) {
            if (IsPageInMemory(page))
                return;
            
            memorySpace[FIFOIter++] = page;
        }

        public bool IsMemoryFull() {
            return !IsPageInMemory(0);
        }

        public override string ToString() {
            string res = "";
            for (int i = 0; i < size; i++) {
                res += memorySpace[i].ToString() + " ";
            }
            return res;
        }
    }

    public static void Main(string[] args)
    {
        List<string> outputList = new List<string>();
        FIFO fifo = new FIFO(4);
        for (int i = 0; i < 10; i++) {
            int page = int.Parse(Console.ReadLine());
            fifo.AddPage(page);
            outputList.Add(fifo.ToString());
        }

        for (int i = 0; i < outputList.Count; i++) {
            if (i == outputList.Count - 1) {
                Console.Write(outputList[i]);
            }
            else {
                Console.WriteLine(outputList[i]);
            }
        }
    }
}