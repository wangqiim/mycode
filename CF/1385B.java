import java.util.*;

public class Solution {
    public static int T;
    public static int n;
    public static int a;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        T = scanner.nextInt();
        Set<Integer> hashSet = new HashSet<>();
        List<Integer> arrayList = new ArrayList<>();
        for (int t = T; t > 0; t--) {
            hashSet.clear();
            arrayList.clear();
            n = scanner.nextInt();
            for (int i = 0; i < 2 * n; i++) {
                a = scanner.nextInt();
                if (!hashSet.contains(a)) {
                    arrayList.add(a);
                    hashSet.add(a);
                }
            }
            for (int i = 0; i < arrayList.size(); i++)
                System.out.print(arrayList.get(i) + " ");
            System.out.println();
        }
        scanner.close();
    }
}