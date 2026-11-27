import java.util.*;

class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    int k, n;

    public List<List<Integer>> combinationSum3(int k, int n) {
        this.k = k;
        this.n = n;
        dfs(1, 0, new int[k]);
        return ans;
    }

    private void dfs(int start, int idx, int[] path) {

        if (idx == k) {
            if (n == 0) {
                List<Integer> list = new ArrayList<>(k);
                for (int x : path) list.add(x);
                ans.add(list);
            }
            return;
        }
        for (int i = start; i <= 9; i++) {

            if (i > n) break;

            path[idx] = i;
            n -= i;

            dfs(i + 1, idx + 1, path);

            n += i;
        }
    }
}