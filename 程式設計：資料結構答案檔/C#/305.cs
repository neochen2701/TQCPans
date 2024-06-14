using System;
using System.Collections.Generic;
using System.Linq;

class Employee
{
    public string EId { get; set; }
    public string EName { get; set; }
    public int Salary { get; set; }
    public string DId { get; set; }
}

class Department
{
    public string DId { get; set; }
    public string DName { get; set; }
    public string MId { get; set; }
}

class Project
{
    public string PId { get; set; }
    public string PName { get; set; }
    public string Location { get; set; }
}

class HourLog
{
    public string EId { get; set; }
    public string PId { get; set; }
    public int PHours { get; set; }
}

class ANS
{
    public string PName { get; set; }
    public int PHours { get; set; }
}

class Program
{
    static void Main()
    {
        var numInputs = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var employees = new List<Employee>();
        var departments = new List<Department>();
        var projects = new List<Project>();
        var hourLogs = new List<HourLog>();

        for (int i = 0; i < numInputs[0]; i++)
        {
            var inputs = Console.ReadLine().Split(' ');
            employees.Add(new Employee { EId = inputs[0], EName = inputs[1], Salary = int.Parse(inputs[2]), DId = inputs[3] });
        }

        for (int i = 0; i < numInputs[1]; i++)
        {
            var inputs = Console.ReadLine().Split(' ');
            departments.Add(new Department { DId = inputs[0], DName = inputs[1], MId = inputs[2] });
        }

        for (int i = 0; i < numInputs[2]; i++)
        {
            var inputs = Console.ReadLine().Split(' ');
            projects.Add(new Project { PId = inputs[0], PName = inputs[1], Location = inputs[2] });
        }

        for (int i = 0; i < numInputs[3]; i++)
        {
            var inputs = Console.ReadLine().Split(' ');
            hourLogs.Add(new HourLog { EId = inputs[0], PId = inputs[1], PHours = int.Parse(inputs[2]) });
        }

        string sName = Console.ReadLine();
        var employee = employees.FirstOrDefault(e => e.EName == sName);

        var ansList = new List<ANS>();
        if (employee != null)
        {
            foreach (var log in hourLogs.Where(h => h.EId == employee.EId))
            {
                var project = projects.FirstOrDefault(p => p.PId == log.PId);
                if (project != null)
                {
                    ansList.Add(new ANS { PName = project.PName, PHours = log.PHours });
                }
            }
        }

        int totalHours = ansList.Sum(a => a.PHours);
        ansList.OrderBy(a => a.PName).ToList().ForEach(a => Console.WriteLine($"{a.PName} {a.PHours}"));
        Console.WriteLine(totalHours);
    }
}
