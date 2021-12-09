static bool WithinBounds((int x, int y) move, (int x, int y) currentPos, int maxX, int maxY) =>
    WithinBoundsOnAxis(move.x, currentPos.x, maxX) && WithinBoundsOnAxis(move.y, currentPos.y, maxY);

static bool WithinBoundsOnAxis(int move, int currentPos, int max) =>
    move + currentPos >= 0 && move + currentPos < max;

static int[][] GetDepths() =>
    File.ReadLines("input.txt").Select(line => line.ToArray()).Select(charArray => charArray.Select(c => c - '0').ToArray()).ToArray();

static List<(int x, int y)> FindLocalOptima(int[][] depths)
{
    List<(int x, int y)> moves = new() { (0, 1), (0, -1), (1, 0), (-1, 0) };
    List<(int, int)> localOptima = new();

    for(int i = 0; i< depths.Length; i++)
    {
        for(int j = 0; j < depths[i].Length; j++)
        {
            if (moves.Where(move => WithinBounds(move, (i, j), depths.Length, depths[i].Length)).All(move => depths[i][j] < depths[i + move.x][j + move.y]))
            {
                localOptima.Add((i, j));
            }
        }
    }

    return localOptima;
}

static string Problem1()
{
    int[][] depths = GetDepths();
    return $"{FindLocalOptima(depths).Select(pos => depths[pos.x][pos.y]).Sum()}";
}

static string Problem2()
{
    List<(int x, int y)> moves = new() { (0, 1), (0, -1), (1, 0), (-1, 0) };

    int[][] depths = GetDepths();
    bool[,] visited = new bool[depths.Length, depths[0].Length];

    List<(int x, int y)> localOptima = FindLocalOptima(depths);

    List<int> basinCount = new();

    foreach((int x, int y) in localOptima)
    {
        int counter = 0;

        Queue<(int x, int y)> adjacentPositions = new();
        adjacentPositions.Enqueue((x, y));

        while(adjacentPositions.Count > 0)
        {
            var currentPos = adjacentPositions.Dequeue();

            if (depths[currentPos.x][currentPos.y] != 9 && !visited[currentPos.x, currentPos.y])
            {
                visited[currentPos.x, currentPos.y] = true;
                counter++;

                foreach((int moveX, int moveY) in moves.Where(move => WithinBounds(move, (currentPos.x, currentPos.y), depths.Length, depths[0].Length)))
                {
                    adjacentPositions.Enqueue((currentPos.x + moveX, currentPos.y + moveY));
                }
            }
        }

        basinCount.Add(counter);
    }

    basinCount.Sort((x, y) => y - x);

    return $"{basinCount.Take(3).Aggregate(1, (result, next) => result * next)}";
}

Console.WriteLine(Problem1());
Console.WriteLine(Problem2());
