#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

typedef struct employee_s
{
    char e_id[SIZE];
    char e_name[SIZE];
    int salary;
    char d_id[SIZE];
} Employee;

typedef struct department_s
{
    char d_id[SIZE];
    char d_name[SIZE];
    char m_id[SIZE];
} Department;

typedef struct project_s
{
    char p_id[SIZE];
    char p_name[SIZE];
    char location[SIZE];
} Project;

typedef struct hourLog_s
{
    char e_id[SIZE];
    char p_id[SIZE];
    int p_hours;
} HourLog;

typedef struct num_s
{
    int e_num;
    int d_num;
    int p_num;
    int h_num;
} Num;
typedef struct ans_s
{
    char p_name[SIZE];
    int p_hours;
} ANS;
void getData(Employee e[], Department d[], Project p[], HourLog h[], Num *np)
{
    scanf("%d %d %d %d", &np->e_num, &np->d_num, &np->p_num, &np->h_num);
    for (int i = 0; i < np->e_num; i++)
        scanf("%s %s %d %s", e[i].e_id, e[i].e_name, &e[i].salary, e[i].d_id);
    for (int i = 0; i < np->d_num; i++)
        scanf("%s %s %s", d[i].d_id, d[i].d_name, d[i].m_id);
    for (int i = 0; i < np->p_num; i++)
        scanf("%s %s %s", p[i].p_id, p[i].p_name, p[i].location);
    for (int i = 0; i < np->h_num; i++)
        scanf("%s %s %d", h[i].e_id, h[i].p_id, &h[i].p_hours);
}
int getEmployeeIndex(char *s_name, Employee employees[], int n)
{
    int e_index = 0;
    for (int i = 0; i < n; i++)
        if (strcmp(employees[i].e_name, s_name) == 0)
            return (e_index = i);
}
int compareName(const void *a, const void *b)
{
    ANS *p1 = (ANS *)a, *p2 = (ANS *)b;
    return (strcmp(p1->p_name, p2->p_name));
}
void printAns(ANS ans[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s %d\n", ans[i].p_name, ans[i].p_hours);
    }
}
void searchData(char *e_id, Project p[], HourLog h[], Num num)
{
    int hours = 0, ans_num = 0;
    ANS ans[SIZE];
    for (int j = 0; j < num.h_num; j++)
    {
        if (strcmp(h[j].e_id, e_id) == 0)
        {
            for (int k = 0; k < num.p_num; k++)
            {
                if (strcmp(h[j].p_id, p[k].p_id) == 0)
                {
                    strcpy(ans[ans_num].p_name, p[k].p_name);
                    ans[ans_num++].p_hours = h[j].p_hours;
                    hours += h[j].p_hours;
                }
            }
        }
    }
    qsort(ans, ans_num, sizeof(ANS), compareName);
    printAns(ans, ans_num);
    printf("%d\n", hours);
}
int main()
{
    Employee employees[SIZE];
    Department departments[SIZE];
    Project projects[SIZE];
    HourLog hour_logs[SIZE];
    Num num;
    char s_name[SIZE];
    int e_index = 0;
    getData(employees, departments, projects, hour_logs, &num);
    scanf("%s", s_name);
    e_index = getEmployeeIndex(s_name, employees, num.e_num);
    searchData(employees[e_index].e_id, projects, hour_logs, num);
    return 0;
}
