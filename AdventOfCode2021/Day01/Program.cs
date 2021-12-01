// Part 1
{
    uint previousDepth = uint.MaxValue;
    uint depthIncreaseCounter = 0;

    foreach (uint depth in File.ReadLines("input.txt").Select(s => uint.Parse(s)))
    {
        if (depth > previousDepth)
        {
            depthIncreaseCounter++;
        }

        previousDepth = depth;
    }

    Console.WriteLine(depthIncreaseCounter);
}

// Part 2
{
    uint depthIncreaseCounter = 0;

    uint[] depthWindow = new uint[3] { 10_000, 10_000, 10_000 };
    long depthWindowSum = long.MaxValue;

    foreach (uint depth in File.ReadLines("input.txt").Select(s => uint.Parse(s)))
    {
        depthWindow[0] = depthWindow[1];
        depthWindow[1] = depthWindow[2];
        depthWindow[2] = depth;

        long newDepthWindowSum = depthWindow.Sum(x => x);
        if (newDepthWindowSum > depthWindowSum)
        {
            depthIncreaseCounter++;
        }

        depthWindowSum = newDepthWindowSum;
    }

    Console.WriteLine(depthIncreaseCounter);
}