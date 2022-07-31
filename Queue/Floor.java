import java.io.*;
import java.lang.*;
import java.util.*;

class Codechef {

  public static void main(String[] args) throws java.lang.Exception {
    Scanner scn = new Scanner(System.in);
    int T = scn.nextInt();

    while (T != 0) {
      int X = scn.nextInt();
      int Y = scn.nextInt();
      System.out.print(
		Math.round(
			Math.ceil(
				Math.abs(
					(X - Y) / 10
				)
			)
		)
      );
      System.out.print("\n");
      T--;
    }
  }
}
