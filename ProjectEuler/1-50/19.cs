using System;

namespace Main
{
  class Program
  {
    static void Main(string[] args)
    {
      int ans = 0;
      for (var date = new DateTime(1901, 1, 1); date.Year <= 2000; date = date.AddDays(1))
        if(date.DayOfWeek == DayOfWeek.Sunday && date.Day == 1)
          ans++;
      Console.WriteLine(ans);
    }
  }
}
