import java.util.Scanner;

public class Main {

	static void build(int arr[], int tree[], int at, int l, int r) {
		if (l == r) {
			tree[at] = arr[l];
			return;
		}
		int mid = (l + r) / 2;
		build(arr, tree, at * 2, l, mid);
		build(arr, tree, at * 2 + 1, mid + 1, r);
		tree[at] = Math.min(tree[at * 2], tree[at * 2 + 1]);
	}

	static int query(int arr[], int tree[], int at, int l, int r, int x, int y) {
		if (x > r || y < l)
			return Integer.MAX_VALUE;
		if (l >= x && r <= y)
			return tree[at];
		int mid = (l + r) / 2;
		return Math.min(query(arr, tree, at * 2, l, mid, x, y), query(arr, tree, at * 2 + 1, mid + 1, r, x, y));
	}

	public static void main(String args[]) {
		Scanner ob = new Scanner(System.in);
		int T = ob.nextInt();
		for (int cs = 1; cs <= T; cs++) {
			int n = ob.nextInt();
			int q = ob.nextInt();
			int arr[] = new int[n];
			for (int i = 0; i < n; i++)
				arr[i] = ob.nextInt();
			int tree[] = new int[n * 4];
			build(arr, tree, 1, 0, n - 1);
			System.out.println("Case " + cs + ": ");
			for (int qq = 0; qq < q; qq++) {
				int x = ob.nextInt() - 1;
				int y = ob.nextInt() - 1;
				System.out.println(query(arr, tree, 1, 0, n - 1, x, y));
			}
		}
		ob.close();
	}

}
