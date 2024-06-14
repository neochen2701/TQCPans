import java.util.Scanner;

public class JPA502 {
    private static class Result {
        int sum;
        int start;
        int end;

        Result(int sum, int start, int end) {
            this.sum = sum;
            this.start = start;
            this.end = end;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int[] arr = new int[input.length];

        for (int i = 0; i < input.length; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }

        if (arr.length == 0) {
            System.out.println("0\n0\n0");
            return;
        }

        Result result = maxSubarraySum(arr);
        System.out.println(result.sum);
        System.out.println(result.start);
        System.out.println(result.end);
    }

    private static Result maxSubarraySum(int[] arr) {
        int maxSum = arr[0], currentSum = arr[0];
        int start = 0, end = 0, tempStart = 0;

        for (int i = 1; i < arr.length; i++) {
            if (currentSum < 0) {
                currentSum = arr[i];
                tempStart = i;
            } else {
                currentSum += arr[i];
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
        }

        return new Result(maxSum, start, end);
    }
}
