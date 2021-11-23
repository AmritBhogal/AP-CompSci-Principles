using System;
using System.Linq;

Console.Write("Enter compressed: ");
string message = Console.ReadLine();
string[] split = message.Split('_');

string[] duplicates = split.GroupBy(str => str)
                            .Where(str => str.Count() > 1)
                            .Select(str => str.Key)
                            .ToArray();

Console.WriteLine("Duplicates:");

foreach (string dup in duplicates)
{
    Console.WriteLine(dup);
}
