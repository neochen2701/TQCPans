using System;

class Monster
{
    public int Value { get; set; }
    public Monster Next { get; set; }

    public Monster(int value)
    {
        Value = value;
        Next = null;
    }
}

class BattleSimulator
{
    private Monster head;

    public BattleSimulator()
    {
        head = null;
    }

    public void CreateMonsters(string input)
    {
        string[] values = input.Split(',');

        foreach (string value in values)
        {
            if (int.TryParse(value, out int monsterAttack))
            {
                AddMonster(monsterAttack);
            }
            else
            {
                Console.WriteLine("input error");
            }
        }
    }

    public void AddMonster(int value)
    {
        Monster newNode = new Monster(value);

        if (head == null)
        {
            head = newNode;
        }
        else
        {
            Monster current = head;
            while (current.Next != null)
            {
                current = current.Next;
            }
            current.Next = newNode;
        }
    }

    public bool SimulateBattle(int playerHP)
    {
        Monster current = head;
        int level = 1;

        while (current != null)
        {
            playerHP -= current.Value;

            if (playerHP <= 0)
            {
                Console.WriteLine(string.Format("game over! dead at level {0}", level));
                return false; 
            }

            level++;
            current = current.Next;
        }

        Console.WriteLine(string.Format("game clear! hp left {0}", playerHP));
        return true; 
    }
}


class Program
{
    static void Main()
    {
        string input = Console.ReadLine();

        BattleSimulator battle = new BattleSimulator();
        battle.CreateMonsters(input);

        int playerHP = 100;
        battle.SimulateBattle(playerHP);
    }

}
