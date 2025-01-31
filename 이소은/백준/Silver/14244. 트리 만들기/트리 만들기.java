import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner (System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		int cur = 0;
        int lastLeaf = 0;
		
		if (m==2) cur = 1;
		for (int i=1; i<n; i++) {
			if (m > cur) { 
				System.out.println(0 + " "  +i);
				cur++;
			} else System.out.println(lastLeaf + " " + i);
			lastLeaf = i;
		}
		sc.close();
	}
}