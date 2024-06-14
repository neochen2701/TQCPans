using System;
using System.Collections.Generic;
using System.Linq;

class BinaryTreeTraversal {
    static string[] lst;

    static void InorderTree(int idx) {
        if (idx < lst.Length && lst[idx] != "") {
            InorderTree(2 * idx);
            Console.Write(lst[idx]);
            InorderTree(2 * idx + 1);
        }
    }

    static void LeafNode() {
        List<string> leaves = new List<string>();
        
        for (int i = 1; i < lst.Length; i++) {
            if ((2 * i >= lst.Length || lst[2 * i] == "") && (2 * i + 1 >= lst.Length || lst[2 * i + 1] == "")) {
                leaves.Add(lst[i]);
            }
        }
        
        leaves.Sort();
        Console.WriteLine(string.Join("", leaves));
    }

    static void Main(string[] args) {
        string inp = Console.ReadLine();
        lst = new string[] {null}.Concat(inp.Split(',')).ToArray();

        InorderTree(1);
        Console.WriteLine();
        LeafNode();
    }
}
