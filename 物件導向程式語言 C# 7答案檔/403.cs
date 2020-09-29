using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSA04
{
    class CSA04
    {
        static string[] meetingDates = { "2018/12/01 14:00", "2018/12/02 15:00", "2018/12/03 10:30","2018/12/03 15:30","2018/12/04 15:00" };
        static int[] meetingHours = { 1, 3, 4 , 2, 5};
		static void Main(string[] args)
        {
            try
            {
                DateTime newMeeting = Convert.ToDateTime(Console.ReadLine());
                bool isOverlap = false;
                string meetingOverlap = "";
                for(int i = 0; i <= meetingDates.Length - 1; i++)
                {
                    DateTime startMeeting = Convert.ToDateTime(meetingDates[i].ToString());
                    DateTime endMeeting = startMeeting.AddHours(meetingHours[i]);
                    if(DateTime.Compare(newMeeting, startMeeting)>=0 && DateTime.Compare(newMeeting, endMeeting) < 0)
                    {
                        isOverlap = true;
                        meetingOverlap = meetingDates[i].ToString();
                        break;
                    }
                }
                if (isOverlap)
                {
                    Console.Write("Has already reserved - "+ meetingOverlap);
                }
                else
                {
                    Console.Write("Reservation completed - "+ newMeeting.ToString("yyyy/MM/dd HH:mm"));
                }
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }
    }
}
