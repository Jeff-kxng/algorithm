/*
Problem: LAB.02.02 - Cut Material
Description
Given a material having the shape rectangle with height H and width W. We need to cut this material into n smaller rectangle submaterials of size (h1,w1), (h2, w2), ..., (hn, wn). Write a program to check if we can perform this cut.
Input
Line 1: contains two positive integers H, W (1 <= H, W <= 10)
Line 2: contains a positive integer n (1 <= n <= 10)
Line i+2 (i= 1,...,n): contains two positive integer hi and wi (1 <= hi, wi <= 10)
Output
Write 1 if we can perform the cut and write 0, otherwise.
Example
Input
7 5
4
1 5
6 2
2 2
4 3
Output
1
 */
/*
 Java code
 import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int n = scanner.nextInt();
        int[][] submaterials = new int[n][2];
        for (int i = 0; i < n; i++) {
            submaterials[i][0] = scanner.nextInt();
            submaterials[i][1] = scanner.nextInt();
        }
        scanner.close();
        Arrays.sort(submaterials, (a, b) -> Math.max(b[0], b[1]) - Math.max(a[0], a[1]));
        boolean[][] material = new boolean[H][W];
        System.out.println(canPerformCut(material, submaterials, 0) ? "1" : "0");
    }

    public static boolean canPerformCut(boolean[][] material, int[][] submaterials, int index) {
        if (index == submaterials.length) {
            return true;
        }

        int h = submaterials[index][0];
        int w = submaterials[index][1];

        for (int i = 0; i <= material.length - h; i++) {
            for (int j = 0; j <= material[0].length - w; j++) {
                if (canPlace(material, i, j, h, w)) {
                    place(material, i, j, h, w, true);
                    if (canPerformCut(material, submaterials, index + 1)) {
                        return true;
                    }
                    place(material, i, j, h, w, false); // Backtrack
                }
            }
        }

        if (h != w) {
            for (int i = 0; i <= material.length - w; i++) {
                for (int j = 0; j <= material[0].length - h; j++) {
                    if (canPlace(material, i, j, w, h)) {
                        place(material, i, j, w, h, true);
                        if (canPerformCut(material, submaterials, index + 1)) {
                            return true;
                        }
                        place(material, i, j, w, h, false);
                    }
                }
            }
        }

        return false;
    }

    public static boolean canPlace(boolean[][] material, int x, int y, int h, int w) {
        for (int i = x; i < x + h; i++) {
            for (int j = y; j < y + w; j++) {
                if (material[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    public static void place(boolean[][] material, int x, int y, int h, int w, boolean value) {
        for (int i = x; i < x + h; i++) {
            for (int j = y; j < y + w; j++) {
                material[i][j] = value;
            }
        }
    }
}
 */