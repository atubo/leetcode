import LeetcodeUtil.*;
import java.util.*;

public class MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int A[], int B[]) {
        int n = A.length + B.length;
        if (n % 2 == 1) {
            return (double)findKth(A, 0, B, 0, n/2);
        } else {
            return ((double)(findKth(A, 0, B, 0, n/2) + findKth(A, 0, B, 0, n/2-1)))/2;
        }
    }
    
    private int findKth(int[] A, int startA, int[] B, int startB, int k) {
        if (startA >= A.length) {
            return B[startB + k];
        }
        if (startB >= B.length) {
            return A[startA + k];
        }
        if (k == 0) {
            return Math.min(A[startA], B[startB]);
        }
        if (k == 1) {
            ArrayList<Integer> array = new ArrayList<Integer>();
            array.add(A[startA]);
            array.add(B[startB]);
            if (startA + 1 < A.length) {
                array.add(A[startA + 1]);
            }
            if (startB + 1 < B.length) {
                array.add(B[startB + 1]);
            }
            Collections.sort(array);
            return array.get(1);
        }
        if (A.length < B.length) {
            int[] C = A;
            A = B;
            B = C;
            int tmp = startA;
            startA = startB;
            startB = tmp;
        }
        int halfK = k / 2;
        if (B.length - 1 < startB + halfK) {
            int a = A[startA + halfK];
            int b = B[B.length - 1];
            if (a > b) {
                return findKth(A, startA + halfK, B, B.length, k - halfK - B.length + startB);
            } else {
                return findKth(A, startA + halfK, B, startB, k - halfK);
            }
        }
        int a = A[startA + halfK];
        int b = B[startB + halfK];
        if (a < b) {
            return findKth(A, startA + halfK, B, startB, k - halfK);
        } else {
            return findKth(A, startA, B, startB + halfK, k - halfK);
        }
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] A = reader.readArray();
        int[] B = reader.readArray();
        
        MedianOfTwoSortedArrays solution = new MedianOfTwoSortedArrays();
        double result = solution.findMedianSortedArrays(A, B);
        System.out.println(result);
    }
}