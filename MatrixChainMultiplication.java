package java_algo;

import java.util.*;

/* A naive recursive implementation that simply follows
the above optimal substructure property */
class MatrixChainMultiplication {
	// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
	static String[] MatrixChainOrder(int p[], int i, int j) {
		String str[] = new String[2];
		str[0] = "0";
		if (i == j)
			return str;

		int min = Integer.MAX_VALUE;

//		System.out.println("...................");
		for (int k = i; k < j; k++) {

			int count = Integer.parseInt(MatrixChainOrder(p, i, k)[0])
					+ Integer.parseInt(MatrixChainOrder(p, k + 1, j)[0]) + p[i - 1] * p[k] * p[j];

			if (count < min) {
				min = count;
				str[0] = String.valueOf(min);
				String a = MatrixChainOrder(p, i, k)[1];
				if (MatrixChainOrder(p, i, k)[1] == null) {
					a = "0";
				}
				String b = MatrixChainOrder(p, k + 1, j)[1];
				if (MatrixChainOrder(p, k + 1, j)[1] == null) {
					b = "0";
				}
				str[1] = a + " + " + b + " + " + p[i - 1] + "*" + p[k] + "*" + p[j];

			}
		}
//		System.out.println(str[1] + " count " + str[0]);

		// Return minimum count
		return str;
	}

	// Driver code
	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter No Of Matrix To Be Multipied:");
		int n = sc.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter Size Array : ");
		System.out.println("(((( e.g. Suppose There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30."
				+ "then Size Array is [[40, 20, 30, 10, 30]] ))))");
		int i = 0;
		while (i < n) {

			int ai = sc.nextInt();
			arr[i] = ai;
			i++;
		}

		System.out.println("\n \n Minimum number of multiplications is " + MatrixChainOrder(arr, 1, n - 1)[0] + "\n"
				+ "obtained by " + MatrixChainOrder(arr, 1, n - 1)[1]);
	}
}
