using System;
using System.Collections.Generic;

class Activity
{
    public int Start { get; set; }
    public int End { get; set; }

    public Activity(int start, int end)
    {
        Start = start;
        End = end;
    }
}

class Program
{
    static void Main()
    {
        int numActivities = int.Parse(Console.ReadLine());
        List<Activity> activities = new List<Activity>();

        for (int i = 0; i < numActivities; i++)
        {
            string[] input = Console.ReadLine().Split(',');
            int start = int.Parse(input[0]);
            int end = int.Parse(input[1]);
            activities.Add(new Activity(start, end));
        }

        activities.Sort((a, b) => a.End.CompareTo(b.End));

        int selectedActivities = 1;
        Activity currentActivity = activities[0];
        for (int i = 1; i < numActivities; i++)
        {
            if (currentActivity.End <= activities[i].Start)
            {
                currentActivity = activities[i];
                selectedActivities++;
            }
        }

        Console.WriteLine(selectedActivities);
    }
}
