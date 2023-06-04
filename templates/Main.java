import java.io.*;
import java.util.*;


public class Main  {

    static FastReader in =  new FastReader();
    static final Random random=new Random();
    static long mod=1000000007L;
    static HashMap<String,Integer>map=new HashMap<>();
    
    /******************************** Main code is here ********************************/
    
    static void solve() {
     

   	 map.clear();
    }

    /******************************** Main code is here ********************************/
 
    public static void main(String args[]) throws IOException {
        int t = 1;
        t = in.nextInt();
        while(t-->0)
        {
            solve();
        }
    }
 

 
    static int max(int a, int b)
    {
        if(a<b)
        	return b;
        return a;
    }
 
 
    static void ruffleSort(int[] a) {
        int n=a.length;
        for (int i=0; i<n; i++) {
            int oi=random.nextInt(n), temp=a[oi];
            a[oi]=a[i]; a[i]=temp;
        }
        Arrays.sort(a);
    }
 
    static < E > void print(E res)
    {
        System.out.println(res);
    }
 
 
    static  int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    
    static int arraygcd(int[] ar) {
    	int n = ar.length;
    	int result = ar[0];
    	for(int i = 1; i<n; i++) {
    		result = gcd(ar[i], result);
    	}
    	return result;
    }
 
    static int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
    
    static int arraylcm(int[] ar) {
    	int result = ar[0];
    	int n  = ar.length;
    	for(int i = 1; i<n; i++) {
    		result = lcm(result, ar[i]);
    	}
    	return result;
    }
 
 
    static int abs(int a)
    {
        if(a<0)
            return -1*a;
        return a;
    }
 
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
 
        int [] readintarray(int n) {
            int res [] = new int [n];
            for(int i = 0; i<n; i++)res[i] = nextInt();
            return res;
        }
        long [] readlongarray(int n) {
            long res [] = new long [n];
            for(int i = 0; i<n; i++)res[i] = nextLong();
            return res;
        }
    }
 
}