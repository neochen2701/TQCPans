using System;
using System.Collections.Generic;

public class TQC708
{
    public class TimeStorage {
        private int hour;
        private int minute;

        public TimeStorage(int _hour, int _minute) {
            this.hour = _hour;
            this.minute = _minute;
        }

        public int GetHour24() {
            return hour;
        }

        public int GetHour12() {
            if (IsTimeInAM()) {
                if (hour == 0)
                    return 12;
                else
                    return hour;
            }
            else {
                if (hour == 12)
                    return 12;
                else
                    return hour - 12;
            }
        }

        public int GetMinute() {
            return minute;
        }

        public bool IsTimeInAM() {
            if (hour < 12)
                return true;
            else
                return false;
        }

        public override string ToString() {
            string am_pm = IsTimeInAM() ? "AM" : "PM";
            string time = GetHour12().ToString() + ":" + GetMinute().ToString();
            return am_pm + " " + time;
        }
    }

    public static void Main(string[] args)
    {
        int amCount = 0;
        List<TimeStorage> timeStorageList = new List<TimeStorage>();
        for (int i = 0; i < 3; i++) {
            string[] inpArray = Console.ReadLine().Split(' ');
            int hour = Convert.ToInt32(inpArray[0]);
            int minute = Convert.ToInt32(inpArray[1]);
            timeStorageList.Add(new TimeStorage(hour, minute));
        }

        foreach (TimeStorage timeStorage in timeStorageList) {
            if (timeStorage.IsTimeInAM()) {
                amCount++;
            }
            Console.WriteLine(timeStorage.ToString());
        }
        Console.Write(amCount);
    }
}