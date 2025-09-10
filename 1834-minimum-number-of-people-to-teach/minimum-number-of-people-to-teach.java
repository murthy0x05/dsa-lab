class Solution {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        Set<Integer> users = new HashSet<>();
        List<Set<Integer>> knows = new ArrayList<>();
        for (int i = 0; i < languages.length; i++) {
            knows.add(new HashSet<>());
        }
        for (int[] friends: friendships) {
            int ui = friends[0], vi = friends[1];
            if (knows.get(ui - 1).size() == 0) {
                for (int lang: languages[ui - 1]) {
                    knows.get(ui - 1).add(lang);
                }
            }
            boolean canTalk = false;
            for (int lang: languages[vi - 1]) {
                if (knows.get(ui - 1).contains(lang)) {
                    canTalk = true;
                    break;
                }
            }

            if (!canTalk) {
                users.add(ui - 1);
                users.add(vi - 1);
            }
        }

        int[] langs = new int[n];
        int maxEle = 0;
        for (Integer user: users) {
            for (int lang: languages[user]) {
                langs[lang - 1]++;
                maxEle = Math.max(maxEle, langs[lang - 1]);
            }
        }

        return users.size() - maxEle;        
    }
}