using System.Text.RegularExpressions;

static string Problem1()
{
    Regex regex = new Regex(@"(?<command>\w+) (?<value>[0-9]+)");

    int x = 0, y = 0;
    foreach (string line in File.ReadLines("input.txt"))
    {
        var match = regex.Match(line);
        var value = int.Parse(match.Groups["value"].Value);

        switch (match.Groups["command"].Value)
        {
            case "down":
                y += value;
                break;
            case "up":
                y -= value;
                break;
            case "forward":
                x += value;
                break;
        }
    }

    return $"{x * y}";
}

static string Problem2()
{
    Regex regex = new Regex(@"(?<command>\w+) (?<value>[0-9]+)");

    int x = 0, y = 0, aim = 0;
    foreach (string line in File.ReadLines("input.txt"))
    {
        var match = regex.Match(line);
        var value = int.Parse(match.Groups["value"].Value);

        switch (match.Groups["command"].Value)
        {
            case "down":
                aim += value;
                break;
            case "up":
                aim -= value;
                break;
            case "forward":
                x += value;
                y += aim * value;
                break;
        }
    }

    return $"{x * y}";
}

Console.WriteLine(Problem1());
Console.WriteLine(Problem2());
