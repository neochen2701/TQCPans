#include <stdio.h>
#include <stdlib.h>

struct time
{
    int hour, minute;
};
int compute(struct time t[]);

int main()
{
    int i;
    struct time t[3];
    for (i = 0; i < 3; i++)
    {
        scanf("%d %d", &t[i].hour, &t[i].minute);
    }
    int am = compute(t);
    printf("%d\n", am);
    return 0;
}


int compute(struct time t[])
{
    int i;
    int am = 0;
    for (i = 0; i < 3; i++)
    {
        if (t[i].hour >= 0 && t[i].hour <= 11)
        {
            am += 1;
            if (t[i].hour == 0)
                printf("AM 12:%d\n", t[i].minute);
            else
                printf("AM %d:%d\n", t[i].hour, t[i].minute);
        }
        else
        {
            if (t[i].hour == 12)
                printf("PM 12:%d\n", t[i].minute);
            else
                printf("PM %d:%d\n", t[i].hour - 12, t[i].minute);
        }
    }
    return am;
}
