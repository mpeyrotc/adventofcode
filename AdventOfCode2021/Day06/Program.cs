static string Problem(int days)
{
    List<int> initialDaysTillOffspring = File.ReadAllText("input.txt").Split(',').Select(int.Parse).ToList();
    long[] daysTillOffspring = new long[9];

    foreach (int day in initialDaysTillOffspring)
    {
        daysTillOffspring[day]++;
    }

    for (int i = 0; i < days; i++)
    {
        long newFish = daysTillOffspring[0];
        for (int j = 1; j < 9; j++)
        {
            daysTillOffspring[j - 1] = daysTillOffspring[j];
        }

        daysTillOffspring[8] = newFish;
        daysTillOffspring[6] += newFish;
    }

    return $"{daysTillOffspring.Sum()}";
}

Console.WriteLine(Problem(80));
Console.WriteLine(Problem(256));