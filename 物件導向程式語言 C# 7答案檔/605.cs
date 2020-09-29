using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Threading;
namespace CSA06
{
    class CSA06
    {
        static void Main(string[] args)
        {
            try
            {
                string str = Console.ReadLine();
                string[] data = str.Split(' ');
                if (data.Length != 3) { throw new Exception(); }
                Manager mm = new Manager(data[0].ToString(), data[1].ToString(), data[2].ToString());
                //TODO
                mm.login();
                Thread.Sleep(2000); // 2 sec.
                mm.logout();

                Console.Write("{0} Login {1},Logout {2}",
                    mm.name,
                    mm.logintime.ToString("yyyy/MM/dd HH:mm:ss"),
                    mm.logouttime.ToString("yyyy/MM/dd HH:mm:ss")); //TODO
                mm = null;
            }
            catch
            {
                Console.Write("error");
            }
            Console.ReadKey();
        }


    }

    public interface Ilogin
    {
        bool login();
    }
    public interface Ilogout
    {
        bool logout();
    }

    public class staff
    {
        public string name = "";
        public DateTime logintime;
        public DateTime logouttime;
        public string workdate;
        public string worktime;
    }
    //TODO --class Manager
    public class Manager : staff, Ilogin, Ilogout
    {
        public Manager(string name, string workdate, string worktime)
        {
            this.name = name;
            this.workdate = workdate;
            this.worktime = worktime;
        }

        public bool login()
        {
            DateTime date = DateTime.Parse(workdate);
            DateTime time = DateTime.Parse(worktime);
            this.logintime = new DateTime(
                date.Year, date.Month, date.Day,
                time.Hour, time.Minute, time.Second);
            return true;
        }

        public bool logout()
        {
            DateTime date = DateTime.Parse(workdate);
            DateTime time = DateTime.Parse(worktime);
            this.logouttime = new DateTime(
                date.Year, date.Month, date.Day,
                time.Hour, time.Minute, time.Second + 2);
            return true;
        }
    }

}
