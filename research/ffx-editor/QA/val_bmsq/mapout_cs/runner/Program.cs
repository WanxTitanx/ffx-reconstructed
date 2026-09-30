using System;
using MapoutVpaFull;
class P {
  static void Main(string[] a) {
    foreach (var p in a) {
      var r = Parser.Go(p);
      Console.WriteLine($"{System.IO.Path.GetFileName(System.IO.Path.GetDirectoryName(System.IO.Path.GetDirectoryName(p)))}: status={r.S} fam={r.F} size={r.Sz} rings={(r.Rings?.Count ?? -1)} tris={(r.Tris?.Count ?? -1)} note=\"{r.N}\"");
    }
  }
}
