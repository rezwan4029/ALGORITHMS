public class Main {

	public static int findMin(int[] nums) {
		if (nums == null || nums.length == 0)
			return -1;

		int lo = 0;
		int hi = nums.length - 1;

		while (nums[lo] > nums[hi]) {

			int mid = (lo + hi) >> 1;

			if (nums[mid] > nums[hi]) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}

		return nums[lo];
	}

	public static void main(String[] args) {
		// [2,1], [2,3,1], [3,1,2]
		int a[] = { 5, 6, 8, 2, 3, 4 };
		System.err.println(findMin(a));
	}

}
