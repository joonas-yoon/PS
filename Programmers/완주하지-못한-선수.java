import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> table = new HashMap<>();
        // getOrDefault는 없으면 0, 있으면 그 값을 가져오는 메소드
        for (String player : participant) table.put(player, table.getOrDefault(player, 0) + 1);
        // 완주한 명단에 있는 사람은 뺀다.
        for (String player : completion) table.put(player, table.get(player) - 1);

        for (String key : table.keySet()) {
            // 해시 테이블에 남아있는 그 사람이 완주하지 않은 사람
            if (table.get(key) != 0){
                answer = key;
                break;
            }
        }
        return answer;
    }
}