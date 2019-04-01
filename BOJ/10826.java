import java.util.*;
import java.math.*;

public class Main
{
    public static void main (String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(), a=0;
        BigInteger s = new BigInteger("0");
        BigInteger t = new BigInteger("0");
        BigInteger p = new BigInteger("1");

        for(a=0;a<n;++a)
        {
            t = p;
            p = p.add(s);
            s = t;
        }
        System.out.print(s.toString());
    }
}