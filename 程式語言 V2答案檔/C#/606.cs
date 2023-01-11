using System;

public class TQC606
{
    public static void Main(string[] args)
    {
        string id1, id2, id3;
        id1 = Console.ReadLine();
        id2 = Console.ReadLine();
        id3 = Console.ReadLine();

        Console.WriteLine((ValidID(id1) ? "Pass" : "Fail"));
        Console.WriteLine((ValidID(id2) ? "Pass" : "Fail"));
        Console.Write((ValidID(id3) ? "Pass" : "Fail"));
    }

    public static bool ValidID(string id) {
        string checkCode = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
        int s1 = (id[0] - '0') + (id[2] - '0') + (id[4] - '0');
        int s2 = ((id[1] - '0') + (id[3] - '0')) * 5;
        int s3 = (s1 + s2) % 26;
        return checkCode[s3] == id[5];
    }
}