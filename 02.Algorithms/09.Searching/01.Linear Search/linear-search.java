public class Search {
    public static void main(String[] args) {
        int arr[] = {12, 52, 69, 78, 23, 5, 6, 8, 4, 64};
        int r = linearSearch(arr, 69);
        if (r == -1) {
            System.out.println("Element is not present in array");
        } else {
            System.out.println("Element is present at index " + r);
        }
    }

    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
}
