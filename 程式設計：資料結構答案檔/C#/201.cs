using System;
using System.Collections.Generic;

class Program
{
    static List<int> tasks = new List<int>();

    static bool RequestQuests(string input)
    {
        bool success = true;
        string[] taskStrings = input.Split(',');

        foreach (string taskString in taskStrings)
        {
            if (int.TryParse(taskString, out int taskReward))
            {
                if (taskReward >= 0)
                    tasks.Add(taskReward);
                else
                {
                    Console.WriteLine("error");
                    success = false;
                    break;
                }
            }
            else
            {
                Console.WriteLine("error");
                success = false;
                break;
            }
        }
        return success;
    }

    static void Main()
    {
        string input = Console.ReadLine();

        if (RequestQuests(input))
        {
            int totalReward = CalculateTotalReward(tasks);
            Console.WriteLine(totalReward);
        }
    }

    static int CalculateTotalReward(List<int> tasks)
    {
        int totalReward = 0;
        Queue<int> taskQueue = new Queue<int>(tasks);

        int morningTasks = 3;
        int noonTasks = 2;
        int nightTasks = 1;

        while (taskQueue.Count > 0)
        {
            for (int i = 0; i < morningTasks && taskQueue.Count > 0; i++)
            {
                totalReward += taskQueue.Dequeue() * 3;
            }

            for (int i = 0; i < noonTasks && taskQueue.Count > 0; i++)
            {
                totalReward += taskQueue.Dequeue() * 2;
            }

            for (int i = 0; i < nightTasks && taskQueue.Count > 0; i++)
            {
                totalReward += taskQueue.Dequeue();
            }
        }

        return totalReward;
    }
}
