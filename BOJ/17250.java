import java.util.*;

public class Main {
    static int[] gr = new int [100001];
    static int[] sz = new int [100001];

    static int find(int p) {
        if (gr[p] == p) return p;
        gr[p] = find(gr[p]);
        return gr[p];
    }
    
    static int merge(int p, int q) {
        p = find(p);
        q = find(q);

        if (p == q) return sz[p];
    
        gr[p] = q;
        sz[q] += sz[p];
        sz[p] = 0;
        return sz[q];
    }
    
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        
        for (int i = 1; i <= n; ++i) {
            sz[i] = in.nextInt();
            gr[i] = i;
        }
    
        for (int i = 0; i < m; ++i) {
            int a = in.nextInt();
            int b = in.nextInt();
            System.out.printf("%d\n", merge(a, b));
        }
    }
}